#include "binanceAPI.h"

void BinanceAPI::set_api_keys(std::string api_key, std::string secret_key)
{
    this->api_key = api_key;
    this->secret_key = secret_key;
}

void BinanceAPI::setup_curl_opt(CURL *curl, std::string url, std::string data, std::vector<Header> headers, Action action, struct memory &result)
{

    std::cout << url << std::endl;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
     /* send all data to this function  */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);
 
    /* we pass our 'result' struct to the callback function */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
    struct curl_slist *list = NULL;
    for (auto &h : headers)
    {
        std::string val{h.key + ": " + h.value};
        list = curl_slist_append(list, val.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    if (action == POST || action == PUT)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, action_str[action].c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    }
}

void BinanceAPI::start_curl(CURL *curl){

    CURLcode res;
    res = curl_easy_perform(curl);

    /* Check for errors */
    if (res != CURLE_OK)
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

    /* always cleanup */
    curl_easy_cleanup(curl);

}

std::string bin2hex(unsigned char *input, unsigned int len)
{
    std::string res;
    const char hex[] = "0123456789abcdef";
    for (int i = 0; i < len; ++i)
    {
        res += hex[input[i] >> 4];
        res += hex[input[i] & 0xf];
    }

    return res;
}

bool generate_HMAC_SHA256_sig(std::string key, std::string data, std::string &result)
{
    unsigned char *digest;
    unsigned int resultlen = -1;
    digest = HMAC(EVP_sha256(), key.c_str(), strlen(key.c_str()), (unsigned char *)data.c_str(), strlen(data.c_str()), NULL, &resultlen);
    if (digest)
    {
        result = bin2hex(digest, resultlen);
        return true;
    }
    return false;
}