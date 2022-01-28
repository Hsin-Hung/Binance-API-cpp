#ifndef FIAT_H
#define FIAT_H
#include "fiatUtils.h"
#include "binanceAPI.h"

namespace Binance
{

    class Fiat : public BinanceAPI
    {
    public:
        Fiat() : BinanceAPI(){};

        // https://binance-docs.github.io/apidocs/spot/en/#get-fiat-deposit-withdraw-history-user_data
        void GetDepositWithdrawHistory(FiatHistoryParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#get-fiat-payments-history-user_data
        void GetPaymentHistory(FiatHistoryParams params, json &result);
    };
}

#endif