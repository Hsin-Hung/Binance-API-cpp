#include "spotAccountTrade.h"

using namespace Binance;

void SpotAccountTrade::ProcessOrder(BinanceAPI::QueryParams &query_params, const SpotOrder &order)
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

void SpotAccountTrade::TestNewOrder(SpotOrderParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        ProcessOrder(query_params, params);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/order/test?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::NewOrder(SpotOrderParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        ProcessOrder(query_params, params);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/order?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::CancelOrder(CancelSpotOrderParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("orderId", params.orderId);
        query_params.add_new_query("origClientOrderId", params.origClientOrderId);
        query_params.add_new_query("newClientOrderId", params.newClientOrderId);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/order?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::DELETE, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::CancelAllOpenOrders(CancelSpotOrderParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/openOrders?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::DELETE, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::QueryOrder(QuerySpotOrderParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("orderId", params.orderId);
        query_params.add_new_query("origClientOrderId", params.origClientOrderId);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/order?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::CurrentOpenOrders(OpenSpotOrdersParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/openOrders?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::AllOrders(AllSpotOrdersParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("orderId", params.orderId);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("limit", params.limit);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/allOrders?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::NewOCO(NewSpotOCOParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("listClientOrderId", params.listClientOrderId);
        query_params.add_new_query("side", get_OrderSide(params.side));
        query_params.add_new_query("quantity", params.quantity);
        query_params.add_new_query("limitClientOrderId", params.limitClientOrderId);
        query_params.add_new_query("price", params.price);
        query_params.add_new_query("limitIcebergQty", params.limitIcebergQty);
        query_params.add_new_query("stopClientOrderId", params.stopClientOrderId);
        query_params.add_new_query("stopPrice", params.stopPrice);
        query_params.add_new_query("stopLimitPrice", params.stopLimitPrice);
        query_params.add_new_query("stopIcebergQty", params.stopIcebergQty);

        if (params.stopLimitTimeInForce != TimeInForce::NONE)
            query_params.add_new_query("stopLimitTimeInForce", get_TimeInForce(params.stopLimitTimeInForce));

        if (params.newOrderRespType != OrderResponseType::NONE)
            query_params.add_new_query("newOrderRespType", get_OrderResponseType(params.newOrderRespType));

        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/order/oco?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::CancelOCO(CancelSpotOCOParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("orderListId", params.orderListId);
        query_params.add_new_query("listClientOrderId", params.listClientOrderId);
        query_params.add_new_query("newClientOrderId", params.newClientOrderId);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/orderList?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::DELETE, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::QueryOCO(QuerySpotOCOParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("orderListId", params.orderListId);
        query_params.add_new_query("origClientOrderId", params.origClientOrderId);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/orderList?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::QueryAllOCO(QueryAllSpotOCOParams order, json &result)
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
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/allOrderList?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::QueryOpenOCO(QueryOpenSpotOCOParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/openOrderList?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::AccountInfo(SpotAccountInfoParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/account?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::AccountTradeList(SpotAccountTradeListParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("orderId", params.orderId);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("fromId", params.fromId);
        query_params.add_new_query("limit", params.limit);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/myTrades?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void SpotAccountTrade::QueryOrderCountUsage(QuerySpotOrderCountParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/api/v3/rateLimit/order?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}
