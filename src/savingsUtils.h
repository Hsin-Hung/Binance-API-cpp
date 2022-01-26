#ifndef SAVINGS_UTILS_H
#define SAVINGS_UTILS_H
#include <string>
#include "binanceAPIUtils.h"

typedef struct SavingsFlexProducts{

    SavingsStatus status;
    std::string featured;
    uint64_t current;
    uint64_t size;
    uint64_t recvWindow;
    uint64_t timestamp;

    SavingsFlexProducts(): status{SavingsStatus::NONE}, current{0}, size{0}, recvWindow{0}, timestamp{0}{};

} SavingsFlexProductsParams;

typedef struct SavingsFlexLeftQuota{

    std::string productId;
    uint64_t recvWindow;
    uint64_t timestamp;

    SavingsFlexLeftQuota(): recvWindow{0}, timestamp{0}{};

} SavingsFlexLeftQuotaParams;

typedef struct SavingsPurchaseFlex{

    std::string productId;
    double amount;
    uint64_t recvWindow;
    uint64_t timestamp;

    SavingsPurchaseFlex(): amount{0}, recvWindow{0}, timestamp{0}{};

} SavingsPurchaseFlexParams;

typedef struct SavingsFlexLeftRedeemQuota{

    std::string productId;
    SavingsFlexRedeemType type;
    uint64_t recvWindow;
    uint64_t timestamp;

    SavingsFlexLeftRedeemQuota(): recvWindow{0}, timestamp{0}{};

} SavingsFlexLeftRedeemQuotaParams;

typedef struct SavingsFlexRedeem{

    std::string productId;
    double amount;
    SavingsFlexRedeemType type;
    uint64_t recvWindow;
    uint64_t timestamp;

     SavingsFlexRedeem(): amount{0}, recvWindow{0}, timestamp{0}{};

}  SavingsFlexRedeemParams;

typedef struct SavingsFlexProductPosition{

    std::string asset;
    uint64_t recvWindow;
    uint64_t timestamp;

     SavingsFlexProductPosition(): recvWindow{0}, timestamp{0}{};

}  SavingsFlexProductPositionParams;

typedef struct SavingsFixedActivityList{

    std::string asset;
    SavingsFixedActivityType type;
    SavingsStatus status;
    bool isSortAsc;
    SavingsSortBy sortBy;
    uint64_t current;
    uint64_t size;
    uint64_t recvWindow;
    uint64_t timestamp;

     SavingsFixedActivityList(): status{SavingsStatus::NONE}, isSortAsc{true}, sortBy{SavingsSortBy::NONE}, current{0}, size{0}, recvWindow{0}, timestamp{0}{};

} SavingsFixedActivityListParams;

typedef struct SavingsPurchaseFixedActivity{

    std::string projectId;
    uint64_t lot;
    uint64_t recvWindow;
    uint64_t timestamp;

     SavingsPurchaseFixedActivity(): lot{0}, recvWindow{0}, timestamp{0}{};

} SavingsPurchaseFixedActivityParams;

typedef struct SavingsFixedActivityPosition{

    std::string asset;
    std::string projectId;
    SavingsFixedActivityPositionStatus status;
    uint64_t recvWindow;
    uint64_t timestamp;

     SavingsFixedActivityPosition(): status{SavingsFixedActivityPositionStatus::NONE}, recvWindow{0}, timestamp{0}{};

} SavingsFixedActivityPositionParams;

typedef struct SavingsLendingAccount{

    uint64_t recvWindow;
    uint64_t timestamp;

     SavingsLendingAccount(): recvWindow{0}, timestamp{0}{};

} SavingsLendingAccountParams;


typedef struct SavingsLendingRecord{

    SavingsLendingType lendingType;
    std::string asset;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t current;
    uint64_t size;
    uint64_t recvWindow;
    uint64_t timestamp;

     SavingsLendingRecord(): startTime{0}, endTime{0}, current{0}, size{0}, recvWindow{0}, timestamp{0}{};

} SavingsLendingRecordParams;

typedef struct SavingsChangeFixedActivityPositionToDaily{

    std::string projectId;
    uint64_t lot;
    uint64_t positionId;
    uint64_t recvWindow;
    uint64_t timestamp;

     SavingsChangeFixedActivityPositionToDaily(): lot{0}, positionId{0}, recvWindow{0}, timestamp{0}{};

} SavingsChangeFixedActivityPositionToDailyParams;

#endif