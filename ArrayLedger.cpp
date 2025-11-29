#include "ArrayLedger.hpp"
#include <stdexcept>

ArrayLedger::ArrayLedger() : size(0) {}

ArrayLedger::ArrayLedger(const ArrayLedger& other) {
    size = other.size;
    for(int i = 0;i<size;i++) arr[i] = other.arr[i];
}

ArrayLedger& ArrayLedger::operator=(const AbstractLedger& other) {
    const ArrayLedger* p=dynamic_cast<const ArrayLedger*>(&other);
    if(!p) return *this;

    size=p->size;
    for(int i = 0;i<size;i++) arr[i]=p->arr[i];
    return *this;
}

ArrayLedger& ArrayLedger::operator+=(const Transaction& t) {
    if(size < MAX) arr[size++] = t;
    return *this;
}

ArrayLedger& ArrayLedger::operator-=(int) {
    if(size > 0) size--;
    return *this;
}

bool ArrayLedger::operator==(const AbstractLedger& other) const {
    const ArrayLedger* p = dynamic_cast<const ArrayLedger*>(&other);
    if(!p) return false;
    if(size != p->size) return false;
    for(int i = 0; i < size; i++)
        if(arr[i]!=p->arr[i]) return false;
    return true;
}

bool ArrayLedger::operator!=(const AbstractLedger& other) const {
    return !((*this)==other);
}

AbstractLedger* ArrayLedger::operator+(const AbstractLedger& other) const {
    const ArrayLedger* p = dynamic_cast<const ArrayLedger*>(&other);
    if(!p) return nullptr;

    ArrayLedger* result = new ArrayLedger();
    for(int i=0;i<size;i++) (*result)+=arr[i];
    for(int i=0;i<p->size;i++) (*result)+=p->arr[i];
    return result;
}

void ArrayLedger::print(std::ostream& os) const {
    os << "--- ArrayLedger ---\n";
    for(int i = 0; i < size; i++) {
        os << arr[i].type << " " << arr[i].ticker << " x" << arr[i].quantity << "\n";
    }
}
