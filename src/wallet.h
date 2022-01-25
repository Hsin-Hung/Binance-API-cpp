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
    void DailyAccountSnapshot(WalletAccountSnapParams params, json &result);
    void DisableFastWithdrawSwitch(WalletFastWithdrawSwitch params, json &result);
    void EnableFastWithdrawSwitch(WalletFastWithdrawSwitch params, json &result);
    void Withdraw(WalletWithdraw params, json &result);
    void DepositHistory(WalletDepositHistoryParams params, json &result);
    void WithdrawHistory(WalletWithdrawHistoryParams params, json &result);
    void DepositAddress(WalletDepositAddressParams params, json &result);
    void AccountStatus(WalletAccountStatus params, json &result);
    void AccountAPITradeStatus(WalletAccountAPITradeStatusParams params, json &result);
    void DustLog(WalletDustLogParams params, json &result);
    void DustTransfer(WalletDustTransferParams params, json &result);
    void AssetDividendRecord(WalletAssetDividendRecordParams params, json &result);
    void AssetDetail(WalletAssetDetailParams params, json &result);
    void TradeFee(WalletTradeFeeParams params, json &result);
    void UniversalTransfer(WalletUniversalTransferParams params, json &result);
    void QueryUniversalTransfer(WalletQueryUniversalTransferParams params, json &result);
    void Funding(WalletFundingParams params, json &result);
    void GetAPIKeyPermission(WalletGetAPIKeyPermissionParams params, json &result);
};
#endif