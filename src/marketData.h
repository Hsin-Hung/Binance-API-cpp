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
    void TestConnectivity(json &result);
    void CheckServerTime(json &result);
    void ExchangeInfo(MarketExchangeInfoParams params, json &result);
    void OrderBook(MarketOrderBookParams params, json &result);
    void RecentTradesList(MarketRecentTradesListParams params, json &result);
    void OldTradeLookup(MarketOldTradeLookupParams params, json &result);
    void CompAggTradesList(MarketCompAggTradesListParams params, json &result);
    void KlineCandlestickData(MarketKCDataParams params, json &result);
    void CurrentAvgPrice(MarketSymbolParams params, json &result);
    void _24hrTickerPriceChangeStats(MarketSymbolParams params, json &result);
    void SymbolPrice(MarketSymbolParams params, json &result);
    void SymbolOrderBookTicker(MarketSymbolParams params, json &result);
};

#endif