#ifndef MARKET_DATA_H
#define MARKET_DATA_H
#include <string>
#include <numeric>
#include "binanceAPI.h"
#include "marketDataUtils.h"

class MarketData : public BinanceAPI
{
public:
    MarketData() : BinanceAPI() {}
    void get_Connectivity(json &result);
    void get_Time(json &result);
    void init(){};
    void get_Exchange_Info(MarketExchangeInfoParams params, json &result);
    void get_KlineCandlestick_Data(MarketKCDataParams params, json &result);
    void get_Current_Avg_Price(MarketSymbolParams params, json &result);
    void get_24hr_Ticker_Price_Change_Stats(MarketSymbolParams params, json &result);
    void get_Symbol_Price(MarketSymbolParams params, json &result);
};

#endif