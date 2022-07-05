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

    SpotOrder() : timeInForce{TimeInForce::NONE}, quantity{0}, quoteOrderQty{0}, price{0}, stopPrice{0}, icebergQty{0}, newOrderRespType{OrderResponseType::NONE}, recvWindow{0}, timestamp{0}
    {
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

} QuerySpotOrderParams;

typedef struct CancelReplace
{

    std::string symbol;
    OrderSide side;
    OrderType type;   
    CancelReplaceMode mode;
    TimeInForce timeInForce;
    double quantity;
    double quoteOrderQty;
    double price;    
    std::string cancelNewClientOrderId;
    std::string cancelOrigClientOrderId;
    uint64_t cancelOrderId;
    std::string newClientOrderId;
    double stopPrice;
    uint64_t trailingDelta;
    double icebergQty;
    OrderResponseType newOrderRespType;    
    uint64_t recvWindow;
    uint64_t timestamp;    

    CancelReplace() : quantity{0}, quoteOrderQty{0}, price{0}, cancelOrderId{0}, stopPrice{0}, trailingDelta{0}, icebergQty{0}, recvWindow{0}, timestamp{0}
    {
    }   

} CancelReplaceParams;

typedef struct OpenSpotOrders
{

    std::string symbol;
    uint64_t recvWindow;
    uint64_t timestamp;

    OpenSpotOrders() : recvWindow{0}, timestamp{0}
    {
    }

} OpenSpotOrdersParams;

typedef struct AllSpotOrders
{

    std::string symbol;
    uint64_t orderId;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;

    AllSpotOrders() : orderId{0}, startTime{0}, endTime{0}, limit{0}, recvWindow{0}, timestamp{0}
    {
    }

} AllSpotOrdersParams;

typedef struct NewSpotOCO
{

    std::string symbol;
    std::string listClientOrderId;
    OrderSide side;
    double quantity;
    std::string limitClientOrderId;
    double price;
    double limitIcebergQty;
    std::string stopClientOrderId;
    double stopPrice;
    double stopLimitPrice;
    double stopIcebergQty;
    TimeInForce stopLimitTimeInForce;
    OrderResponseType newOrderRespType;
    uint64_t recvWindow;
    uint64_t timestamp;

    NewSpotOCO() : quantity{0}, price{0}, limitIcebergQty{0}, stopPrice{0}, stopLimitPrice{0}, stopIcebergQty{0},
                   stopLimitTimeInForce{TimeInForce::NONE}, newOrderRespType{OrderResponseType::NONE}, recvWindow{0}, timestamp{0}
    {
    }

} NewSpotOCOParams;

typedef struct CancelSpotOCO
{

    std::string symbol;
    uint64_t orderListId;
    std::string listClientOrderId;
    std::string newClientOrderId;
    uint64_t recvWindow;
    uint64_t timestamp;

    CancelSpotOCO() : orderListId{0}, recvWindow{0}, timestamp{0}
    {
    }

} CancelSpotOCOParams;

typedef struct QuerySpotOCO
{

    uint64_t orderListId;
    std::string origClientOrderId;
    uint64_t recvWindow;
    uint64_t timestamp;

    QuerySpotOCO() : orderListId{0}, recvWindow{0}, timestamp{0}
    {
    }

} QuerySpotOCOParams;

typedef struct QueryAllSpotOCO
{

    uint64_t fromId;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;

    QueryAllSpotOCO() : fromId{0}, startTime{0}, endTime{0}, limit{0}, recvWindow{0}, timestamp{0}
    {
    }

} QueryAllSpotOCOParams;

typedef struct QueryOpenSpotOCO
{
    uint64_t recvWindow;
    uint64_t timestamp;
    QueryOpenSpotOCO() : recvWindow{0}, timestamp{0} {}

} QueryOpenSpotOCOParams;

typedef struct SpotAccountInfo
{
    uint64_t recvWindow;
    uint64_t timestamp;
    SpotAccountInfo() : recvWindow{0}, timestamp{0} {}

} SpotAccountInfoParams;

typedef struct SpotAccountTradeList
{
    std::string symbol;
    uint64_t orderId;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t fromId;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;
    SpotAccountTradeList() : orderId{0}, startTime{0}, endTime{0}, fromId{0}, limit{0}, recvWindow{0}, timestamp{0} {}

} SpotAccountTradeListParams;

typedef struct QuerySpotOrderCount
{
    uint64_t recvWindow;
    uint64_t timestamp;
    QuerySpotOrderCount() : recvWindow{0}, timestamp{0} {}

} QuerySpotOrderCountParams;

#endif