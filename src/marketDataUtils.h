#ifndef MARKET_DATA_UTILS_H
#define MARKET_DATA_UTILS_H
#include <string>
#include <vector>
#include "binanceAPIUtils.h"

typedef struct MarketExchangeInfo{

    std::string symbol;
    std::vector<std::string> symbols;

} MarketExchangeInfoParams;

typedef struct MarketKCData{

    std::string symbol;
    KCChartIntervals interval;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;

    MarketKCData():startTime{0}, endTime{0}, limit{0}{};

}MarketKCDataParams;

typedef struct MarketSymbol{

    std::string symbol;

}MarketSymbolParams;

#endif