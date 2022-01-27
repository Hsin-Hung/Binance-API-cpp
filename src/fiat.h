#ifndef FIAT_H
#define FIAT_H
#include "fiatUtils.h"
#include "binanceAPI.h"

class Fiat : public BinanceAPI
{
public:
    Fiat() : BinanceAPI(){};
    void GetDepositWithdrawHistory(FiatHistoryParams params, json &result);
    void GetPaymentHistory(FiatHistoryParams params, json &result);
};

#endif