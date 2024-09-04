#include <stdio.h>
#include <vector>

void print(std::vector<double> input) {
    std::vector<double>::iterator ptr;

    for (ptr = input.begin(); ptr < input.end(); ptr++)
        printf(" %f ", *ptr);
}

int main() {
    std::vector<double> val = {1, 2, 3, 4, 5};

    print(val);
    printf("\n%f", val.front());
    printf("\n%f\n", val.back());
    val.push_back(1);
    print(val);
    printf("\n");
    val.pop_back();
    print(val);
    printf("\n");

    val.clear();
    print(val);
    return 0;
}