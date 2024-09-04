#ifndef COMBINATION
#define COMBINATION
#include <stdlib.h>

class Combination {
private:
    const int N;
    const int P;
    int *combination;

public:
    Combination() : N(0), P(0), combination(NULL) {}
    Combination(const int N, const int P);
    ~Combination();
    void show(void);
    void set(void);
    int getSize(void) { return N; }
    int getCapacity(void) { return P; }
};

#endif