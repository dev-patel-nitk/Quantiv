#ifndef LINKEDLIST_LEDGER_HPP
#define LINKEDLIST_LEDGER_HPP

#include "AbstractLedger.hpp"

class LinkedListLedger : public AbstractLedger {
private:
    struct Node {
        Transaction t;
        Node* next;
        Node(const Transaction& tr) : t(tr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

    void copyFrom(const LinkedListLedger& other);
    void freeList();

public:
    LinkedListLedger();
    LinkedListLedger(const LinkedListLedger& other);
    ~LinkedListLedger();

    LinkedListLedger& operator=(const AbstractLedger& other) override;
    LinkedListLedger& operator+=(const Transaction& t) override;
    LinkedListLedger& operator-=(int dummy) override;
    bool operator==(const AbstractLedger& other) const override;
    bool operator!=(const AbstractLedger& other) const override;
    AbstractLedger* operator+(const AbstractLedger& other) const override;

    void print(std::ostream& os) const override;
};

#endif
