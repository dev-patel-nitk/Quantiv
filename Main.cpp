#include <iostream>
#include "../include/VectorLedger.hpp"
#include "../include/LinkedListLedger.hpp"
#include "../include/ArrayLedger.hpp"
using namespace std;

int main() {
    Transaction t1{"BUY", "AAPL", 10};
    Transaction t2{"SELL", "GOOG", 5};
    VectorLedger v1;
    v1 += t1;
    v1 += t2;
    LinkedListLedger l1;
    l1 += t1;
    l1 += t2;
    ArrayLedger a1;
    a1 += t2;
    a1 += t1;
    cout << v1;
    cout << l1;
    cout << a1;
    cout << "\nVector == LinkedList? " << (v1 == l1) << "\n";
    AbstractLedger* v2 = v1 + v1;
    cout << "\nConcatenated:\n" << (*v2);

    delete v2;
}
