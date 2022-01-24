#include "spotAccountTrade.h"

void SpotAccountTrade::processOrder(BinanceAPI::QueryParams &query_params, const SpotOrder &order)
{

    query_params.add_new_query("symbol", order.symbol);
    query_params.add_new_query("side", get_OrderSide(order.side));
    query_params.add_new_query("type", get_OrderType(order.type));
    if (order.timeInForce != TimeInForce::NONE)
    {
        query_params.add_new_query("timeInForce", get_TimeInForce(order.timeInForce));
    }
    if (order.quantity != 0)
    {
        query_params.add_new_query("quantity", order.quantity);
    }
    if (order.quoteOrderQty != 0)
    {
        query_params.add_new_query("quoteOrderQty", order.quoteOrderQty);
    }
    if (order.price != 0)
    {
        query_params.add_new_query("price", order.price);
    }
    if (!order.newClientOrderId.empty())
    {
        query_params.add_new_query("newClientOrderId", order.newClientOrderId);
    }
    if (order.stopPrice != 0)
    {
        query_params.add_new_query("stopPrice", order.stopPrice);
    }
    if (order.icebergQty != 0)
    {
        query_params.add_new_query("icebergQty", order.icebergQty);
    }
    if (order.newOrderRespType != OrderResponseType::NONE)
    {
        query_params.add_new_query("newOrderRespType", get_OrderResponseType(order.newOrderRespType));
    }
    if (order.recvWindow != 0)
    {
        query_params.add_new_query("recvWindow", order.recvWindow);
    }
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
        if (order.orderId != 0)
        {
            query_params.add_new_query("orderId", order.orderId);
        }
        if (!order.origClientOrderId.empty())
        {
            query_params.add_new_query("origClientOrderId", order.origClientOrderId);
        }
        if (!order.newClientOrderId.empty())
        {
            query_params.add_new_query("newClientOrderId", order.newClientOrderId);
        }
        if (order.recvWindow != 0)
        {
            query_params.add_new_query("recvWindow", order.recvWindow);
        }
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
        if (order.recvWindow != 0)
        {
            query_params.add_new_query("recvWindow", order.recvWindow);
        }
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

void SpotAccountTrade::queryOrder(QuerySpotOrderParams order, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", order.symbol);
        if (order.orderId != 0)
        {
            query_params.add_new_query("orderId", order.orderId);
        }
        if (!order.origClientOrderId.empty())
        {
            query_params.add_new_query("origClientOrderId", order.origClientOrderId);
        }
        if (order.recvWindow != 0)
        {
            query_params.add_new_query("recvWindow", order.recvWindow);
        }
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
