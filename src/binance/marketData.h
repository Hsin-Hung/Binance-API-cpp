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

    // https://binance-docs.github.io/apidocs/spot/en/#test-connectivity
    void TestConnectivity(json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#check-server-time
    void CheckServerTime(json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#exchange-information
    void ExchangeInfo(MarketExchangeInfoParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#order-book
    void OrderBook(MarketOrderBookParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#recent-trades-list
    void RecentTradesList(MarketRecentTradesListParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#old-trade-lookup-market_data
    void OldTradeLookup(MarketOldTradeLookupParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#compressed-aggregate-trades-list
    void CompAggTradesList(MarketCompAggTradesListParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#kline-candlestick-data
    void KlineCandlestickData(MarketKCDataParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#current-average-price
    void CurrentAvgPrice(MarketSymbolParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#24hr-ticker-price-change-statistics
    void _24hrTickerPriceChangeStats(MarketSymbolParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#symbol-price-ticker
    void SymbolPrice(MarketSymbolParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#symbol-order-book-ticker
    void SymbolOrderBookTicker(MarketSymbolParams params, json &result);
};

#endif