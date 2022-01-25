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
    void currentOpenOrders(OpenSpotOrdersParams order, json &result);
    void allOrders(AllSpotOrdersParams order, json &result);
    void newOCO(NewSpotOCOParams order, json &result);
    void cancelOCO(CancelSpotOCOParams order, json &result);
    void queryOCO(QuerySpotOCOParams order, json &result);
    void queryAllOCO(QueryAllSpotOCOParams order, json &result);
    void queryOpenOCO(QueryOpenSpotOCOParams order, json &result);
    void accountInfo(SpotAccountInfoParams account, json &result);
    void accountTradeList(SpotAccountTradeListParams account, json &result);
    void queryOrderCount(QuerySpotOrderCountParams order, json &result);
};


#endif