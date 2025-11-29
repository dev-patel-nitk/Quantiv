#ifndef VECTOR_LEDGER_HPP
#define VECTOR_LEDGER_HPP

#include <vector>
#include "AbstractLedger.hpp"

class VectorLedger : public AbstractLedger {
private:
    std::vector<Transaction> data;

public:
    VectorLedger() = default;
    VectorLedger(const VectorLedger& other);

    VectorLedger& operator=(const AbstractLedger& other) override;

    // Operators
    VectorLedger& operator+=(const Transaction& t) override;
    VectorLedger& operator-=(int dummy) override;
    bool operator==(const AbstractLedger& other) const override;
    bool operator!=(const AbstractLedger& other) const override;
    AbstractLedger* operator+(const AbstractLedger& other) const override;

    void print(std::ostream& os) const override;
};

#endif
