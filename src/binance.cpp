#include <stdio.h>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include <string>
#include <thread>
#include <chrono>
#include "wallet.h"
#include "savings.h"
#include "marketData.h"
#include "binanceWebsocket.h"
#include "spotAccountTrade.h"
#include "userDataStreams.h"

int main(void)
{
  std::ifstream infile("apikeys.txt");
  std::string p, s;
  std::getline(infile, p);
  std::getline(infile, s);
  std::time_t result = std::time(nullptr);
  std::asctime(std::localtime(&result));

 
  // Savings svg;
  // uds.set_api_keys(p, s);
  // json j;
  // SavingsFlexProductPositionParams pm;
  // pm.timestamp = result * 1000;
  // pm.asset = "BUSD";
  // svg.GetFlexProductPosition(pm, j);
  // std::cout << j.dump() << std::endl;

  return 0;
}