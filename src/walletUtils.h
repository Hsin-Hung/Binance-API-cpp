#ifndef WALLET_UTILS_H
#define WALLET_UTILS_H


typedef struct WalletAllCoins
{

    uint64_t timestamp;
    uint64_t recv_window;

    WalletAllCoins(): timestamp{0}, recv_window{0}{};

} WalletAllCoinsParams;

#endif