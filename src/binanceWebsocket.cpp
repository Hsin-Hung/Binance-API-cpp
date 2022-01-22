#include "binanceWebsocket.h"
#include "binanceAPI.h"
#include <boost/asio.hpp>
#include <mutex>
#include <condition_variable>
#include "../include/json.hpp"

// Report a failure
void fail(beast::error_code ec, char const *what)
{
    std::cerr << what << ": " << ec.message() << "\n";
}

BinanceWebsocket::BinanceWebsocket() : ctx{ssl::context::tlsv12_client}
{
}
void BinanceWebsocket::init()
{

    // net::io_context ioc;

    // The SSL context is required, and holds certificates
    // ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws = std::make_shared<session>(ioc, ctx);
    ws->init(WS_BASE_ENDPOINT, WS_PORT);

    // Run the I/O service. The call will return when
    // the socket is closed.
}

void BinanceWebsocket::run()
{
    ioc.run();
}
void BinanceWebsocket::subscribe_Streams(std::vector<std::string> streams, stream_callback callback)
{
    std::mutex m;
    std::condition_variable cv;
    bool ready = false;

    std::string path = "/stream";

    json j;
    j["method"] = "SUBSCRIBE";
    j["params"] = streams;
    j["id"] = 1;

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), j , callback);

}

void BinanceWebsocket::unsubscribe_Streams(std::vector<std::string> streams, stream_callback callback)
{
    std::string path = "/stream";

    json j;
    j["method"] = "UNSUBSCRIBE";
    j["params"] = streams;
    j["id"] = 2;

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), j, callback);
}
void BinanceWebsocket::list_Subscribtions(stream_callback callback)
{

    std::string path = "/stream";

    json j;
    j["method"] = "LIST_SUBSCRIPTIONS";
    j["id"] = 3;

    // The SSL context is required, and holds certificates
    ssl::context ctx{ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), j, callback);
    
}

void BinanceWebsocket::access_Combined_Streams(std::vector<std::string> streams, stream_callback callback)
{
    std::string path = "/stream?streams=";
    for (auto i = 0; i < streams.size(); ++i)
    {

        path += streams[i];

        if (i != streams.size() - 1)
        {
            path += "/";
        }
    }

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}

void BinanceWebsocket::stream_Aggregate_Trade(std::string symbol, stream_callback callback)
{
    std::string path = "/ws/" + symbol + "@aggTrade";

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}

void BinanceWebsocket::stream_Trade(std::string symbol, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@trade";

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}
void BinanceWebsocket::stream_KlineCandlestick(std::string symbol, std::string interval, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@kline_" + interval;

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}
void BinanceWebsocket::stream_Mini_Ticker(std::string symbol, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@miniTicker";

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}
void BinanceWebsocket::stream_All_Mini_Tickers(stream_callback callback)
{

    std::string path = "/ws/!miniTicker@arr";

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}
void BinanceWebsocket::stream_Symbol_Ticker(std::string symbol, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@ticker";

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}
void BinanceWebsocket::stream_All_Market_Tickers(stream_callback callback)
{

    std::string path = "/ws/!ticker@arr";

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}
void BinanceWebsocket::stream_Symbol_Book_Ticker(std::string symbol, stream_callback callback)
{
    std::string path = "/ws/" + symbol + "@bookTicker";

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}
void BinanceWebsocket::stream_All_Book_Tickers(stream_callback callback)
{

    std::string path = "/ws/!bookTicker";

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}

void BinanceWebsocket::stream_Partial_Book_Depth(std::string symbol, std::string levels, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@depth" + levels;

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}
void BinanceWebsocket::stream_Diff_Depth(std::string symbol, stream_callback callback)
{

    std::string path = "/ws/" + symbol + "@depth";

    // This holds the root certificate used for verification
    // load_root_certificates(ctx);

    // Launch the asynchronous operation
    ws->run(path.c_str(), json(), callback);
}