
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

std::vector<double> fetch() {
    std::vector<double> random;
    for (int i = 0; i < 5; i++) {
        random.push_back(rand() % 5);
    }
    return random;
}

void print(std::vector<double> vals) {
    std::vector<double>::iterator ptr;
    printf("\n");
    for (ptr = vals.begin(); ptr < vals.end(); ptr++)
        printf(" %f ", *ptr);
}

int test_vector() {
    srand(time(NULL));

    std::vector<double> init = {1, 2, 3, 4, 5};
    init = fetch();
    print(init);

    double choice;
    printf("\nWhat value to insert?");

    do {
        std::cin >> choice;
        if(choice != 1) init.push_back(choice);
        printf("\nWhat value to insert?");
    } while (choice != -1);

    return 0;
}
