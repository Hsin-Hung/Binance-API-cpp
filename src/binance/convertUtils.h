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

#ifndef CONVERT_UTILS_H
#define CONVERT_UTILS_H
#include "binanceAPIUtils.h"

typedef struct ConvertListPairs
{
    std::string fromAsset;
    std::string toAsset;

} ConvertListPairsParams;

typedef struct ConvertQueryAssetPrecision
{
    uint64_t recvWindow;
    uint64_t timestamp;

    ConvertQueryAssetPrecision() : recvWindow{0}, timestamp{0} {}

} ConvertQueryAssetPrecisionParams;

typedef struct ConvertGetQuote
{
    std::string fromAsset;
    std::string toAsset;
    double fromAmount;
    double toAmount;
    QuoteValidTime validTime;
    uint64_t recvWindow;
    uint64_t timestamp;

    ConvertGetQuote() : fromAmount{0.0}, toAmount{0.0}, recvWindow{0}, timestamp{0} {}

} ConvertGetQuoteParams;

typedef struct ConvertAcceptQuote
{
    std::string quoteId;
    uint64_t recvWindow;
    uint64_t timestamp;

    ConvertAcceptQuote() : recvWindow{0}, timestamp{0} {}

} ConvertAcceptQuoteParams;

typedef struct ConvertOrderStatus
{
    std::string orderId;

} ConvertOrderStatusParams;

typedef struct ConvertTradeHistory
{
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;

    ConvertTradeHistory() : startTime{0}, endTime{0}, limit{0}, recvWindow{0}, timestamp{0} {}

} ConvertTradeHistoryParams;
#endif