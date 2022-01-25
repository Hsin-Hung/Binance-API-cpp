#ifndef BINANCE_API_H
#define BINANCE_API_H
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <curl/curl.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/bn.h>
#include "../include/json.hpp"
#include "binanceAPIUtils.h"

using json = nlohmann::json;

struct Header
{
    std::string key;
    std::string value;
};

struct memory
{
    char *response;
    size_t size;
};

static size_t curl_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    size_t realsize = size * nmemb;
    struct memory *mem = (struct memory *)userdata;
    mem->response = ptr;
    mem->size = realsize;
    return realsize;
}

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
            if (!value.empty())
                params.push_back(key + "=" + value);
        }
        void add_new_query(std::string key, uint64_t value)
        {
            if (value != 0)
                add_new_query(key, std::to_string(value));
        }
        void add_new_query(std::string key, double value)
        {
            if (value != 0.0)
                add_new_query(key, std::to_string(value));
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
    void setup_curl_opt(CURL *curl, std::string url, std::string data, std::vector<Header> headers, Action action, struct memory &result);
    void start_curl(CURL *curl);
    virtual void init() = 0;
    virtual ~BinanceAPI() = default;
};
std::string bin2hex(unsigned char *input, unsigned int len);
bool generate_HMAC_SHA256_sig(std::string key, std::string data, std::string &result);
#endif