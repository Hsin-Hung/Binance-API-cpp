#ifndef BINANCE_WEBSOCKET_H
#define BINANCE_WEBSOCKET_H

//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: WebSocket SSL client, asynchronous
//
//------------------------------------------------------------------------------
#include <boost/beast/core.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/beast/websocket/ssl.hpp>
#include <boost/asio/strand.hpp>
#include "../include/json.hpp"
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

#define WS_BASE_ENDPOINT "stream.binance.com"
#define WS_PORT "9443"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
namespace ssl = boost::asio::ssl;       // from <boost/asio/ssl.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

using json = nlohmann::json;
using stream_callback = std::function<bool(beast::error_code, json)>;
//------------------------------------------------------------------------------

// Report a failure
void fail(beast::error_code ec, char const *what);

// Sends a WebSocket message and prints the response
class session : public std::enable_shared_from_this<session>
{
    tcp::resolver resolver_;
    websocket::stream<
        beast::ssl_stream<beast::tcp_stream>>
        ws_;
    beast::flat_buffer buffer_;
    std::string host_;
    std::string path_;
    json req_body_;
    stream_callback callback_;

public:
    // Resolver and socket require an io_context
    explicit session(net::io_context &ioc, ssl::context &ctx)
        : resolver_(net::make_strand(ioc)), ws_(net::make_strand(ioc), ctx)
    {
    }

    // Start the asynchronous operation
    void
    init(
        char const *host,
        char const *port)
    {
        std::cout << "init" << std::endl;
        // Save these for later
        host_ = host;
        // Look up the domain name
        try
        {
            auto const results = resolver_.resolve(host, port);
            auto ep = beast::get_lowest_layer(ws_).connect(results);
            if (!SSL_set_tlsext_host_name(
                    ws_.next_layer().native_handle(),
                    host_.c_str()))
            {
                beast::error_code ec = beast::error_code(static_cast<int>(::ERR_get_error()),
                                                         net::error::get_ssl_category());
                return fail(ec, "connect");
            }
            host_ += ':' + std::to_string(ep.port());
        }
        catch (std::exception const &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }

        // resolver_.async_resolve(
        //     host,
        //     port,
        //     beast::bind_front_handler(
        //         &session::on_resolve,
        //         shared_from_this()));
    }

    bool
    run(
        char const *path,
        json req_body,
        stream_callback callback)
    {
        path_ = path;
        req_body_ = req_body;
        callback_ = callback;

            // Perform the SSL handshake
        ws_.next_layer().async_handshake(
            ssl::stream_base::client,
            beast::bind_front_handler(
                &session::on_ssl_handshake,
                shared_from_this()));
        
    }

    void
    on_resolve(
        beast::error_code ec,
        tcp::resolver::results_type results)
    {
        if (ec)
            return fail(ec, "resolve");

        // Set a timeout on the operation
        // beast::get_lowest_layer(ws_).expires_after(std::chrono::seconds(30));

        // Make the connection on the IP address we get from a lookup

        beast::get_lowest_layer(ws_).async_connect(
            results,
            beast::bind_front_handler(
                &session::on_connect,
                shared_from_this()));
    }

    void
    on_connect(beast::error_code ec, tcp::resolver::results_type::endpoint_type ep)
    {
        if (ec)
            return fail(ec, "connect");

        // Set a timeout on the operation
        // beast::get_lowest_layer(ws_).expires_after(std::chrono::seconds(30));

        // Set SNI Hostname (many hosts need this to handshake successfully)
        if (!SSL_set_tlsext_host_name(
                ws_.next_layer().native_handle(),
                host_.c_str()))
        {
            ec = beast::error_code(static_cast<int>(::ERR_get_error()),
                                   net::error::get_ssl_category());
            return fail(ec, "connect");
        }
        // Update the host_ string. This will provide the value of the
        // Host HTTP header during the WebSocket handshake.
        // See https://tools.ietf.org/html/rfc7230#section-5.4
        host_ += ':' + std::to_string(ep.port());
        std::cout << host_ << std::endl;
        // Perform the SSL handshake
        // ws_.next_layer().async_handshake(
        //     ssl::stream_base::client,
        //     beast::bind_front_handler(
        //         &session::on_ssl_handshake,
        //         shared_from_this()));
        std::cout << "connection done" << std::endl;
    }

