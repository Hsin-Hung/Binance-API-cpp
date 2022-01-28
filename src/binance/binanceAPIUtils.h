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

#endif