# **Binance API Wrapper (C++)**

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#dependencies">Dependencies</a>
    </li>
    <li>
      <a href="#build">Build</a>
    </li>
    <li>
      <a href="#integration">Integration</a>
    </li>
    <li>
        <a href="#examples">Examples</a>
        <ul>
        <li><a href="#wallet-endpoints">Wallet Endpoints</a></li>
        <li><a href="#market-data-endpoints">Market Data Endpoints</a></li>
        <li><a href="#savings-endpoints">Savings Endpoints</a></li>
        <li><a href="#spot-account-trade">Spot Account Trade</a></li>
        <li><a href="#websocket-streams">Websocket Streams</a></li>
      </ul>
    </li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

## About The Project

This is a wrapper for [Binance API](https://binance-docs.github.io/apidocs/spot/en/#change-log) implemented in cpp for most endpoints.

Implemented API endpoints:

* Wallet Endpoints: `wallet.h`
* Market Data Endpoints: `marketData.h`
* Websocket Market Streams: `binanceWebsocket.h`
* Spot Account/Trade: `spotAccountTrade.h`
* User Data Streams: `userDataStreams.h`
* Savings Endpoints: `savings.h`
* BSwap Endpoints: `bSwap.h`
* Fiat Endpoints: `fiat.h`

The format for each API calls and parameters follows the official Binance API documentation. You can see the parameter's format in its endpoint's corresponding Header and Utils files. All necessary paramters should be provides prior to the API call with the exception of `timestamp`, which will be the system clock time if not provided.

## Dependencies
* Boost
* OpenSSL
* CURL

## Build

```shell
mkdir build; cd build
cmake ..
cmake --build .
./binanceAPI
```

## Integration

add `src/binance` to your project and include the API wrapper

```cpp
#include <binance.h>
```

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
### Spot Account Trade
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

## Contributing

Thank you for considering contributing to this Binance API C++ wrapper! Your contributions are greatly appreciated and will help improve the functionality and reliability of this project.

### How to Contribute
There are two main ways you can contribute:

1. **Add More API Endpoints:** If you notice that the wrapper is missing certain Binance API endpoints, you can contribute by adding support for these endpoints. Simply implement the necessary functions and ensure they adhere to the existing coding style.

2. **Add Test Cases:** Robust test coverage is essential to maintain the reliability and stability of the wrapper. You can contribute by adding test cases that cover different scenarios and edge cases. Ensure that the tests validate the correctness of the implemented functionality and help prevent regressions.

3. **Fix Bugs:** Bugs can sometimes slip through the cracks, and we welcome your help in identifying and fixing them. If you encounter any issues or bugs while using the wrapper, please report them by opening an issue. If you're able to fix the bug, submit a pull request with the necessary changes.

## License

Distributed under Apache-2.0 license. See `LICENSE` for more information.

## Contact

Henry - hsinhungw@gmail.com
