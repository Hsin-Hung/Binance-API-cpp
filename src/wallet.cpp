#include "wallet.h"
#include <ctime>

void Wallet::SystemStatus(json &result)
{
    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        std::string url = endpoint + "/sapi/v1/system/status";

        SetUpCurlOpt(curl, url, "", std::vector<Header>(), Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::AllCoins(WalletAllCoinsParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/capital/config/getall?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::DailyAccountSnapshot(WalletAccountSnapParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("type", params.type);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("limit", params.limit);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/accountSnapshot?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::DisableFastWithdrawSwitch(WalletFastWithdrawSwitchParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/account/disableFastWithdrawSwitch?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::EnableFastWithdrawSwitch(WalletFastWithdrawSwitch params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;

        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::cout << query_params.to_str() << std::endl;
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/account/enableFastWithdrawSwitch?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::Withdraw(WalletWithdraw params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("coin", params.coin);
        query_params.add_new_query("withdrawOrderId", params.withdrawOrderId);
        query_params.add_new_query("network", params.network);
        query_params.add_new_query("address", params.address);
        query_params.add_new_query("addressTag", params.addressTag);
        query_params.add_new_query("amount", params.amount);
        query_params.add_new_query("transactionFeeFlag", params.transactionFeeFlag);
        query_params.add_new_query("name", params.name);
        query_params.add_new_query("walletType", params.walletType);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/capital/withdraw/apply?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::DepositHistory(WalletDepositHistoryParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("coin", params.coin);
        query_params.add_new_query("status", params.status);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("offset", params.offset);
        query_params.add_new_query("limit", params.limit);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/capital/deposit/hisrec?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::WithdrawHistory(WalletWithdrawHistoryParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("coin", params.coin);
        query_params.add_new_query("withdrawOrderId", params.withdrawOrderId);
        query_params.add_new_query("status", params.status);
        query_params.add_new_query("offset", params.offset);
        query_params.add_new_query("limit", params.limit);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);

        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/capital/withdraw/history?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::DepositAddress(WalletDepositAddressParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("coin", params.coin);
        query_params.add_new_query("network", params.network);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/capital/deposit/address?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::AccountStatus(WalletAccountStatus params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        std::cout << query_params.to_str() << std::endl;
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/account/status?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::AccountAPITradeStatus(WalletAccountAPITradeStatusParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/account/apiTradingStatus?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::DustLog(WalletDustLogParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/asset/dribblet?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::DustTransfer(WalletDustTransferParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/asset/dust?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::AssetDividendRecord(WalletAssetDividendRecordParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("limit", params.limit);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/asset/assetDividend?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::AssetDetail(WalletAssetDetailParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/asset/assetDetail?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::TradeFee(WalletTradeFeeParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("symbol", params.symbol);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/asset/tradeFee?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::UniversalTransfer(WalletUniversalTransferParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("type", get_OrderType(params.type));
        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("amount", params.amount);
        query_params.add_new_query("fromSymbol", params.fromSymbol);
        query_params.add_new_query("toSymbol", params.toSymbol);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/asset/transfer?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::QueryUniversalTransfer(WalletQueryUniversalTransferParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("type", get_OrderType(params.type));
        query_params.add_new_query("startTime", params.startTime);
        query_params.add_new_query("endTime", params.endTime);
        query_params.add_new_query("current", params.current);
        query_params.add_new_query("size", params.size);
        query_params.add_new_query("fromSymbol", params.fromSymbol);
        query_params.add_new_query("toSymbol", params.toSymbol);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/asset/transfer?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::Funding(WalletFundingParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("asset", params.asset);
        query_params.add_new_query("needBtcValuation", params.needBtcValuation);
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/asset/get-funding-asset?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::POST, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}

void Wallet::GetAPIKeyPermission(WalletGetAPIKeyPermissionParams params, json &result)
{

    struct memory chunk;

    CURL *curl;
    curl = curl_easy_init();
    if (curl)
    {
        BinanceAPI::QueryParams query_params;
        query_params.add_new_query("recvWindow", params.recvWindow);
        query_params.add_new_query("timestamp", params.timestamp);
        
        std::string sig;
        generate_HMAC_SHA256_sig(secret_key, query_params.to_str(), sig);
        query_params.add_signature(sig);
        std::string url = endpoint + "/sapi/v1/account/apiRestrictions?" + query_params.to_str();
        std::vector<Header> headers;

        headers.push_back(Header{api_key_header, api_key});

        SetUpCurlOpt(curl, url, "", headers, Action::GET, chunk);
        StartCurl(curl);
        ParseToJson(chunk.response, result);
    }
}