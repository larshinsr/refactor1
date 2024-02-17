#ifndef CCSMATRIX
#define CCSMATRIX
#include "diagonal_matrix.h"

class CCSMatrix {
public:
    CCSMatrix(DiagonalMatrix& input);
    void print();

private:
    ListInt A;
    ListInt LI;
    ListInt LJ;
    int notNullElements;
};

// #include "ccs_matrix.cpp"
#endif