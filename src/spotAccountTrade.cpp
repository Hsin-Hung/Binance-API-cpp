#include "spotAccountTrade.h"

void SpotAccountTrade::processOrder(BinanceAPI::QueryParams &query_params, const SpotOrder &order)
{

    query_params.add_new_query("symbol", order.symbol);
    query_params.add_new_query("side", get_OrderSide(order.side));
    query_params.add_new_query("type", get_OrderType(order.type));
    if (order.timeInForce != TimeInForce::NONE)
        query_params.add_new_query("timeInForce", get_TimeInForce(order.timeInForce));

    query_params.add_new_query("quantity", order.quantity);
    query_params.add_new_query("quoteOrderQty", order.quoteOrderQty);
    query_params.add_new_query("price", order.price);
    query_params.add_new_query("newClientOrderId", order.newClientOrderId);
    query_params.add_new_query("stopPrice", order.stopPrice);
    query_params.add_new_query("icebergQty", order.icebergQty);

    if (order.newOrderRespType != OrderResponseType::NONE)
        query_params.add_new_query("newOrderRespType", get_OrderResponseType(order.newOrderRespType));

    query_params.add_new_query("recvWindow", order.recvWindow);
    query_params.add_new_query("timestamp", order.timestamp);
}

void SpotAccountTrade::testNewOrder(SpotOrderParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        processOrder(query_params, order);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/order/test?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::POST, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::newOrder(SpotOrderParams order, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        processOrder(query_params, order);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/order?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::POST, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::cancelOrder(CancelSpotOrderParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", order.symbol);
        query_params.add_new_query("orderId", order.orderId);
        query_params.add_new_query("origClientOrderId", order.origClientOrderId);
        query_params.add_new_query("newClientOrderId", order.newClientOrderId);
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/order?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::DELETE, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::cancelAllOpenOrders(CancelSpotOrderParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", order.symbol);
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/openOrders?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::DELETE, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::queryOrder(QuerySpotOrderParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", order.symbol);
        query_params.add_new_query("orderId", order.orderId);
        query_params.add_new_query("origClientOrderId", order.origClientOrderId);
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/order?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::currentOpenOrders(OpenSpotOrdersParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", order.symbol);
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/openOrders?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::allOrders(AllSpotOrdersParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", order.symbol);
        query_params.add_new_query("orderId", order.orderId);
        query_params.add_new_query("startTime", order.startTime);
        query_params.add_new_query("endTime", order.endTime);
        query_params.add_new_query("limit", order.limit);
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/openOrders?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::newOCO(NewSpotOCOParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", order.symbol);
        query_params.add_new_query("listClientOrderId", order.listClientOrderId);
        query_params.add_new_query("side", get_OrderSide(order.side));
        query_params.add_new_query("quantity", order.quantity);
        query_params.add_new_query("limitClientOrderId", order.limitClientOrderId);
        query_params.add_new_query("price", order.price);
        query_params.add_new_query("limitIcebergQty", order.limitIcebergQty);
        query_params.add_new_query("stopClientOrderId", order.stopClientOrderId);
        query_params.add_new_query("stopPrice", order.stopPrice);
        query_params.add_new_query("stopLimitPrice", order.stopLimitPrice);
        query_params.add_new_query("stopIcebergQty", order.stopIcebergQty);

        if (order.stopLimitTimeInForce != TimeInForce::NONE)
            query_params.add_new_query("stopLimitTimeInForce", get_TimeInForce(order.stopLimitTimeInForce));

        if (order.newOrderRespType != OrderResponseType::NONE)
            query_params.add_new_query("newOrderRespType", get_OrderResponseType(order.newOrderRespType));

        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/order/oco?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::POST, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::cancelOCO(CancelSpotOCOParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", order.symbol);
        query_params.add_new_query("orderListId", order.orderListId);
        query_params.add_new_query("listClientOrderId", order.listClientOrderId);
        query_params.add_new_query("newClientOrderId", order.newClientOrderId);
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/orderList?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::DELETE, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::queryOCO(QuerySpotOCOParams order, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("orderListId", order.orderListId);
        query_params.add_new_query("origClientOrderId", order.origClientOrderId);
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/orderList?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::queryAllOCO(QueryAllSpotOCOParams order, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("fromId", order.fromId);
        query_params.add_new_query("startTime", order.startTime);
        query_params.add_new_query("endTime", order.endTime);
        query_params.add_new_query("limit", order.limit);
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/allOrderList?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::queryOpenOCO(QueryOpenSpotOCOParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/openOrderList?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::accountInfo(SpotAccountInfoParams account, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", account.recvWindow);
        query_params.add_new_query("timestamp", account.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/account?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::accountTradeList(SpotAccountTradeListParams account, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", account.symbol);
        query_params.add_new_query("orderId", account.orderId);
        query_params.add_new_query("startTime", account.startTime);
        query_params.add_new_query("endTime", account.endTime);
        query_params.add_new_query("fromId", account.fromId);
        query_params.add_new_query("limit", account.limit);
        query_params.add_new_query("recvWindow", account.recvWindow);
        query_params.add_new_query("timestamp", account.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/myTrades?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void SpotAccountTrade::queryOrderCount(QuerySpotOrderCountParams order, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", order.recvWindow);
        query_params.add_new_query("timestamp", order.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/api/v3/rateLimit/order?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});
        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}
