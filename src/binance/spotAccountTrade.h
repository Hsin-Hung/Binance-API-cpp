#ifndef SPOT_ACCOUNT_TRADE_H
#define SPOT_ACCOUNT_TRADE_H
#include "binanceAPI.h"
#include "spotAccountTradeUtils.h"

class SpotAccountTrade : public BinanceAPI
{

    void ProcessOrder(BinanceAPI::QueryParams &query_params, const SpotOrder &order);

public:
    SpotAccountTrade() : BinanceAPI(){};

    // https://binance-docs.github.io/apidocs/spot/en/#test-new-order-trade
    void TestNewOrder(SpotOrderParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#new-order-trade
    void NewOrder(SpotOrderParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#cancel-order-trade
    void CancelOrder(CancelSpotOrderParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#cancel-all-open-orders-on-a-symbol-trade
    void CancelAllOpenOrders(CancelSpotOrderParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#query-order-user_data
    void QueryOrder(QuerySpotOrderParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#current-open-orders-user_data
    void CurrentOpenOrders(OpenSpotOrdersParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#all-orders-user_data
    void AllOrders(AllSpotOrdersParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#new-oco-trade
    void NewOCO(NewSpotOCOParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#cancel-oco-trade
    void CancelOCO(CancelSpotOCOParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#query-oco-user_data
    void QueryOCO(QuerySpotOCOParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#query-all-oco-user_data
    void QueryAllOCO(QueryAllSpotOCOParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#query-open-oco-user_data
    void QueryOpenOCO(QueryOpenSpotOCOParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#account-information-user_data
    void AccountInfo(SpotAccountInfoParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#account-trade-list-user_data
    void AccountTradeList(SpotAccountTradeListParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#query-current-order-count-usage-trade
    void QueryOrderCountUsage(QuerySpotOrderCountParams params, json &result);
};

#endif