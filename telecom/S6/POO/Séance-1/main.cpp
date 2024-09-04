#include <stdio.h>
#include "vector.h"
#include <stdlib.h>

int main()
{
    Vector u(1, 2);
    Vector v(3, 4);
    u.print();
    printf("\n");
    v.print();
    printf("\n");
    printf("scalar(u,v) = %f\n", u * v);
    printf("u.x = %d\n", u.Getx());
    printf("u.y = %d\n", u.Gety());

    Vector *ptr = (Vector *)malloc(sizeof(int) * 2);
    ptr[0] = Vector(1, 2);
    ptr[1] = Vector(3, 4);
    ptr[0].print();
    printf("\n");
    ptr[1].print();

    return 0;
}
