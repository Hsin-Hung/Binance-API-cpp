#include "wallet.h"
#include <ctime>

void Wallet::get_System_Status()
{

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/sapi/v1/system/status";

        setup_curl_opt(curl, url, "", std::vector<Header>(), GET);
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
}

void Wallet::get_All_Coins(uint64_t timestamp, uint64_t recv_window)
{
    // std::time_t result = std::time(nullptr);
    // std::asctime(std::localtime(&result));

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", std::to_string(recv_window));
        query_params.add_new_query("timestamp", std::to_string(timestamp));
        std::cout << query_params.to_str() << std::endl;
        std::string result;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), result);
        query_params.add_new_query("signature", result);
        std::string url = endpoint + "/sapi/v1/capital/config/getall?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{"X-MBX-APIKEY", api_key});

        setup_curl_opt(curl, url, "", headers, GET);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
}