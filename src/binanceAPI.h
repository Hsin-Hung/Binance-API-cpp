#ifndef BINANCE_API_H
#define BINANCE_API_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <curl/curl.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/bn.h>

enum Action
{
    GET,
    POST,
    PUT,
    DELETE,

};

static const std::vector<std::string> action_str{"GET", "POST", "PUT", "DELETE"};

struct Header
{
    std::string key;
    std::string value;
};

class BinanceAPI
{

protected:
    std::string api_key;
    std::string secret_key;
    std::string endpoint{"https://api.binance.com"};

public:
    class QueryParams
    {

        std::vector<std::string> params;

    public:
        QueryParams(){};
        void add_new_query(std::string key, std::string value)
        {
            params.push_back(key + "=" + value);
        }
        std::string to_str()
        {
            std::string ret;
            for (auto i = 0; i < params.size(); ++i)
            {
                ret += params[i];
                if (i != params.size() - 1)
                    ret += "&";
            }
            return ret;
        }
    };
    BinanceAPI(){};
    void set_api_keys(std::string api_key, std::string secret_key);
    void setup_curl_opt(CURL *curl, std::string url, std::string data, std::vector<Header> headers, Action action);
    virtual void init() = 0;
    virtual ~BinanceAPI() = default;
};
std::string bin2hex(unsigned char *input, unsigned int len);
bool generate_HMAC_SHA256_sig(std::string key, std::string data, std::string &result);
#endif