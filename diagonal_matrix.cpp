#include "diagonal_matrix.h"
#include <iostream>

DiagonalMatrix::DiagonalMatrix(int** input, int size) {
    
    this->size = size;
        

       
        for (int i = 1; i < size; i++)              // подсчет нижних диагоналей и заполнение
        {
            if (input[i][0] != 0)
            {
                ++countDownDiagonal; 
                indexes.push_front(-i);

                auto currentList = matrix.push_front(new ListInt);

                currentList->value->get_head();
                for (size_t o = 0; o < i; o++)
                {
                    currentList->value->push_back(0);
                }
                auto rows = 0;
                for (size_t col = i; col < size; col++)
                {
                    for (size_t row = rows; row < rows + 1; row++)
                    {
                        auto newNode = currentList->value->push_back(input[col][row]);
                        newNode->i = col;
                        newNode->j = row;
                    }
                    ++rows;
                }
            }
        }
        
        indexes.push_back(0);                           // заполнение главной диагонали
        auto diagonalList = matrix.push_back(new ListInt);
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < i + 1; j++)
            {
                auto newNode = diagonalList->value->push_back(input[i][j]);
                newNode->i = i;
                newNode->j = j;
            }
        }

        
        for (int j = 1; j < size; j++)                  // подсчет верхних диагоналей
        {
            if (input[0][j] != 0)
            {
                ++countUpDiagonal;
                indexes.push_back(j);

                auto currentList = matrix.push_back(new ListInt);

                currentList->value->get_head();
                auto columns = 0;
                for (size_t row = j; row < size; row++)
                {
                    for (size_t col = columns; col < columns + 1; col++)
                    {
                        auto newNode = currentList->value->push_back(input[col][row]);
                        newNode->i = col;
                        newNode->j = row;
                    }
                    ++columns;
                }
                for (size_t o = currentList->value->size(); o < size; o++)
                {
                    currentList->value->push_back(0);
                }
            }
        }

        print();
}

DiagonalMatrix* DiagonalMatrix::operator + (DiagonalMatrix& right) {
     auto leftIndex = this->indexes.get_head();
        auto leftMatrix = this->matrix.get_head();
        auto rightIndex = right.indexes.get_head();
        auto rightMatrix = right.matrix.get_head();

        while (leftIndex || rightIndex)
        {     
            if (leftIndex && rightIndex)
            {
                if (leftIndex->value < 0 || rightIndex->value < 0)
                {
                    if (leftIndex->value == rightIndex->value)
                    {
                        auto leftMatrixCol = leftMatrix->value->get_head();
                        auto rightMatrixCol = rightMatrix->value->get_head();

                        while (leftMatrixCol)
                        {
                            leftMatrixCol->value = leftMatrixCol->value + rightMatrixCol->value;
                            leftMatrixCol = leftMatrixCol->next;
                            rightMatrixCol = rightMatrixCol->next;
                        }

                        leftIndex = leftIndex->next;
                        leftMatrix = leftMatrix->next;
                        rightIndex = rightIndex->next;
                        rightMatrix = rightMatrix->next;
                    }
                    else if (leftIndex->value < rightIndex->value)
                    {
                        leftIndex = leftIndex->next;
                        leftMatrix = leftMatrix->next;
                    }
                    else
                    {
                        indexes.push_prev(leftIndex, rightIndex);
                        matrix.push_prev(leftMatrix, rightMatrix);
                        rightIndex = rightIndex->next;
                        rightMatrix = rightMatrix->next;
                    }

                }
                else if (leftIndex->value == 0 && rightIndex->value == 0)
                {
                    auto leftMatrixCol = leftMatrix->value->get_head();
                    auto rightMatrixCol = rightMatrix->value->get_head();

                    while (leftMatrixCol)
                    {
                        leftMatrixCol->value = leftMatrixCol->value + rightMatrixCol->value;
                        leftMatrixCol = leftMatrixCol->next;
                        rightMatrixCol = rightMatrixCol->next;
                    }

                    leftIndex = leftIndex->next;
                    leftMatrix = leftMatrix->next;
                    rightIndex = rightIndex->next;
                    rightMatrix = rightMatrix->next;
                }
                else
                {
                    if (leftIndex->value == rightIndex->value)
                    {
                        auto leftMatrixCol = leftMatrix->value->get_head();
                        auto rightMatrixCol = rightMatrix->value->get_head();

                        while (leftMatrixCol)
                        {
                            leftMatrixCol->value = leftMatrixCol->value + rightMatrixCol->value;
                            leftMatrixCol = leftMatrixCol->next;
                            rightMatrixCol = rightMatrixCol->next;
                        }

                        leftIndex = leftIndex->next;
                        leftMatrix = leftMatrix->next;
                        rightIndex = rightIndex->next;
                        rightMatrix = rightMatrix->next;
                    }
                    else if (leftIndex->value < rightIndex->value)
                    {
                        leftIndex = leftIndex->next;
                        leftMatrix = leftMatrix->next;
                    }
                    else
                    {
                        indexes.push_prev(leftIndex, rightIndex);
                        matrix.push_prev(leftMatrix, rightMatrix);
                        rightIndex = rightIndex->next;
                        rightMatrix = rightMatrix->next;
                    }
                }
            }
            else if (rightIndex)
            {
                indexes.push_back(rightIndex);
                matrix.push_back(rightMatrix);
                rightIndex = rightIndex->next;
                rightMatrix = rightMatrix->next;
            }
        }

        return this;
}

ListList& DiagonalMatrix::get_matrix() {
    return matrix;
}

void DiagonalMatrix::print() {
    print_matrix(indexes);
    print_matrix(matrix);
}
