## Description

This is a wrapper for Binance API (https://binance-docs.github.io/apidocs) implemented in cpp for most endpoints.

Implemented API:

* Wallet Endpoints
* Market Data Endpoints
* Websocket Market Streams
* Spot Account/Trade
* User Data Streams
* Savings Endpoints
* BSwap Endpoints
* Fiat Endpoints

The format for each API calls and parameters follows the official Binance API documentation. You can see the parameter's format in its endpoint's corresponding Utils header file and all necessary paramters should be provides prior to the API call with the exception of `timestamp`, which will refer to the system clock if not provided.
## Integration

add `src/binance` to your project and include the API wrapper

```cpp
#include <binance.h>
```

## Build/Run

* `mkdir build; cd build`
* `cmake ..`
* `cmake --build .`
* `./binanceAPI`
  
## Examples

### Wallet Endpoints
```cpp
Binance::Wallet wallet;
json result;

wallet.SetApiKeys("api-key", "secret-key");

// check system status
wallet.SystemStatus(result);
std::cout << result << std::endl;

// get info of coins that are available for deposit and withdraw for user
WalletAllCoinsParams params;
wallet.AllCoins(params, result);
std::cout << result << std::endl;

```
### Market Data Endpoints
```cpp
Binance::MarketData market;
json result;
market.SetApiKeys("api-key", "secret-key");


// test connectivity to the Rest API
market.TestConnectivity(result);
std::cout << result << std::endl;

// current average price for a symbol
MarketSymbolParams params;
params.symbol = "BNBBTC";
market.CurrentAvgPrice(params, result);
std::cout << result << std::endl;

```
### Savings Endpoints
```cpp
Binance::Savings savings;
json result;
savings.SetApiKeys("api-key", "secret-key");

// get flexible products that are featured and subscribable
SavingsFlexProductsParams params;
params.status = SavingsStatus::SUBSCRIBABLE;
params.featured = "TRUE";
savings.GetFlexProducts(params, result);
std::cout << result << std::endl;
```
### Spot Account/Trade
```cpp
Binance::SpotAccountTrade spot;
json result;
spot.SetApiKeys("api-key", "secret-key");

SpotOrderParams params;
params.symbol = "BTCUSDT";
params.side = OrderSide::BUY;
params.type = OrderType::MARKET;
params.quoteOrderQty = 100;
spot.TestNewOrder(params, result);
std::cout << result << std::endl;
```
### Websocket Streams
```cpp
Binance::BinanceWebsocket ws;

// stream individual symbol ticker
ws.StreamSymbolTicker("bnbbtc", [](beast::error_code, json result) -> bool
                     {
                        std::cout << result << std::endl;
                     });

// run event loop
ws.Run();

```
```cpp
Binance::BinanceWebsocket ws;

// access combined streams
std::vector<std::string> streams;
streams.push_back("btcusdt@aggTrade");
streams.push_back("btcusdt@depth");
ws.AccessCombinedStreams(streams, [](beast::error_code, json result) -> bool
                        { 
                            std::cout << result << std::endl; 
                        });

// run event loop
ws.Run();

```
