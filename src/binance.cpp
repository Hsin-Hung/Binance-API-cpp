#include <stdio.h>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include <string>
#include <thread>
#include <chrono>
#include "wallet.h"
#include "marketData.h"
#include "binanceWebsocket.h"
#include "spotAccountTrade.h"

int main(void)
{
  std::ifstream infile("apikeys.txt");
  std::string p, s;
  std::getline(infile, p);
  std::getline(infile, s);
  std::time_t result = std::time(nullptr);
  std::asctime(std::localtime(&result));
  // Wallet wallet;
  // json j;
  // wallet.set_api_keys(p, s);
  // wallet.get_All_Coins(result * 1000, 5000, j);
  // std::cout << j.dump() << std::endl;

  // MarketData md;
  // json j;
  // md.get_KlineCandlestick_Data("ETHUSDT", "5m", -1, -1, 10, j);
  // std::cout << j.dump() << std::endl;
  // md.get_Current_Avg_Price("ETHUSDT", j);
  // std::cout << j.dump() << std::endl;

  return 0;
}