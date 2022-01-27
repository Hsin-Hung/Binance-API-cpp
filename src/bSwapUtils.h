#ifndef BSWAP_UTILS_H
#define BSWAP_UTILS_H
#include "binanceAPIUtils.h"

typedef struct BSwapLiquidityInfo
{
    uint64_t poolId;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapLiquidityInfo() : poolId{0}, recvWindow{0}, timestamp{0} {};

} BSwapLiquidityInfoParams;

typedef struct BSwapAddLiquidity
{
    uint64_t poolId;
    std::string type;
    std::string asset;
    double quantity;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapAddLiquidity() : poolId{0}, quantity{0}, recvWindow{0}, timestamp{0} {};

} BSwapAddLiquidityParams;

typedef struct BSwapRemoveLiquidity
{
    uint64_t poolId;
    std::string type;
    std::vector<std::string> asset;
    double shareAmount;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapRemoveLiquidity() : poolId{0}, shareAmount{0}, recvWindow{0}, timestamp{0} {};

} BSwapRemoveLiquidityParams;

typedef struct BSwapLiquidityOpRecord
{
    uint64_t operationId;
    uint64_t poolId;
    LiquidityOperation operation;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapLiquidityOpRecord() : operationId{0}, poolId{0}, operation{LiquidityOperation::NONE}, startTime{0}, endTime{0}, limit{0}, recvWindow{0}, timestamp{0} {};

} BSwapLiquidityOpRecordParams;

typedef struct BSwapQuote
{

    std::string quoteAsset;
    std::string baseAsset;
    double quoteQty;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapQuote() : quoteQty{0}, recvWindow{0}, timestamp{0} {};

} BSwapQuoteParams;

typedef struct BSwapHistory
{

    uint64_t swapId;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t status;
    std::string quoteAsset;
    std::string baseAsset;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapHistory() : swapId{0}, startTime{0}, endTime{0}, status{0}, limit{0}, recvWindow{0}, timestamp{0} {};

} BSwapHistoryParams;

typedef struct BSwapPool
{

    uint64_t poolId;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapPool() : poolId{0}, recvWindow{0}, timestamp{0} {};

} BSwapPoolParams;

typedef struct BSwapAddLiquidityPreview
{

    uint64_t poolId;
    std::string type;
    std::string quoteAsset;
    double quoteQty;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapAddLiquidityPreview() : poolId{0}, quoteQty{0}, recvWindow{0}, timestamp{0} {};

} BSwapAddLiquidityPreviewParams;

typedef struct BSwapRemoveLiquidityPreview
{

    uint64_t poolId;
    std::string type;
    std::string quoteAsset;
    double shareAmount;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapRemoveLiquidityPreview() : poolId{0}, shareAmount{0}, recvWindow{0}, timestamp{0} {};

} BSwapRemoveLiquidityPreviewParams;

typedef struct BSwapRewards
{

    uint64_t type;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapRewards() : type{0}, recvWindow{0}, timestamp{0} {};

} BSwapRewardsParams;

typedef struct BSwapClaimedHistory
{

    uint64_t poolId;
    std::string assetRewards;
    uint64_t type;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;

    BSwapClaimedHistory() : type{0}, recvWindow{0}, timestamp{0} {};

} BSwapClaimedHistoryParams;

#endif