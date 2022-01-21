#include <stdio.h>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include <string>
#include <thread>
#include "wallet.h"
#include "marketData.h"
#include "binanceWebsocket.h"

int main(void)
{
  // std::ifstream infile("apikeys.txt");
  // std::string p, s;
  // std::getline(infile, p);
  // std::getline(infile, s);
  // Wallet wallet;
  // wallet.set_api_keys(p,s);

  // std::time_t result = std::time(nullptr);
  // std::asctime(std::localtime(&result));
  // wallet.get_All_Coins(result * 1000, 5000);
  // MarketData md;
  // md.get_KlineCandlestick_Data("ETHUSDT", "5m", -1, -1, 10 );
  // md.get_Current_Avg_Price("ETHUSDT");

  BinanceWebsocket binweb;

  // binweb.subscribe_Streams({"btcusdt@aggTrade", "btcusdt@depth"}, [](beast::error_code ec, json data) -> bool
  //                          {
  //                                 std::cout << data.dump() << std::endl;
  //                                  return true; });

      std::thread th(&BinanceWebsocket::stream_Trade, binweb, "btcusdt", [](beast::error_code ec, json data) -> bool
                     {
                                      std::cout << data.dump() << std::endl;
                                      return true; });

      binweb.stream_Aggregate_Trade("btcusdt", [](beast::error_code ec, json data) -> bool
                                    {
                                      std::cout << data.dump() << std::endl;
                                      return true; });

      th.join();

  return 0;
}