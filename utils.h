#pragma once
#include "list.h"
#include <string>

typedef List<int> ListInt;
typedef List<List<int>*> ListList;
bool is_number(std::string str);
void abort_if_not_number(std::string str);
void print_matrix(int** matrix, int size);
void print_matrix(ListList& matrix);
void print_matrix(ListInt& matrix);
void print_matrix(int** matrix, int sizeCol, int sizeRow);
void print_array(int* arr, int size);
void algoritm(int** inputFirst, int sizeFirst, int** inputSecond, int sizeSecond);
