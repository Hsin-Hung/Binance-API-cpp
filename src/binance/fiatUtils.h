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

#ifndef FIAT_UTILS_H
#define FIAT_UTILS_H
#include <string>

typedef struct FiatHistory
{
    std::string transactionType;
    uint64_t beginTime;
    uint64_t endTime;
    uint64_t page;
    uint64_t rows;
    uint64_t recvWindow;
    uint64_t timestamp;
    FiatHistory() : beginTime{0}, endTime{0}, page{0}, rows{0}, recvWindow{0}, timestamp{0} {};

} FiatHistoryParams;

#endif