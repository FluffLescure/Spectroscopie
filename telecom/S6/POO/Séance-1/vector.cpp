#include "vector.h"

Vector::Vector(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Vector::print()
{
    printf("(%d,%d)", x, y);
}

float Vector::operator*(const Vector &v)
{
    return this->x * v.x + this->y * v.y;
}

Vector::~Vector()
{
    printf("\nFucked a vector");
}