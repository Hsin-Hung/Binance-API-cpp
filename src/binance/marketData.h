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

#ifndef MARKET_DATA_H
#define MARKET_DATA_H
#include <string>
#include <numeric>

#include "binanceAPI.h"
#include "marketDataUtils.h"

namespace Binance
{

    class MarketData : public BinanceAPI
    {
    public:
        MarketData() : BinanceAPI() {}

        // https://binance-docs.github.io/apidocs/spot/en/#test-connectivity
        void TestConnectivity(json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#check-server-time
        void CheckServerTime(json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#exchange-information
        void ExchangeInfo(MarketExchangeInfoParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#order-book
        void OrderBook(MarketOrderBookParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#recent-trades-list
        void RecentTradesList(MarketRecentTradesListParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#old-trade-lookup-market_data
        void OldTradeLookup(MarketOldTradeLookupParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#compressed-aggregate-trades-list
        void CompAggTradesList(MarketCompAggTradesListParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#kline-candlestick-data
        void KlineCandlestickData(MarketKCDataParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#current-average-price
        void CurrentAvgPrice(MarketSymbolParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#24hr-ticker-price-change-statistics
        void _24hrTickerPriceChangeStats(MarketSymbolParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#symbol-price-ticker
        void SymbolPrice(MarketSymbolParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#symbol-order-book-ticker
        void SymbolOrderBookTicker(MarketSymbolParams params, json &result);
    };
}

#endif