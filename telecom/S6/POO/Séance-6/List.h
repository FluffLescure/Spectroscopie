#ifndef LIST
#define LIST

#include "Element.h"

template <class Class>
class List {
private:
    Element<Class>* begin;
    Element<Class>* end;

public:
    constexpr List() : begin(nullptr), end(nullptr) {}
    ~List() { this->removeall(); }
    constexpr bool isempty() { return begin == nullptr; }
    constexpr Element<Class>* getFirst() { return begin; }
    constexpr Element<Class>* getLast() { return end; }
    constexpr void insert(const Class&& val);
    constexpr void append(const Class&& val);
    constexpr void removeFirst();
    constexpr void removeall();
};

template <class Class>
constexpr void List<Class>::insert(const Class&& val) {
    if (this->isempty()) {
        Element<Class> first = new Element<Class>;
        begin = new Element<Class>;
        begin->setVal(val);
        end = begin;
    } else {
        Element<Class>* first = new Element<Class>;
        first->setVal(val);
        first->setNext(begin);
        begin = first;
    }
}

template <class Class>
constexpr void List<Class>::append(const Class&& val) {
    Element<Class>* next = new Element<Class>;
    next->setVal(val);
    end->setNext(next);
    end = end->getNext();
}

template <class Class>
constexpr void List<Class>::removeFirst() {
    Element<Class>* first = begin;
    begin = begin->getNext();
    delete first;
}

template <class Class>
constexpr void List<Class>::removeall() {
    while (!this->isempty())
        this->removeFirst();
}

#endif