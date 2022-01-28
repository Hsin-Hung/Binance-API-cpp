#ifndef BINANCE_API_H
#define BINANCE_API_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <sys/time.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>
#include <curl/curl.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/bn.h>
#include <nlohmann/json.hpp>

#include "binanceAPIUtils.h"

#define API_ENDPOINT "https://api.binance.com"
#define API_KEY_HEADER "X-MBX-APIKEY"

using json = nlohmann::json;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

struct Header
{
    std::string key;
    std::string value;
};

struct memory
{
    std::string response;
    size_t size;
};

static size_t curl_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    size_t realsize = size * nmemb;
    struct memory *mem = (struct memory *)userdata;
    mem->response += ptr;
    mem->size += realsize;
    return realsize;
}

namespace Binance
{

    class BinanceAPI
    {

        static std::string bin_to_hex(unsigned char *input, unsigned int len);
        static uint64_t get_current_time();

    protected:
        std::string api_key;
        std::string secret_key;
        const std::string api_key_header;
        const std::string endpoint;

        BinanceAPI() : api_key_header{API_KEY_HEADER}, endpoint{API_ENDPOINT} {};

        // generate HMAC SHA256 signature
        bool generate_HMAC_SHA256_sig(std::string key, std::string data, std::string &result);

        void SetUpCurlOpt(CURL *curl, std::string url, std::string data, std::vector<Header> headers, Action action, struct memory &result);

        // start api call
        void StartCurl(CURL *curl);
        void ParseToJson(std::string data, json &result);

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
                else if (key == "timestamp")
                    add_new_query(key, get_current_time());
            }
            void add_new_query(std::string key, double value)
            {
                if (value != 0.0)
                    add_new_query(key, std::to_string(value));
            }
            void add_new_query(std::string key, bool value)
            {
                if (value)
                    add_new_query(key, "true");
                else
                    add_new_query(key, "false");
            }
            void add_new_query(std::string key, std::vector<std::string> value)
            {
                for (auto &v : value)
                {
                    add_new_query(key, v);
                }
            }
            void add_signature(std::string sig)
            {
                add_new_query("signature", sig);
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

    public:
        void SetApiKeys(std::string api_key, std::string secret_key);
        virtual ~BinanceAPI() = 0;
    };
}
#endif