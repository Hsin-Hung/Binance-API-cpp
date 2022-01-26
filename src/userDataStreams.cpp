#include "userDataStreams.h"


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

