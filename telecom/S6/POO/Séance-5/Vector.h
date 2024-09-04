#ifndef VECTOR
#define VECTOR

#include <stdlib.h>

template <class Class>
class Vector {
private:
    Class* vect;
    int length;

public:
    Vector() : vect(NULL), length(0) {}
    Vector(int length, const Class& list = Class());
    Vector(const Vector<Class>& V);
    ~Vector() { free(this->vect); }

    Vector<Class> operator+(const Vector<Class>& list) const;
    void operator=(const Vector<Class>& list);
};

template <class Class>
Vector<Class>::Vector(int length, const Class& list) : length(length < 0 ? 0 : length) {
    this->vect = this->length ? (Class*)malloc(sizeof(Class) * this->length) : NULL;
    for (int i = 0; i < this->length; i++)
        this->vect[i] = list;
}

template <class Class>
Vector<Class>::Vector(const Vector<Class>& V) : length(V.length) {
    this->vect = this->length ? (Class*)malloc(sizeof(Class) * this->length) : NULL;
    for (int i = 0; i < this->length; i++)
        this->vect[i] = V.vect[i];
}

template <class Class>
Vector<Class> Vector<Class>::operator+(const Vector<Class>& list) const {
    Vector<Class> added;
    added.length = this->length + list.length;
    added.vect = (Class*)malloc(sizeof(Class) * added.length);
    for (int i = 0; i < added.length; i++)
        added.vect[i] = i < this->length ? this->vect[i] : list.vect[i - this->length];
    return added;
}

template <class Class>
void Vector<Class>::operator=(const Vector<Class>& list) {
    free(this->vect);
    this->length = list.length;
    this->vect = (Class*)malloc(sizeof(Class) * this->length);
    for (int i = 0; i < this->length; i++)
        this->vect[i] = list.vect[i];
}

#endif
