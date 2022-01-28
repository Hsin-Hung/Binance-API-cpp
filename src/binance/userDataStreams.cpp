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

#include "userDataStreams.h"

using namespace Binance;

void UserDataStreams::CreateListenKey(json &result){

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {

        std::string url = endpoint + "/api/v3/userDataStream";
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }

}

void UserDataStreams::PingListenKey(UserDataStreamsListenKeyParams params, json &result){

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("listenKey", params.listenKey);
        std::string url = endpoint + "/api/v3/userDataStream?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::PUT, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }

}



void UserDataStreams::CloseListenKey(UserDataStreamsListenKeyParams params, json &result){

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("listenKey", params.listenKey);
        std::string url = endpoint + "/api/v3/userDataStream?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::DELETE, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }

}

