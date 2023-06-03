#ifndef MATRIZ
#define MATRIZ

struct Node;

class SparseMatriz {
private:
    Node* head;
    Node* lin;
    Node* col;
    int mlinha, mcoluna;
public:
    // Constructor
    SparseMatriz(int m, int n);

    // Destructor
    ~SparseMatriz();

    // Other member functions
    void createHead(int m, int n);
    void insert(int i, int j, double value);
    double getValue(int i, int j);
    int getColuna();
    int getLinha();
    void print();
    SparseMatriz* soma(SparseMatriz* A, SparseMatriz* B);
    SparseMatriz* lerMatrizDeArquivo(std::string nomeDoArquivo);
};

SparseMatriz* multiplica(SparseMatriz* A, SparseMatriz* B);

#endif
