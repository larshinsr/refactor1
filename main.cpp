#include "ccs_matrix.h"
#include <iostream>
#include <fstream>
#include "utils.h"
#include <string>
using namespace std;

const std::string INPUT_FILENAME = "input.txt";

int main() {
    setlocale(LC_ALL, "ru");

    int choise;
    int** inputMatrix1;
    int** inputMatrix2;

    std::cout << "1 - console, 2 - file\n";
    std::string inputNumber = "";
    std::cin >> choise;
    string maxtrixSizeString;
    int matrixFirstSize = 0;
    int matrixSecondSize = 0;
    string matrixElementString;
    int matrixElement = 0;

    if (choise == 1)                    // Ввод с консоли
    {
        cout << "Enter first matrix size: ";
        cin >> maxtrixSizeString;
        abort_if_not_number(maxtrixSizeString);
        matrixFirstSize = atoi(maxtrixSizeString.c_str());

        inputMatrix1 = new int* [matrixFirstSize];

        cout << "Enter first matrix:\n";

        for (size_t i = 0; i < matrixFirstSize; i++)
        {
            inputMatrix1[i] = new int[matrixFirstSize];
            auto row = inputMatrix1[i];
            for (size_t j = 0; j < matrixFirstSize; j++)
            {
                cin >> matrixElementString;
                abort_if_not_number(matrixElementString);
                matrixElement = atoi(matrixElementString.c_str());
                row[j] = matrixElement;
            }
        }

        cout << "Enter second matrix size: ";
        cin >> maxtrixSizeString;
        abort_if_not_number(maxtrixSizeString);
        matrixSecondSize = atoi(maxtrixSizeString.c_str());

        inputMatrix2 = new int* [matrixFirstSize];

        cout << "Enter second matrix:\n";

        for (size_t i = 0; i < matrixSecondSize; i++)
        {
            inputMatrix2[i] = new int[matrixSecondSize];
            auto row = inputMatrix2[i];
            for (size_t j = 0; j < matrixSecondSize; j++)
            {
                cin >> matrixElementString;
                abort_if_not_number(matrixElementString);
                matrixElement = atoi(matrixElementString.c_str());
                row[j] = matrixElement;
            }
        }
    }
    else if (choise == 2)                // Ввод с файла
    {
        ifstream fin(INPUT_FILENAME);

        if (!fin.is_open())
        {
            cout << "Abort! Unable to open file\n";
            return 0;
        }

        fin >> maxtrixSizeString;
        abort_if_not_number(maxtrixSizeString);
        matrixFirstSize = atoi(maxtrixSizeString.c_str());

        inputMatrix1 = new int* [matrixFirstSize];

        for (size_t i = 0; i < matrixFirstSize; i++)
        {
            inputMatrix1[i] = new int[matrixFirstSize];
            auto row = inputMatrix1[i];
            for (size_t j = 0; j < matrixFirstSize; j++)
            {
                fin >> matrixElementString;
                abort_if_not_number(matrixElementString);
                matrixElement = atoi(matrixElementString.c_str());
                row[j] = matrixElement;
            }
        }

        fin >> maxtrixSizeString;
        abort_if_not_number(maxtrixSizeString);
        matrixSecondSize = atoi(maxtrixSizeString.c_str());

        inputMatrix2 = new int* [matrixFirstSize];

        for (size_t i = 0; i < matrixSecondSize; i++)
        {
            inputMatrix2[i] = new int[matrixSecondSize];
            auto row = inputMatrix2[i];
            for (size_t j = 0; j < matrixSecondSize; j++)
            {
                fin >> matrixElementString;
                abort_if_not_number(matrixElementString);
                matrixElement = atoi(matrixElementString.c_str());
                row[j] = matrixElement;
            }
        }
    }
    else                                // В случае некорректного выбора
    {
        cout << "Alert! Wrong choise given\n";
        return 0;
    }
    algoritm(inputMatrix1, matrixFirstSize, inputMatrix2, matrixSecondSize);

    return 0;

    return 0;
}
