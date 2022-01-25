#include "wallet.h"
#include <ctime>

void Wallet::SystemStatus(json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/sapi/v1/system/status";

        setup_curl_opt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void Wallet::AllCoins(WalletAllCoinsParams params, json &result)
{
    // std::time_t result = std::time(nullptr);
    // std::asctime(std::localtime(&result));
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("recvWindow", params.recv_window);
        query_params.add_new_query("timestamp", params.timestamp);
        std::cout << query_params.to_str() << std::endl;
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_new_query("signature", sig);
        std::string url = endpoint + "/sapi/v1/capital/config/getall?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});

        setup_curl_opt(curl, url, "", headers, Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}