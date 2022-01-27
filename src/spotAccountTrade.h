#ifndef SPOT_ACCOUNT_TRADE_H
#define SPOT_ACCOUNT_TRADE_H
#include "binanceAPI.h"
#include "spotAccountTradeUtils.h"


class SpotAccountTrade : public BinanceAPI{

public:
    SpotAccountTrade() : BinanceAPI() {};
    void ProcessOrder(BinanceAPI::QueryParams &query_params, const SpotOrder &order);
    void TestNewOrder(SpotOrderParams params, json &result);
    void NewOrder(SpotOrderParams params, json &result);
    void CancelOrder(CancelSpotOrderParams params, json &result);
    void CancelAllOpenOrders(CancelSpotOrderParams params, json &result);
    void QueryOrder(QuerySpotOrderParams params, json &result);
    void CurrentOpenOrders(OpenSpotOrdersParams params, json &result);
    void AllOrders(AllSpotOrdersParams params, json &result);
    void NewOCO(NewSpotOCOParams params, json &result);
    void CancelOCO(CancelSpotOCOParams params, json &result);
    void QueryOCO(QuerySpotOCOParams params, json &result);
    void QueryAllOCO(QueryAllSpotOCOParams params, json &result);
    void QueryOpenOCO(QueryOpenSpotOCOParams params, json &result);
    void AccountInfo(SpotAccountInfoParams params, json &result);
    void AccountTradeList(SpotAccountTradeListParams params, json &result);
    void QueryOrderCountUsage(QuerySpotOrderCountParams params, json &result);
};


#endif