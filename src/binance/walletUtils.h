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

#ifndef WALLET_UTILS_H
#define WALLET_UTILS_H

typedef struct WalletAllCoins
{

    uint64_t timestamp;
    uint64_t recvWindow;

    WalletAllCoins() : timestamp{0}, recvWindow{0} {};

} WalletAllCoinsParams;

typedef struct WalletAccountSnap
{
    std::string type;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletAccountSnap() : startTime{0}, endTime{0}, limit{0}, timestamp{0}, recvWindow{0} {};

} WalletAccountSnapParams;

typedef struct WalletFastWithdrawSwitch
{

    uint64_t recvWindow;
    uint64_t timestamp;

    WalletFastWithdrawSwitch() : timestamp{0}, recvWindow{0} {};

} WalletFastWithdrawSwitchParams;

typedef struct WalletWithdraw
{
    std::string coin;
    std::string withdrawOrderId;
    std::string network;
    std::string address;
    std::string addressTag;
    double amount;
    bool transactionFeeFlag;
    std::string name;
    uint64_t walletType;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletWithdraw() : amount{0}, transactionFeeFlag{false}, walletType{0}, timestamp{0}, recvWindow{0} {};

} WalletWithdrawParams;

typedef struct WalletDepositHistory
{
    std::string coin;
    uint64_t status;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t offset;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletDepositHistory() : status{0}, startTime{0}, endTime{0}, offset{0}, limit{0}, timestamp{0}, recvWindow{0} {};

} WalletDepositHistoryParams;

typedef struct WalletWithdrawHistory
{
    std::string coin;
    std::string withdrawOrderId;
    uint64_t status;
    uint64_t offset;
    uint64_t limit;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletWithdrawHistory() : status{0}, offset{0}, limit{0}, startTime{0}, endTime{0}, timestamp{0}, recvWindow{0} {};

} WalletWithdrawHistoryParams;

typedef struct WalletDepositAddress
{
    std::string coin;
    std::string network;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletDepositAddress() : timestamp{0}, recvWindow{0} {};

} WalletDepositAddressParams;

typedef struct WalletAccountStatus
{
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletAccountStatus() : timestamp{0}, recvWindow{0} {};

} WalletAccountStatusParams;

typedef struct WalletAccountAPITradeStatus
{
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletAccountAPITradeStatus() : timestamp{0}, recvWindow{0} {};

} WalletAccountAPITradeStatusParams;

typedef struct WalletDustLog
{
    uint64_t startTime;
    uint64_t endTime;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletDustLog() : startTime{0}, endTime{0}, timestamp{0}, recvWindow{0} {};

} WalletDustLogParams;

typedef struct WalletDustTransfer
{
    std::vector<std::string> asset;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletDustTransfer() : timestamp{0}, recvWindow{0} {};

} WalletDustTransferParams;

typedef struct WalletAssetDividendRecord
{
    std::string asset;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t limit;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletAssetDividendRecord() : startTime{0}, endTime{0}, timestamp{0}, recvWindow{0} {};

} WalletAssetDividendRecordParams;

typedef struct WalletAssetDetail
{
    std::string asset;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletAssetDetail() : timestamp{0}, recvWindow{0} {};

} WalletAssetDetailParams;

typedef struct WalletTradeFee
{
    std::string symbol;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletTradeFee() : timestamp{0}, recvWindow{0} {};

} WalletTradeFeeParams;

typedef struct WalletUniversalTransfer
{
    OrderType type;
    std::string asset;
    double amount;
    std::string fromSymbol;
    std::string toSymbol;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletUniversalTransfer() : amount{0}, timestamp{0}, recvWindow{0} {};

} WalletUniversalTransferParams;

typedef struct WalletQueryUniversalTransfer
{
    OrderType type;
    uint64_t startTime;
    uint64_t endTime;
    uint64_t current;
    uint64_t size;
    std::string fromSymbol;
    std::string toSymbol;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletQueryUniversalTransfer() : startTime{0}, endTime{0}, current{0}, size{0}, timestamp{0}, recvWindow{0} {};

} WalletQueryUniversalTransferParams;

typedef struct WalletFunding
{
    std::string asset;
    std::string needBtcValuation;
    uint64_t recvWindow;
    uint64_t timestamp;

    WalletFunding() : timestamp{0}, recvWindow{0} {};

} WalletFundingParams;

typedef struct WalletGetAPIKeyPermission
{

    uint64_t recvWindow;
    uint64_t timestamp;

    WalletGetAPIKeyPermission() : timestamp{0}, recvWindow{0} {};

} WalletGetAPIKeyPermissionParams;

#endif