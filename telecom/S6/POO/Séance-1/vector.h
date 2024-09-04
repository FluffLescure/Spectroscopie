#ifndef VECTOR
#define VECTOR

#include <stdio.h>

class Vector
{
private:
    int x;
    int y;

public:
    Vector(int x, int y);
    void print();
    int Getx() { return x; }
    int Gety() { return y; }
    float operator*(const Vector &v);
    ~Vector();
};

#endif