/*
    Binance API Wrapper for C++
    
    Copyright (c) 2022 Hsin-Hung <https://github.com/Hsin-Hung>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

            http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#ifndef WALLET_H
#define WALLET_H
#include "binanceAPI.h"
#include "walletUtils.h"

namespace Binance
{
    class Wallet : public BinanceAPI
    {
    public:
        Wallet() : BinanceAPI() {}

        // https://binance-docs.github.io/apidocs/spot/en/#system-status-system
        void SystemStatus(json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#all-coins-39-information-user_data
        void AllCoins(WalletAllCoinsParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#daily-account-snapshot-user_data
        void DailyAccountSnapshot(WalletAccountSnapParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#disable-fast-withdraw-switch-user_data
        void DisableFastWithdrawSwitch(WalletFastWithdrawSwitchParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#enable-fast-withdraw-switch-user_data
        void EnableFastWithdrawSwitch(WalletFastWithdrawSwitchParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#withdraw-user_data
        void Withdraw(WalletWithdrawParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#deposit-history-supporting-network-user_data
        void DepositHistory(WalletDepositHistoryParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#withdraw-history-supporting-network-user_data
        void WithdrawHistory(WalletWithdrawHistoryParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#deposit-address-supporting-network-user_data
        void DepositAddress(WalletDepositAddressParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#deposit-address-supporting-network-user_data
        void AccountStatus(WalletAccountStatusParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#deposit-address-supporting-network-user_data
        void AccountAPITradeStatus(WalletAccountAPITradeStatusParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#dustlog-user_data
        void DustLog(WalletDustLogParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#dust-transfer-user_data
        void DustTransfer(WalletDustTransferParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#asset-dividend-record-user_data
        void AssetDividendRecord(WalletAssetDividendRecordParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#asset-detail-user_data
        void AssetDetail(WalletAssetDetailParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#trade-fee-user_data
        void TradeFee(WalletTradeFeeParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#user-universal-transfer-user_data
        void UniversalTransfer(WalletUniversalTransferParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#query-user-universal-transfer-history-user_data
        void QueryUniversalTransfer(WalletQueryUniversalTransferParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#funding-wallet-user_data
        void Funding(WalletFundingParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#user-asset-user_data
        void UserAsset(UserAssetParams params, json &result);

        // https://binance-docs.github.io/apidocs/spot/en/#get-api-key-permission-user_data
        void GetAPIKeyPermission(WalletGetAPIKeyPermissionParams params, json &result);
    };
}
#endif