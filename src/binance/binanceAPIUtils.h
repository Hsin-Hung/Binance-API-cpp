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

#ifndef BINANCE_API_ENUMS_H
#define BINANCE_API_ENUMS_H
#include <string>
#include <vector>
#include <iostream>

enum class OrderSide
{
    BUY,
    SELL
};

std::string get_OrderSide(OrderSide side);

enum class OrderType
{
    LIMIT,
    MARKET,
    STOP_LOSS,
    STOP_LOSS_LIMIT,
    TAKE_PROFIT,
    TAKE_PROFIT_LIMIT,
    LIMIT_MAKER
};

std::string get_OrderType(OrderType type);

enum class TimeInForce
{
    GTC,
    IOC,
    FOK,
    NONE

};

std::string get_TimeInForce(TimeInForce time);

enum class OrderResponseType
{
    ACK,
    RESULT,
    FULL,
    NONE
};

std::string get_OrderResponseType(OrderResponseType type);

enum class KCChartIntervals
{

    _1m,
    _3m,
    _5m,
    _15m,
    _30m,
    _1h,
    _2h,
    _4h,
    _6h,
    _8h,
    _12h,
    _1d,
    _3d,
    _1w,
    _1M

};

std::string get_KCChartIntervals(KCChartIntervals interval);

enum class Action
{
    GET,
    POST,
    PUT,
    DELETE,

};

std::string get_Action(Action action);

enum class SavingsStatus
{
    ALL,
    SUBSCRIBABLE,
    UNSUBSCRIBABLE,
    NONE

};

std::string get_SavingsStatus(SavingsStatus status);

enum class SavingsFlexRedeemType
{
    FAST,
    NORMAL
};

std::string get_SavingsFlexRedeemType(SavingsFlexRedeemType type);

enum class SavingsFixedActivityType
{
    ACTIVITY,
    CUSTOMIZED_FIXED,
};

std::string get_SavingsFixedActivityType(SavingsFixedActivityType type);

enum class SavingsSortBy
{
    START_TIME,
    LOT_SIZE,
    INTEREST_RATE,
    DURATION,
    NONE
};

std::string get_SavingsSortBy(SavingsSortBy by);

enum class SavingsFixedActivityPositionStatus
{
    HOLDING,
    REDEEMED,
    NONE

};

std::string get_SavingsFixedActivityPositionStatus(SavingsFixedActivityPositionStatus status);

enum class SavingsLendingType
{
    DAILY,
    ACTIVITY,
    CUSTOMIZED_FIXED

};

std::string get_SavingsLendingType(SavingsLendingType status);

enum class LiquidityOperation
{
    ADD,
    REMOVE,
    NONE

};

std::string get_LiquidityOperation(LiquidityOperation op);

enum class CancelReplaceMode
{
    STOP_ON_FAILURE,
    ALLOW_FAILURE
};

std::string get_CancelReplaceMode(CancelReplaceMode mode);

enum class SymbolPermissions
{
    SPOT,
    MARGIN,
    LEVERAGED
};

std::string get_SymbolPermissions(SymbolPermissions permissions);

#endif