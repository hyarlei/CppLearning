#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

int main() {
    SparseMatrix* matrix1 = readSparseMatrix("matrix1.txt");
    SparseMatrix* matrix2 = readSparseMatrix("matrix2.txt");

    std::cout << "Matrix 1:" << std::endl;
    matrix1->print();

    std::cout << std::endl;

    std::cout << "Matrix 2:" << std::endl;
    matrix2->print();

    std::cout << std::endl;

    SparseMatrix* sumMatrix = matrix1->sum(matrix2);
    std::cout << "Matrix Sum:" << std::endl;
    sumMatrix->print();

    std::cout << std::endl;

    SparseMatrix* productMatrix = matrix1->multiply(matrix2);
    std::cout << "Matrix Product:" << std::endl;
    productMatrix->print();

    delete matrix1;
    delete matrix2;
    delete sumMatrix;
    delete productMatrix;

    return 0;
}