#ifndef WALLET_H
#define WALLET_H
#include "binanceAPI.h"

class Wallet : public BinanceAPI
{
public:
    Wallet() : BinanceAPI() {}

    void init(){};
    void get_System_Status(json &result);
    void get_All_Coins(uint64_t timestamp, uint64_t recv_window, json &result);
};
#endif