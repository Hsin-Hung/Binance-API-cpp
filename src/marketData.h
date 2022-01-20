#ifndef MARKET_DATA_H
#define MARKET_DATA_H
#include <string>
#include <numeric>
#include "binanceAPI.h"


class MarketData : public BinanceAPI
{
public:
    MarketData() : BinanceAPI() {}
    void get_Connectivity();
    void get_Time();
    void init(){};
    void get_Exchange_Info(const std::vector<std::string> &symbols);
    void get_KlineCandlestick_Data(std::string symbol, std::string interval, uint64_t startTime, uint64_t endTime, uint64_t limit);
    void get_Current_Avg_Price(std::string symbol);
};

#endif