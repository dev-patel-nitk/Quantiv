#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>

struct Transaction {
    std::string type;
    std::string ticker;
    int quantity;

    // Useful for comparisons inside all ledgers
    bool operator==(const Transaction &other) const {
        return type == other.type && ticker == other.ticker && quantity == other.quantity;
    }

    bool operator!=(const Transaction &other) const {
        return !(*this == other);
    }
};

#endif
