#include "marketData.h"

void MarketData::TestConnectivity(json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/api/v3/ping";

        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::CheckServerTime(json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/api/v3/time";

        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::ExchangeInfo(MarketExchangeInfoParams params, json &result)
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
        else if(!params.symbols.empty())
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
        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::OrderBook(MarketOrderBookParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("limit", params.limit);

        std::string url = endpoint + "/api/v3/depth?" + query_params.to_str();
        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::RecentTradesList(MarketRecentTradesListParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("limit", params.limit);

        std::string url = endpoint + "/api/v3/trades?" + query_params.to_str();
        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::OldTradeLookup(MarketOldTradeLookupParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("limit", params.limit);
        query_params.add_new_query("fromId", params.fromId);
        std::string url = endpoint + "/api/v3/historicalTrades?" + query_params.to_str();
        std::vector<Header> headers;
        headers.push_back(Header{api_key_header, api_key});
        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::CompAggTradesList(MarketCompAggTradesListParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("fromId", params.fromId);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("limit", params.limit);
        std::string url = endpoint + "/api/v3/aggTrades?" + query_params.to_str();
        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::KlineCandlestickData(MarketKCDataParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("interval", get_KCChartIntervals(params.interval));
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("limit", params.limit);

        std::string url = endpoint + "/api/v3/klines?" + query_params.to_str();
        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::CurrentAvgPrice(MarketSymbolParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        std::string url = endpoint + "/api/v3/avgPrice?" + query_params.to_str();

        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::_24hrTickerPriceChangeStats(MarketSymbolParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        std::string url = endpoint + "/api/v3/ticker/24hr?" + query_params.to_str();

        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::SymbolPrice(MarketSymbolParams params, json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        std::string url = endpoint + "/api/v3/ticker/price?" + query_params.to_str();

        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void MarketData::SymbolOrderBookTicker(MarketSymbolParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        std::string url = endpoint + "/api/v3/ticker/bookTicker?" + query_params.to_str();

        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}
