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

#include "savings.h"

using namespace Binance;

void Savings::GetFlexProducts(SavingsFlexProductsParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        if (params.status != SavingsStatus::NONE)
            query_params.add_new_query("status", get_SavingsStatus(params.status));
        query_params.add_new_query("featured", params.featured);
        query_params.add_new_query("current", params.current);
        query_params.add_new_query("size", params.size);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/daily/product/list?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::GetFlexLeftQuota(SavingsFlexLeftQuotaParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("productId", params.productId);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::cout << query_params.to_str() << std::endl;
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/daily/userLeftQuota?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::PurchaseFlex(SavingsPurchaseFlexParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("productId", params.productId);
        query_params.add_new_query("amount", params.amount);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/daily/purchase?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::GetFlexLeftRedeemQuota(SavingsFlexLeftRedeemQuotaParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("productId", params.productId);
        query_params.add_new_query("type", get_SavingsFlexRedeemType(params.type));
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/daily/userRedemptionQuota?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::RedeemFlex(SavingsFlexRedeemParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("productId", params.productId);
        query_params.add_new_query("amount", params.amount);
        query_params.add_new_query("type", get_SavingsFlexRedeemType(params.type));
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/daily/redeem?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::GetFlexProductPosition(SavingsFlexProductPositionParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/daily/token/position?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::GetFixedActivityList(SavingsFixedActivityListParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("type", get_SavingsFixedActivityType(params.type));
        if (params.status != SavingsStatus::NONE)
            query_params.add_new_query("status", get_SavingsStatus(params.status));
        query_params.add_new_query("isSortAsc", params.isSortAsc);
        if (params.sortBy != SavingsSortBy::NONE)
            query_params.add_new_query("sortBy", get_SavingsSortBy(params.sortBy));
        query_params.add_new_query("current", params.current);
        query_params.add_new_query("size", params.size);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/project/list?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::PurchaseFixedActivity(SavingsPurchaseFixedActivityParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("projectId", params.projectId);
        query_params.add_new_query("lot", params.lot);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/customizedFixed/purchase?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::GetFixedActivityPosition(SavingsFixedActivityPositionParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("projectId", params.projectId);
        if (params.status != SavingsFixedActivityPositionStatus::NONE)
            query_params.add_new_query("status", get_SavingsFixedActivityPositionStatus(params.status));
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/project/position/list?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::LendingAccount(SavingsLendingAccountParams params, json &result)
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
        std::string url = endpoint + "/sapi/v1/lending/union/account?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::GetPurchaseRecord(SavingsLendingRecordParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("lendingType", get_SavingsLendingType(params.lendingType));
        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("current", params.current);
        query_params.add_new_query("size", params.size);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/union/purchaseRecord?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::GetRedeemRecord(SavingsLendingRecordParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("lendingType", get_SavingsLendingType(params.lendingType));
        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("current", params.current);
        query_params.add_new_query("size", params.size);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/union/redemptionRecord?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::GetInterestHistory(SavingsLendingRecordParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("lendingType", get_SavingsLendingType(params.lendingType));
        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("current", params.current);
        query_params.add_new_query("size", params.size);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/union/interestHistory?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Savings::ChangeFixedActivityPositionToDaily(SavingsChangeFixedActivityPositionToDailyParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("projectId", params.projectId);
        query_params.add_new_query("lot", params.lot);
        query_params.add_new_query("positionId", params.positionId);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/lending/positionChanged?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}