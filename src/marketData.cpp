#include "marketData.h"

void MarketData::get_Connectivity(json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/api/v3/ping";

        setup_curl_opt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void MarketData::get_Time(json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/api/v3/time";

        setup_curl_opt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void MarketData::get_Exchange_Info(MarketExchangeInfoParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        if (!params.symbol.empty())
        {
            query_params.add_new_query("symbol", params.symbol);
        }
        else
        {
            std::string symbols_lst;
            symbols_lst += "[";
            for (auto i = 0; i < params.symbols.size(); ++i)
            {
                symbols_lst += "\"" + params.symbols[i] + "\"";
                if (i != params.symbols.size() - 1)
                    symbols_lst += ",";
            }
            symbols_lst += "]";
            query_params.add_new_query("symbols", symbols_lst);
        }

        std::string url = endpoint + "/api/v3/exchangeInfo?" + query_params.to_str();
        setup_curl_opt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void MarketData::get_KlineCandlestick_Data(MarketKCDataParams params, json &result)
{
    struct memory chunk;
    
    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("interval", get_KCChartIntervals(params.interval));

        if (params.startTime != 0)
        {
            query_params.add_new_query("startTime", params.startTime);
        }
        if (params.endTime != 0)
        {
            query_params.add_new_query("endTime",params.endTime);
        }
        if (params.limit != 0)
        {
            query_params.add_new_query("limit", std::to_string(params.limit));
        }
        std::string url = endpoint + "/api/v3/klines?" + query_params.to_str();
        setup_curl_opt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void MarketData::get_Current_Avg_Price(MarketSymbolParams params, json &result)
{
    struct memory chunk;
    
    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        std::string url = endpoint + "/api/v3/avgPrice?" + query_params.to_str();

        setup_curl_opt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        start_curl(curl);
        result = json::parse(chunk.response);
    }
}

void MarketData::get_24hr_Ticker_Price_Change_Stats(MarketSymbolParams params, json &result)
{
    struct memory chunk;
    
    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        std::string url = endpoint + "/api/v3/ticker/24hr?" + query_params.to_str();

        setup_curl_opt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

void MarketData::get_Symbol_Price(MarketSymbolParams params, json &result)
{
    struct memory chunk;
    
    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        std::string url = endpoint + "/api/v3/ticker/price?" + query_params.to_str();

        setup_curl_opt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        start_curl(curl);
        if (json::accept(chunk.response))
            result = json::parse(chunk.response);
    }
}

