#include "VectorLedger.hpp"
#include <stdexcept>

VectorLedger::VectorLedger(const VectorLedger &other) {
    data = other.data;
}

VectorLedger& VectorLedger::operator=(const AbstractLedger& other) {
    const VectorLedger* p = dynamic_cast<const VectorLedger*>(&other);
    if(!p) return *this; 
    data = p->data;
    return *this;
}

VectorLedger& VectorLedger::operator+=(const Transaction& t) {
    data.push_back(t);
    return *this;
}

VectorLedger& VectorLedger::operator-=(int) {
    if(!data.empty()) data.pop_back();
    return *this;
}

bool VectorLedger::operator==(const AbstractLedger& other) const {
    const VectorLedger* p = dynamic_cast<const VectorLedger*>(&other);
    if(!p) return false; 
    return data == p->data;
}

bool VectorLedger::operator!=(const AbstractLedger& other) const {
    return !((*this) == other);
}

AbstractLedger* VectorLedger::operator+(const AbstractLedger& other) const {
    const VectorLedger* p = dynamic_cast<const VectorLedger*>(&other);
    if(!p) return nullptr;

    VectorLedger* newLedger = new VectorLedger();
    newLedger->data = this->data;
    newLedger->data.insert(newLedger->data.end(), p->data.begin(), p->data.end());
    return newLedger;
}

void VectorLedger::print(std::ostream& os) const {
    os << "--- VectorLedger ---\n";
    for (auto &t : data) {
        os << t.type << " " << t.ticker << " x" << t.quantity << "\n";
    }
}
