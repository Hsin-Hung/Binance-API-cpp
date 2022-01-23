#include "wallet.h"
#include <ctime>

void Wallet::get_System_Status(json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/sapi/v1/system/status";

        setup_curl_opt(curl, url, "", std::vector<Header>(), GET, chunk);
        start_curl(curl);
        result = json::parse(chunk.response);
    }
    
}

void Wallet::get_All_Coins(uint64_t timestamp, uint64_t recv_window, json &result)
{
    // std::time_t result = std::time(nullptr);
    // std::asctime(std::localtime(&result));
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", std::to_string(recv_window));
        query_params.add_new_query("timestamp", std::to_string(timestamp));
        std::cout << query_params.to_str() << std::endl;
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/sapi/v1/capital/config/getall?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});

        setup_curl_opt(curl, url, "", headers, GET, chunk);
        start_curl(curl);
        result = json::parse(chunk.response);
    }
}