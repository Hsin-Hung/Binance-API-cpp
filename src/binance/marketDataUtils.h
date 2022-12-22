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

#ifndef MARKET_DATA_UTILS_H
#define MARKET_DATA_UTILS_H
#include <string>
#include <vector>

#include "binanceAPIUtils.h"

typedef struct MarketExchangeInfo
{

    std::string symbol;
    std::vector<std::string> symbols;
    SymbolPermissions permissions;

} MarketExchangeInfoParams;

typedef struct MarketOrderBook
{

    std::string symbol;
    uint64_t limit;

    MarketOrderBook() : limit{0} {};

} MarketOrderBookParams;

typedef struct MarketRecentTradesList
{

    std::string symbol;
    uint64_t limit;

    MarketRecentTradesList() : limit{0} {};

} MarketRecentTradesListParams;

typedef struct MarketOldTradeLookup
{

    std::string symbol;
    uint64_t limit;
    uint64_t fromId;

    MarketOldTradeLookup() : limit{0}, fromId{0} {};

} MarketOldTradeLookupParams;

typedef struct MarketCompAggTradesList
{

    std::string symbol;
    uint64_t fromId;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;

    MarketCompAggTradesList() : fromId{0}, startTime{0}, endTime{0}, limit{0} {};

} MarketCompAggTradesListParams;

typedef struct MarketKCData
{

    std::string symbol;
    KCChartIntervals interval;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;

    MarketKCData() : startTime{0}, endTime{0}, limit{0} {};

} MarketKCDataParams;

typedef struct MarketSymbol
{

    std::string symbol;
    std::string type;

} MarketSymbolParams;

#endif