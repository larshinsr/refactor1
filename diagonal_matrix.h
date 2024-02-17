#ifndef DIAGONALMATRIX
#define DIAGONALMATRIX
#include "list.h"
#include "utils.h"

class DiagonalMatrix 
{
public:
    DiagonalMatrix(int** input, int size);
    DiagonalMatrix* operator + (DiagonalMatrix& right);
    ListList& get_matrix();
    void print();

private:
    ListList matrix;
    ListInt indexes;
    int indexesSize;
    int size;
    int countUpDiagonal;
    int countDownDiagonal;
};

#endif