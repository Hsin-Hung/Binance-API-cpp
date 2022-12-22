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

#include "convert.h"

using namespace Binance;

void Convert::listAllConvertPairs(ConvertListPairsParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("fromAsset", params.fromAsset);
        query_params.add_new_query("toAsset", params.toAsset);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/convert/exchangeInfo?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Convert::queryAssetPrecision(ConvertQueryAssetPrecisionParams params, json &result)
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
        std::string url = endpoint + "/sapi/v1/convert/assetInfo?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Convert::getQuote(ConvertGetQuoteParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("fromAsset", params.fromAsset);
        query_params.add_new_query("toAsset", params.toAsset);
        query_params.add_new_query("fromAmount", params.fromAmount);
        query_params.add_new_query("toAmount", params.toAmount);
        query_params.add_new_query("validTime", get_QuoteValidTime(params.validTime));
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/convert/getQuote?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Convert::acceptQuote(ConvertAcceptQuoteParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("quoteId", params.quoteId);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/convert/acceptQuote?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Convert::orderStatus(ConvertOrderStatusParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("orderId", params.orderId);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/convert/orderStatus?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Convert::getConvertTradeHistory(ConvertTradeHistoryParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("limit", params.limit);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/convert/tradeFlow?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}