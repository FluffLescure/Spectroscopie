#ifndef ELEMENT
#define ELEMENT

template <class Class>
class Element {
private:
    Class val;
    Element<Class>* next;

public:
    constexpr Element(Class val = 0, Element<Class>* next = nullptr) : val(val), next(next) {}
    constexpr Element<Class>* getNext(void) const { return next; }
    constexpr Class getVal(void) const { return val; }
    constexpr void setVal(const Class&& val) { this->val = val; }
};

#endif