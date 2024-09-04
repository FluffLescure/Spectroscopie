#ifndef COMBINATION
#define COMBINATION
#include <stdlib.h>

class Combination {
private:
    int N;
    int P;
    int* combination;

public:
    Combination() : N(0), P(0) {}
    Combination(const int N, const int P);
    Combination(const Combination& game);
    ~Combination();
    void show(void);
    void set(void);
    int getSize(void) { return N; }
    int getCapacity(void) { return P; }
    int& operator[](int i) const { return this->combination[i]; }
    void operator=(const Combination& game);
    void rand(void);
    int* verify(const Combination& game) const;
};

#endif