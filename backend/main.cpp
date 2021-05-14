#include <iostream>
#include "soccar/Data Structures/Matrix.h"

int main() {
    Matrix<int> *matrix = new Matrix<int>(4, 4);
    matrix->show();
    cout << "-------------------" << endl;
    matrix->add(2, 2, 666);
    matrix->show();
    return 0;
}
