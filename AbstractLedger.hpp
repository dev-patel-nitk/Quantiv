#ifndef ABSTRACT_LEDGER_HPP
#define ABSTRACT_LEDGER_HPP

#include <iostream>
#include "Transaction.hpp"

class AbstractLedger {
public:
    virtual ~AbstractLedger() {}

    virtual AbstractLedger& operator+=(const Transaction& t) = 0;
    virtual AbstractLedger& operator-=(int dummy) = 0; 
    virtual bool operator==(const AbstractLedger& other) const = 0;
    virtual bool operator!=(const AbstractLedger& other) const = 0;
    virtual AbstractLedger& operator=(const AbstractLedger& other) = 0;
    virtual AbstractLedger* operator+(const AbstractLedger& other) const = 0;
    virtual void print(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const AbstractLedger& ledger) {
    ledger.print(os);
    return os;
}

#endif
