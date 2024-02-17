#include "ccs_matrix.h"
#include <iostream>
using namespace std;
CCSMatrix::CCSMatrix(DiagonalMatrix& input) {
    auto matrix = input.get_matrix();
        auto col = matrix.get_head();
        auto row = col->value->get_head();

        while (col)
        {
            row = col->value->get_head();
            while (row)
            {
                if (row->value)
                {
                    A.push_back(row->value);
                    LI.push_back(row->i);
                    ++notNullElements;
                }
                row = row->next;
            }
            col = col->next;
        }

        col = matrix.get_head();
        row = col->value->get_head();

        int currentNotNull = 1;

        while (col)
        {
            row = col->value->get_head();
            LJ.push_back(currentNotNull);
            while (row)
            {
                if (row->value)
                {
                    ++currentNotNull;
                }
                row = row->next;
            }
            col = col->next;
        }
        LJ.push_back(currentNotNull + 1);
}

void CCSMatrix::print() {
    cout << "A\n";
        print_matrix(A);
        cout << "LI\n";
        print_matrix(LI);
        cout << "LJ\n";
        print_matrix(LJ);
}
