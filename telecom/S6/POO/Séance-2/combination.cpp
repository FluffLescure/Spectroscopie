#include "combination.h"
#include <stdio.h>

Combination::Combination(const int N, const int P) : N(N), P(P) {
    combination = (int*)malloc(N * sizeof(int));
}

Combination::~Combination() {
    free(combination);
}

void Combination::show(void) {
    for (int i = 0; i < N; i++) {
        printf("%d ", combination[i]);
    }
    printf("\n");
}

void Combination::set(void) {
    for (int i = 0; i < N; i++) {
        printf("\nEnter the value of element %d: ", i + 1);
        while (scanf("%d", &combination[i]) != 1 || combination[i] <= 0 || combination[i] > P) {
            printf("Invalid input. Please try again.");
            printf("\nEnter the value of element %d: ", i + 1);
            while (!getchar())
                ;
        }
    }
}
