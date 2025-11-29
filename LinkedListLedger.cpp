#include "LinkedListLedger.hpp"
#include <stdexcept>

LinkedListLedger::LinkedListLedger() : head(nullptr), tail(nullptr) {}

void LinkedListLedger::freeList() {
    Node* cur = head;
    while(cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = tail = nullptr;
}

void LinkedListLedger::copyFrom(const LinkedListLedger& other) {
    Node* cur = other.head;
    while(cur) {
        (*this) += cur->t;
        cur = cur->next;
    }
}

LinkedListLedger::LinkedListLedger(const LinkedListLedger& other) : head(nullptr), tail(nullptr) {
    copyFrom(other);
}

LinkedListLedger::~LinkedListLedger() {
    freeList();
}

LinkedListLedger& LinkedListLedger::operator=(const AbstractLedger& other) {
    const LinkedListLedger* p = dynamic_cast<const LinkedListLedger*>(&other);
    if(!p) return *this;

    freeList();
    copyFrom(*p);
    return *this;
}

LinkedListLedger& LinkedListLedger::operator+=(const Transaction& t) {
    Node* node = new Node(t);
    if(!head) head = tail = node;
    else {
        tail->next = node;
        tail = node;
    }
    return *this;
}

LinkedListLedger& LinkedListLedger::operator-=(int) {
    if(!head) return *this;

    if(head == tail) {
        delete head;
        head = tail = nullptr;
        return *this;
    }

    Node* cur = head;
    while(cur->next != tail) cur = cur->next;
    delete tail;
    tail = cur;
    tail->next = nullptr;
    return *this;
}

bool LinkedListLedger::operator==(const AbstractLedger& other) const {
    const LinkedListLedger* p = dynamic_cast<const LinkedListLedger*>(&other);
    if(!p) return false;

    Node *a = head, *b = p->head;
    while(a && b) {
        if(a->t != b->t) return false;
        a = a->next;
        b = b->next;
    }
    return a == nullptr && b == nullptr;
}

bool LinkedListLedger::operator!=(const AbstractLedger& other) const {
    return !((*this) == other);
}

AbstractLedger* LinkedListLedger::operator+(const AbstractLedger& other) const {
    const LinkedListLedger* p = dynamic_cast<const LinkedListLedger*>(&other);
    if(!p) return nullptr;

    LinkedListLedger* result = new LinkedListLedger();
    Node* cur = head;
    while(cur) { (*result) += cur->t; cur = cur->next; }
    cur = p->head;
    while(cur) { (*result) += cur->t; cur = cur->next; }

    return result;
}

void LinkedListLedger::print(std::ostream& os) const {
    os << "--- LinkedListLedger ---\n";
    Node* cur = head;
    while(cur) {
        os << cur->t.type << " " << cur->t.ticker << " x" << cur->t.quantity << "\n";
        cur = cur->next;
    }
}
