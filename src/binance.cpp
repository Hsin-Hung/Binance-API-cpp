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

  std::vector<std::string> streams{"btcusdt@aggTrade", "btcusdt@depth"};

  BinanceWebsocket binweb;
  binweb.init();
  binweb.subscribe_Streams(streams, [](beast::error_code ec, json j) -> bool
                      { std::cout << j.dump() << std::endl; });
  binweb.access_Combined_Streams(streams, [](beast::error_code ec, json j) -> bool
                      { std::cout << j.dump() << std::endl; });
  binweb.run();
  return 0;
}