    void
    on_ssl_handshake(beast::error_code ec)
    {
        if (ec)
            return fail(ec, "ssl_handshake");

        // Turn off the timeout on the tcp_stream, because
        // the websocket stream has its own timeout system.
        beast::get_lowest_layer(ws_).expires_never();

        // Set suggested timeout settings for the websocket
        ws_.set_option(
            websocket::stream_base::timeout::suggested(
                beast::role_type::client));

        // Set a decorator to change the User-Agent of the handshake
        ws_.set_option(websocket::stream_base::decorator(
            [](websocket::request_type &req)
            {
                req.set(http::field::user_agent,
                        std::string(BOOST_BEAST_VERSION_STRING) +
                            " websocket-client-async-ssl");
            }));

        // Perform the websocket handshake
        ws_.async_handshake(host_, path_,
                            beast::bind_front_handler(
                                &session::on_handshake,
                                shared_from_this()));
    }

    void
    on_handshake(beast::error_code ec)
    {
        if (ec)
            return fail(ec, "handshake");

        // Send the message

        if (!req_body_.empty())
        {
            ws_.async_write(
                net::buffer(req_body_.dump()),
                beast::bind_front_handler(
                    &session::on_write,
                    shared_from_this()));
        }
        else
        {
            ws_.async_read(
                buffer_,
                beast::bind_front_handler(
                    &session::on_read,
                    shared_from_this()));
        }
    }

    void
    on_write(
        beast::error_code ec,
        std::size_t bytes_transferred)
    {
        boost::ignore_unused(bytes_transferred);

        if (ec)
            return fail(ec, "write");

        // Read a message into our buffer
        ws_.async_read(
            buffer_,
            beast::bind_front_handler(
                &session::on_read,
                shared_from_this()));
    }

    void
    on_read(
        beast::error_code ec,
        std::size_t bytes_transferred)
    {
        boost::ignore_unused(bytes_transferred);

        if (ec)
            return fail(ec, "read");

        // Close the WebSocket connection
        // ws_.async_close(websocket::close_code::normal,
        //     beast::bind_front_handler(
        //         &session::on_close,
        //         shared_from_this()));
        std::string data = beast::buffers_to_string(buffer_.data());
        buffer_.consume(bytes_transferred);
        auto j = json::parse(data);

        callback_(ec, j);

        if (j.contains("id") && req_body_.contains("id") && j["id"] == req_body_["id"])
            return;

        // std::cout << beast::make_printable(buffer_.data()) << std::endl;
        ws_.async_read(
            buffer_,
            beast::bind_front_handler(
                &session::on_read,
                shared_from_this()));
    }

    void
    on_close(beast::error_code ec)
    {
        if (ec)
            return fail(ec, "close");

        // If we get here then the connection is closed gracefully

        // The make_printable() function helps print a ConstBufferSequence
        // std::cout << beast::make_printable(buffer_.data()) << std::endl;
    }
};

class BinanceWebsocket
{
    net::io_context ioc;
    ssl::context ctx{ssl::context::tlsv12_client};
    std::shared_ptr<session> ws;

public:
    BinanceWebsocket();
    void init();
    void run();
    void subscribe_Streams(std::vector<std::string> streams, stream_callback callback);
    void unsubscribe_Streams(std::vector<std::string> streams, stream_callback callback);
    void list_Subscribtions(stream_callback callback);
    void access_Combined_Streams(std::vector<std::string> streams, stream_callback callback);
    void stream_Aggregate_Trade(std::string symbol, stream_callback callback);
    void stream_Trade(std::string symbol, stream_callback callback);
    void stream_KlineCandlestick(std::string symbol, std::string interval, stream_callback callback);
    void stream_Mini_Ticker(std::string symbol, stream_callback callback);
    void stream_All_Mini_Tickers(stream_callback callback);
    void stream_Symbol_Ticker(std::string symbol, stream_callback callback);
    void stream_All_Market_Tickers(stream_callback callback);
    void stream_Symbol_Book_Ticker(std::string symbol, stream_callback callback);
    void stream_All_Book_Tickers(stream_callback callback);
    void stream_Partial_Book_Depth(std::string symbol, std::string levels, stream_callback callback);
    void stream_Diff_Depth(std::string symbol, stream_callback callback);
};

#endif