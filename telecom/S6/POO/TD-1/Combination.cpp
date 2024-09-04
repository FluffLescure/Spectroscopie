#include "Combination.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Combination::Combination(const int n, const int p) : N(n), P(p) {
    this->combination = (int*)malloc(sizeof(int) * n);
}

Combination::Combination(const Combination& game) : N(game.N), P(game.P) {
    this->combination = (int*)malloc(sizeof(int) * game.N);
    for (int i = 0; i < game.N; i++)
        this->combination[i] = game.combination[i];
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

void Combination::operator=(const Combination& game) {
    free(this->combination);
    this->combination = (int*)malloc(sizeof(int) * game.N);
    for (int i = 0; i < game.N; i++)
        this->combination[i] = game.combination[i];
    this->N = game.N;
    this->P = game.P;
}

void Combination::rand(void) {
    int t[this->P];
    for (int i = 0; i < this->P; i++)
        t[i] = i;
    int k;
    for (int i = 0; i < this->N; i++) {
        k = std::rand() % (this->P - i);
        this->combination[i] = t[k];
        t[k] = t[this->P - i - 1];
    }
}

int* Combination::verify(const Combination& game) const {
    int* result = (int*)malloc(sizeof(int) * 2); // 1st val for correct, 2nd val for misplaced
    Combination test = game;

    for (int k = 0; k < this->N; k++) {
        if (this->combination[k] == test.combination[k]) {
            result[0]++;
            test.combination[k] = this->P;
        }
    }

    for (int k = 0; k < this->N; k++) {
        for (int i = 0; i < this->N; i++) {
            if (test.combination[i] < this->P && test.combination[i] == this->combination[k]) {
                result[1]++;
                test.combination[i] = this->P;
            }
        }
    }
    return result;
}