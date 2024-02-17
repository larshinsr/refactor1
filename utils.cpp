#include "utils.h"
#include "list.h"
#include "diagonal_matrix.h"
#include "ccs_matrix.h"
#include <iostream>

using namespace std;

typedef List<int> ListInt;
typedef List<List<int>*> ListList;
bool is_number(std::string str) {
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

void abort_if_not_number(std::string str) {
    if (!is_number(str))
    {
        cout << "Aborted! given input is not number";
        exit(-1);
    }
}

void print_matrix(int** matrix, int size) {
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout << to_string(matrix[i][j]) << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_matrix(ListList& matrix)
{
    auto col = matrix.get_head();
    auto row = col->value->get_head();
    while (col)
    {
        row = col->value->get_head();
        while (row)
        {
            cout << to_string(row->value) << "\t";
            row = row->next;
        }
        cout << "\n";
        col = col->next;
    }
    cout << "\n";
}
void print_matrix(ListInt& matrix)
{
    auto row = matrix.get_head();
    while (row)
    {
        cout << to_string(row->value) << "\t";
        row = row->next;

    }
    cout << "\n";
}
void print_matrix(int** matrix, int sizeCol, int sizeRow)
{
    for (size_t i = 0; i < sizeCol; i++)
    {
        for (size_t j = 0; j < sizeRow; j++)
        {
            cout << to_string(matrix[i][j]) << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}
void print_array(int* arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << to_string(arr[i]) << "\t";
    }
    cout << "\n";
}
void algoritm(int** inputFirst, int sizeFirst, int** inputSecond, int sizeSecond)
{
    //print_matrix(inputFirst, sizeFirst);
    //print_matrix(inputSecond, sizeSecond);
    DiagonalMatrix matrix1(inputFirst, sizeFirst);
    DiagonalMatrix matrix2(inputSecond, sizeSecond);
    matrix1 + matrix2;
    matrix1.print();
    CCSMatrix ccsMatrix(matrix1);
    ccsMatrix.print();

}