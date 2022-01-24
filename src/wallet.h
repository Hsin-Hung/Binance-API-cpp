#ifndef WALLET_H
#define WALLET_H
#include "binanceAPI.h"
#include "walletUtils.h"

class Wallet : public BinanceAPI
{
public:
    Wallet() : BinanceAPI() {}

    void init(){};
    void SystemStatus(json &result);
    void AllCoins(WalletAllCoinsParams params, json &result);
};
#endif