/*
    Binance API Wrapper for C++

    Copyright (c) 2022 Hsin-Hung <https://github.com/Hsin-Hung>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

            http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#ifndef BINANCE_WEBSOCKET_H
#define BINANCE_WEBSOCKET_H

#include <functional>
#include <memory>
#include <string>

#include "websocketSession.h"
#include "binanceAPI.h"

#define WS_BASE_ENDPOINT "stream.binance.com"
#define WS_PORT "9443"

namespace Binance
{

    class BinanceWebsocket
    {
        net::io_context ioc;
        ssl::context ctx;
        std::shared_ptr<session> ws;
        void connectWebSocket();

    public:
        BinanceWebsocket();

        // run event loop
        void Run();

        // https://binance-docs.github.io/apidocs/spot/en/#live-subscribing-unsubscribing-to-streams
        void SubscribeStreams(std::vector<std::string> streams, stream_callback callback);
        void UnsubscribeStreams(std::vector<std::string> streams, stream_callback callback);
        void ListSubscribtions(stream_callback callback);
        void AccessCombinedStreams(std::vector<std::string> streams, stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#aggregate-trade-streams
        void StreamAggregateTrade(std::string symbol, stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#trade-streams
        void StreamTrade(std::string symbol, stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#kline-candlestick-streams
        void StreamKlineCandlestick(std::string symbol, KCChartIntervals interval, stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#individual-symbol-mini-ticker-stream
        void StreamMiniTicker(std::string symbol, stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#all-market-mini-tickers-stream
        void StreamAllMiniTickers(stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#individual-symbol-ticker-streams
        void StreamSymbolTicker(std::string symbol, stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#all-market-tickers-stream
        void StreamAllMarketTickers(stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#individual-symbol-book-ticker-streams
        void StreamSymbolBookTicker(std::string symbol, stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#partial-book-depth-streams
        void StreamPartialBookDepth(std::string symbol, std::string levels, bool updateSpeed, stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#diff-depth-stream
        void StreamDiffDepth(std::string symbol, bool updateSpeed, stream_callback callback);

        // https://binance-docs.github.io/apidocs/spot/en/#user-data-streams
        void StreamUserData(std::string key, stream_callback callback);
    };
}

#endif