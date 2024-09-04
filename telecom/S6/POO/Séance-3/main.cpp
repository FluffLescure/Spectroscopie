#include <stdio.h>

#include "String.h"

int main() {

    String s1("Hello");
    String s2(" World");

    printf("The %d caracter is %c from the length %d", 2, s1[1], s1.getLength());

    String str = s1 + s2;

    str.print();
    s1.print();
    s2.print();

    return 0;
}