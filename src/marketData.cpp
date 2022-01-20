#include "marketData.h"

void MarketData::get_Connectivity()
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/api/v3/ping";

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

void MarketData::get_Time()
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/api/v3/time";

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

void MarketData::get_Exchange_Info(const std::vector<std::string> &symbols)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        if (symbols.size() == 1)
        {
            query_params.add_new_query("symbol", symbols[0]);
        }
        else
        {
            std::string symbols_lst;
            symbols_lst += "[";
            for (auto i = 0; i < symbols.size(); ++i)
            {
                symbols_lst += "\"" + symbols[i] + "\"";
                if (i != symbols.size() - 1)
                    symbols_lst += ",";
            }
            symbols_lst += "]";
            query_params.add_new_query("symbols", symbols_lst);
        }

        std::string url = endpoint + "/api/v3/exchangeInfo?" + query_params.to_str();
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

void MarketData::get_KlineCandlestick_Data(std::string symbol, std::string interval, uint64_t startTime, uint64_t endTime, uint64_t limit)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("symbol", symbol);
        query_params.add_new_query("interval", interval);

        if (startTime != -1 && endTime != -1)
        {
            query_params.add_new_query("startTime", std::to_string(startTime));
            query_params.add_new_query("endTime", std::to_string(endTime));
        }

        if (limit != -1)
        {
            query_params.add_new_query("limit", std::to_string(limit));
        }
        std::string url = endpoint + "/api/v3/klines?" + query_params.to_str();
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

void MarketData::get_Current_Avg_Price(std::string symbol)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", symbol);
        std::string url = endpoint + "/api/v3/avgPrice?" + query_params.to_str();

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