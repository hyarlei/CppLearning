#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

struct Node {
    Node* right;
    Node* down;
    int row;
    int column;
    double value;
};

class SparseMatrix {
public:
    SparseMatrix(int m, int n);
    ~SparseMatrix();
    void insert(int i, int j, double value);
    double get(int i, int j);
    SparseMatrix* sum(SparseMatrix* other);
    SparseMatrix* multiply(SparseMatrix* other);
    void print();

private:
    Node** rows;
    Node** columns;
    int num_rows;
    int num_columns;
};

SparseMatrix::SparseMatrix(int m, int n) {
    if (m <= 0 || n <= 0) {
        throw std::invalid_argument("Invalid matrix dimensions");
    }

    num_rows = m;
    num_columns = n;

    // Create sentinel nodes for rows and columns
    rows = new Node*[m + 1];
    columns = new Node*[n + 1];

    for (int i = 1; i <= m; i++) {
        rows[i] = new Node();
        rows[i]->right = rows[i];
        rows[i]->down = rows[i];
        rows[i]->row = i;
    }

    for (int j = 1; j <= n; j++) {
        columns[j] = new Node();
        columns[j]->right = columns[j];
        columns[j]->down = columns[j];
        columns[j]->column = j;
    }
}

SparseMatrix::~SparseMatrix() {
    for (int i = 1; i <= num_rows; i++) {
        Node* current = rows[i]->right;

        while (current != rows[i]) {
            Node* temp = current;
            current = current->right;
            delete temp;
        }

        delete rows[i];
    }

    delete[] rows;
    delete[] columns;
}

void SparseMatrix::insert(int i, int j, double value) {
    if (i <= 0 || i > num_rows || j <= 0 || j > num_columns) {
        throw std::out_of_range("Invalid matrix indices");
    }

    Node* newNode = new Node();
    newNode->row = i;
    newNode->column = j;
    newNode->value = value;

    // Insert into row list
    newNode->right = rows[i]->right;
    rows[i]->right = newNode;

    // Insert into column list
    newNode->down = columns[j]->down;
    columns[j]->down = newNode;
}

double SparseMatrix::get(int i, int j) {
    if (i <= 0 || i > num_rows || j <= 0 || j > num_columns) {
        throw std::out_of_range("Invalid matrix indices");
    }

    Node* current = rows[i]->right;

    while (current != rows[i] && current->column != j) {
        current = current->right;
    }

    if (current != rows[i]) {
        return current->value;
    } else {
        return 0.0;
    }
}

SparseMatrix* SparseMatrix::sum(SparseMatrix* other) {
    if (num_rows != other->num_rows || num_columns != other->num_columns) {
        throw std::invalid_argument("Matrix dimensions must match");
    }

    SparseMatrix* result = new SparseMatrix(num_rows, num_columns);

    for (int i = 1; i <= num_rows; i++) {
        Node* current = rows[i]->right;

        while (current != rows[i]) {
            result->insert(current->row, current->column, current->value);
            current = current->right;
        }
    }

    for (int i = 1; i <= other->num_rows; i++) {
        Node* current = other->rows[i]->right;

        while (current != other->rows[i]) {
            double value = result->get(current->row, current->column);
            result->insert(current->row, current->column, value + current->value);
            current = current->right;
        }
    }

    return result;
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* other) {
    if (num_columns != other->num_rows) {
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplication");
    }

    SparseMatrix* result = new SparseMatrix(num_rows, other->num_columns);

    for (int i = 1; i <= num_rows; i++) {
        for (int j = 1; j <= other->num_columns; j++) {
            double value = 0.0;

            for (int k = 1; k <= num_columns; k++) {
                value += get(i, k) * other->get(k, j);
            }

            if (value != 0.0) {
                result->insert(i, j, value);
            }
        }
    }

    return result;
}

void SparseMatrix::print() {
    for (int i = 1; i <= num_rows; i++) {
        for (int j = 1; j <= num_columns; j++) {
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

SparseMatrix* readSparseMatrix(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    std::getline(file, line);
    std::stringstream ss(line);
    int m, n;
    ss >> m >> n;

    SparseMatrix* matrix = new SparseMatrix(m, n);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int i, j;
        double value;
        ss >> i >> j >> value;
        matrix->insert(i, j, value);
    }

    file.close();
    return matrix;
}