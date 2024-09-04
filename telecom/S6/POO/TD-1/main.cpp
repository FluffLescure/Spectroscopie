#include "Combination.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL));

    Combination key(4, 8);
    key.rand();
    key.show();
    Combination game(4, 8);
    int* result;
    do {
        game.set();
        result = game.verify(key);
        printf("Correct: %d Misplaced: %d", result[0], result[1]);
    } while (result[0] != 4);

    return 0;
}