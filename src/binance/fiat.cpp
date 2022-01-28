#include "fiat.h"

using namespace Binance;

void Fiat::GetDepositWithdrawHistory(FiatHistoryParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("transactionType", params.transactionType);
        query_params.add_new_query("beginTime", params.beginTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("page", params.page);
        query_params.add_new_query("rows", params.rows);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/fiat/orders?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Fiat::GetPaymentHistory(FiatHistoryParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("transactionType", params.transactionType);
        query_params.add_new_query("beginTime", params.beginTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("page", params.page);
        query_params.add_new_query("rows", params.rows);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/fiat/payments?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}