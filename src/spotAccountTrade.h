#ifndef SPOT_ACCOUNT_TRADE_H
#define SPOT_ACCOUNT_TRADE_H
#include "binanceAPI.h"
#include "spotAccountTradeUtils.h"


class SpotAccountTrade : public BinanceAPI{

public:
    SpotAccountTrade() : BinanceAPI() {};
    void ProcessOrder(BinanceAPI::QueryParams &query_params, const SpotOrder &order);
    void TestNewOrder(SpotOrderParams order, json &result);
    void NewOrder(SpotOrderParams order, json &result);
    void CancelOrder(CancelSpotOrderParams order, json &result);
    void CancelAllOpenOrders(CancelSpotOrderParams order, json &result);
    void QueryOrder(QuerySpotOrderParams order, json &result);
    void CurrentOpenOrders(OpenSpotOrdersParams order, json &result);
    void AllOrders(AllSpotOrdersParams order, json &result);
    void NewOCO(NewSpotOCOParams order, json &result);
    void CancelOCO(CancelSpotOCOParams order, json &result);
    void QueryOCO(QuerySpotOCOParams order, json &result);
    void QueryAllOCO(QueryAllSpotOCOParams order, json &result);
    void QueryOpenOCO(QueryOpenSpotOCOParams order, json &result);
    void AccountInfo(SpotAccountInfoParams account, json &result);
    void AccountTradeList(SpotAccountTradeListParams account, json &result);
    void QueryOrderCountUsage(QuerySpotOrderCountParams order, json &result);
};


#endif