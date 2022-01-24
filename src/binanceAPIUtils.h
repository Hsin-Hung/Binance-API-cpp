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

enum class KCChartIntervals{

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

#endif