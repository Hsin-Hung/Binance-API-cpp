#include "binanceWebsocket.h"
#include "binanceAPI.h"
#include <boost/asio.hpp>
#include "../include/json.hpp"

// Report a failure
void fail(beast::error_code ec, char const *what)
{
    std::cerr << what << ": " << ec.message() << "\n";
}

BinanceWebsocket::BinanceWebsocket()
{
}

void BinanceWebsocket::subscribe_Streams(std::vector<std::string> streams, stream_callback callback)
{

    std::string path = "/stream";

    json j;
    j["method"] = "SUBSCRIBE";
    j["params"] = streams;
    j["id"] = 1;

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), j, callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}

void BinanceWebsocket::unsubscribe_Streams(std::vector<std::string> streams, stream_callback callback)
{
    std::string path = "/stream";

    json j;
    j["method"] = "UNSUBSCRIBE";
    j["params"] = streams;
    j["id"] = 2;

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), j, callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}
void BinanceWebsocket::list_Subscribtions(stream_callback callback)
{

    std::string path = "/stream";

    json j;
    j["method"] = "LIST_SUBSCRIPTIONS";
    j["id"] = 3;

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), j, callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}

void BinanceWebsocket::access_Combined_Streams(std::vector<std::string> streams, stream_callback callback)
{
}

void BinanceWebsocket::stream_Aggregate_Trade(std::string symbol, stream_callback callback)
{
    std::string path = "/ws/" + symbol + "@aggTrade";

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}

void BinanceWebsocket::stream_Trade(std::string symbol, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@trade";

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}
void BinanceWebsocket::stream_KlineCandlestick(std::string symbol, std::string interval, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@kline_" + interval;

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}
void BinanceWebsocket::stream_Mini_Ticker(std::string symbol, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@miniTicker";

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}
void BinanceWebsocket::stream_All_Mini_Tickers(stream_callback callback)
{

    std::string path = "/ws/!miniTicker@arr";

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}
void BinanceWebsocket::stream_Symbol_Ticker(std::string symbol, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@ticker";

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}
void BinanceWebsocket::stream_All_Market_Tickers(stream_callback callback)
{

    std::string path = "/ws/!ticker@arr";

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}
void BinanceWebsocket::stream_Symbol_Book_Ticker(std::string symbol, stream_callback callback)
{
    std::string path = "/ws/" + symbol + "@bookTicker";

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}
void BinanceWebsocket::stream_All_Book_Tickers(stream_callback callback)
{

    std::string path = "/ws/!bookTicker";

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}

void BinanceWebsocket::stream_Partial_Book_Depth(std::string symbol, std::string levels, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@depth" + levels;

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}
void BinanceWebsocket::stream_Diff_Depth(std::string symbol, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@depth";

    // The io_context is required for all I/O
    net::io_context ioc;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    std::make_shared<session>(ioc, ctx)->run(WS_BASE_ENDPOINT, WS_PORT, path.c_str(), json(), callback);

    // Run the I/O service. The call will return when
    // the socket is closed.
    ioc.run();
}