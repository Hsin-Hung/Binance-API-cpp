#ifndef USER_DATA_STREAMS_H
#define USER_DATA_STREAMS_H
#include "binanceAPI.h"
#include "userDataStreamsUtils.h"

namespace Binance
{
    class UserDataStreams : public BinanceAPI
    {

    public:
        UserDataStreams() : BinanceAPI(){};

        // https://binance-docs.github.io/apidocs/spot/en/#listen-key-spot
        void CreateListenKey(json &result);
        void PingListenKey(UserDataStreamsListenKeyParams params, json &result);
        void CloseListenKey(UserDataStreamsListenKeyParams params, json &result);
    };
}
#endif