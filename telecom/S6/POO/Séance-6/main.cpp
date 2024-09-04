#include "list"

#include <stdio.h>

void concat(std::list<int>& l1, std::list<int>& l2) {
    std::list<int>::iterator ptr;
    for (ptr = l2.begin(); ptr != l2.end(); ptr++) {
        l1.push_back(*ptr);
    }
}

void showList(std::list<int>& l) {
    std::list<int>::iterator ptr;
    for (ptr = l.begin(); ptr != l.end(); ptr++) {
        printf(" %d", *ptr);
    }
}

int main() {
    std::list<int> l1 = {1, 2, 3, 4, 5, 6};
    std::list<int> l2 = {7, 8, 9};

    printf("\n");
    showList(l1);
    printf("\n");
    showList(l2);
    printf("\n");

    concat(l1, l2);
    showList(l1);

    return 0;
}