#ifndef SPOT_ACCOUNT_TRADE_H
#define SPOT_ACCOUNT_TRADE_H
#include "binanceAPI.h"
#include "spotAccountTradeUtils.h"


class SpotAccountTrade : public BinanceAPI{

public:
    SpotAccountTrade(){};
    void processOrder(BinanceAPI::QueryParams &query_params, const SpotOrder &order);
    void init(){};
    void testNewOrder(SpotOrderParams order, json &result);
    void newOrder(SpotOrderParams order, json &result);
    void cancelOrder(CancelSpotOrderParams order, json &result);
    void cancelAllOpenOrders(CancelSpotOrderParams order, json &result);
    void queryOrder(QuerySpotOrderParams order, json &result);
};


#endif