#ifndef SPOT_ACCOUNT_TRADE_UTILS_H
#define SPOT_ACCOUNT_TRADE_UTILS_H
#include <string>
#include "binanceAPIUtils.h"

typedef struct SpotOrder
{

    std::string symbol;
    OrderSide side;
    OrderType type;
    TimeInForce timeInForce;
    double quantity;
    double quoteOrderQty;
    double price;
    std::string newClientOrderId;
    double stopPrice;
    double icebergQty;
    OrderResponseType newOrderRespType;
    uint64_t recvWindow;
    uint64_t timestamp;

    SpotOrder() : quantity{0}, quoteOrderQty{0}, price{0}, stopPrice{0}, icebergQty{0}, recvWindow{0}, timestamp{0}
    {

        timeInForce = TimeInForce::NONE;
        newOrderRespType = OrderResponseType::NONE;
    }

} SpotOrderParams;

typedef struct CancelSpotOrder
{

    std::string symbol;
    uint64_t orderId;
    std::string origClientOrderId;
    std::string newClientOrderId;
    uint64_t recvWindow;
    uint64_t timestamp;

    CancelSpotOrder() : orderId{0}, recvWindow{0}, timestamp{0}
    {
    }

} CancelSpotOrderParams;

typedef struct CancelAllSpotOrder
{

    std::string symbol;
    uint64_t recvWindow;
    uint64_t timestamp;

    CancelAllSpotOrder() : recvWindow{0}, timestamp{0}
    {
    }

} CancelAllSpotOrderParams;

typedef struct QuerySpotOrder
{

    std::string symbol;
    uint64_t orderId;
    std::string origClientOrderId;
    uint64_t recvWindow;
    uint64_t timestamp;

    QuerySpotOrder() : orderId{0}, recvWindow{0}, timestamp{0}
    {
    }

}QuerySpotOrderParams;

#endif