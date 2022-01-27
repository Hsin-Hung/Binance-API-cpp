#ifndef FIAT_UTILS_H
#define FIAT_UTILS_H
#include <string>

typedef struct FiatHistory
{
    std::string transactionType;
    uint64_t beginTime;
    uint64_t endTime;
    uint64_t page;
    uint64_t rows;
    uint64_t recvWindow;
    uint64_t timestamp;
    FiatHistory() : beginTime{0}, endTime{0}, page{0}, rows{0}, recvWindow{0}, timestamp{0} {};

} FiatHistoryParams;

#endif