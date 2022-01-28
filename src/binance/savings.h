#ifndef SAVINGS_H
#define SAVINGS_H
#include "binanceAPI.h"
#include "savingsUtils.h"

class Savings : public BinanceAPI
{

public:
    Savings() : BinanceAPI(){};

    // https://binance-docs.github.io/apidocs/spot/en/#get-flexible-product-list-user_data
    void GetFlexProducts(SavingsFlexProductsParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#get-left-daily-purchase-quota-of-flexible-product-user_data
    void GetFlexLeftQuota(SavingsFlexLeftQuotaParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#purchase-flexible-product-user_data
    void PurchaseFlex(SavingsPurchaseFlexParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#get-left-daily-redemption-quota-of-flexible-product-user_data
    void GetFlexLeftRedeemQuota(SavingsFlexLeftRedeemQuotaParams params, json &result);

    //  https://binance-docs.github.io/apidocs/spot/en/#redeem-flexible-product-user_data
    void RedeemFlex(SavingsFlexRedeemParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#get-flexible-product-position-user_data
    void GetFlexProductPosition(SavingsFlexProductPositionParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#get-fixed-and-activity-project-list-user_data
    void GetFixedActivityList(SavingsFixedActivityListParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#purchase-fixed-activity-project-user_data
    void PurchaseFixedActivity(SavingsPurchaseFixedActivityParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#get-fixed-activity-project-position-user_data
    void GetFixedActivityPosition(SavingsFixedActivityPositionParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#lending-account-user_data
    void LendingAccount(SavingsLendingAccountParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#get-purchase-record-user_data
    void GetPurchaseRecord(SavingsLendingRecordParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#get-redemption-record-user_data
    void GetRedeemRecord(SavingsLendingRecordParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#get-interest-history-user_data-2
    void GetInterestHistory(SavingsLendingRecordParams params, json &result);

    // https://binance-docs.github.io/apidocs/spot/en/#change-fixed-activity-position-to-daily-position-user_data
    void ChangeFixedActivityPositionToDaily(SavingsChangeFixedActivityPositionToDailyParams params, json &result);
};

#endif