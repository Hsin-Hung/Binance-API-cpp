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

#ifndef CONVERT_H
#define CONVERT_H

#include "convertUtils.h"
#include "binanceAPI.h"

namespace Binance
{
    class Convert : public BinanceAPI
    {

    public:
        Convert() : BinanceAPI(){};

        // https://binance-docs.github.io/apidocs/spot/en/#list-all-convert-pairs-user_data
        void listAllConvertPairs(ConvertListPairsParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#query-order-quantity-precision-per-asset-user_data
        void queryAssetPrecision(ConvertQueryAssetPrecisionParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#send-quote-request-user_data
        void getQuote(ConvertGetQuoteParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#accept-quote-trade
        void acceptQuote(ConvertAcceptQuoteParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#order-status-user_data
        void orderStatus(ConvertOrderStatusParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#get-convert-trade-history-user_data
        void getConvertTradeHistory(ConvertTradeHistoryParams params, json &result);
    };
}

#endif