#ifndef BSWAP_H
#define BSWAP_H

#include "bSwapUtils.h"
#include "binanceAPI.h"

class BSwap : public BinanceAPI
{

public:
    BSwap() : BinanceAPI(){};
    void ListAllSwapPools(json &result);
    void GetLiquidityInfo(BSwapLiquidityInfoParams params, json &result);
    void AddLiquidity(BSwapAddLiquidityParams params, json &result);
    void RemoveLiquidity(BSwapRemoveLiquidityParams params, json &result);
    void GetLiquidityOpRecord(BSwapLiquidityOpRecordParams params, json &result);
    void RequestQuote(BSwapQuoteParams params, json &result);
    void Swap(BSwapQuoteParams params, json &result);
    void GetSwapHistory(BSwapHistoryParams params, json &result);
    void GetPoolConfig(BSwapPoolParams params, json &result);
    void AddLiquidityPreview(BSwapAddLiquidityPreviewParams params, json &result);
    void RemoveLiquidityPreview(BSwapRemoveLiquidityPreviewParams params, json &result);
    void GetUnclaimedRewardsRecord(BSwapRewardsParams params, json &result);
    void ClaimRewards(BSwapRewardsParams params, json &result);
    void GetClaimedHistory(BSwapClaimedHistoryParams params, json &result);
};

#endif