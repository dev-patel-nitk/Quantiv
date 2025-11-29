#ifndef ARRAY_LEDGER_HPP
#define ARRAY_LEDGER_HPP

#include "AbstractLedger.hpp"

class ArrayLedger : public AbstractLedger {
private:
    static const int MAX = 100;
    Transaction arr[MAX];
    int size;

public:
    ArrayLedger();
    ArrayLedger(const ArrayLedger& other);

    ArrayLedger& operator=(const AbstractLedger& other) override;
    ArrayLedger& operator+=(const Transaction& t) override;
    ArrayLedger& operator-=(int dummy) override;
    bool operator==(const AbstractLedger& other) const override;
    bool operator!=(const AbstractLedger& other) const override;
    AbstractLedger* operator+(const AbstractLedger& other) const override;

    void print(std::ostream& os) const override;
};

#endif
