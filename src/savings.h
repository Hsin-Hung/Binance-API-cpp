#ifndef SAVINGS_H
#define SAVINGS_H
#include "binanceAPI.h"
#include "savingsUtils.h"

class Savings : public BinanceAPI{

    public:
    Savings() : BinanceAPI() {};
    void GetFlexProducts(SavingsFlexProductsParams params, json &result);
    void GetFlexLeftQuota(SavingsFlexLeftQuotaParams params, json &result);
    void PurchaseFlex(SavingsPurchaseFlexParams params, json &result);
    void GetFlexLeftRedeemQuota(SavingsFlexLeftRedeemQuotaParams params, json &result);
    void RedeemFlex(SavingsFlexRedeemParams params, json &result);
    void GetFlexProductPosition(SavingsFlexProductPositionParams params, json &result);
    void GetFixedActivityList(SavingsFixedActivityListParams params, json &result);
    void PurchaseFixedActivity(SavingsPurchaseFixedActivityParams params, json &result);
    void GetFixedActivityPosition(SavingsFixedActivityPositionParams params, json &result);
    void LendingAccount(SavingsLendingAccountParams params, json &result);
    void GetPurchaseRecord(SavingsLendingRecord params, json &result);
    void GetRedeemRecord(SavingsLendingRecord params, json &result);
    void GetInterestHistory(SavingsLendingRecord params, json &result);
    void ChangeFixedActivityPositionToDaily(SavingsChangeFixedActivityPositionToDailyParams params, json &result);
};





#endif