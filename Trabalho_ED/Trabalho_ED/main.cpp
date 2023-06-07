#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "matrizlista.h"

using namespace std;

/* comandos:

Para preencher a Matriz através do arquivo é necessário que a matriz já tenha sido criada
Ex:
g++ main.cpp matrizfuncoes.cpp -o main
./main
Para criar -> Ex: 1 4 4
Ler arquivo -> Ex: 2 0 matriz1.txt */

void limparTela()
{
    std::system("clear");
}

void mostrarMenu()
{
    cout << "======================================================== Menu ===================================================================" << endl;
    cout << "|   1. Criar matriz - (Informar tamanho da matriz - Ex: 1 4 4)                                                                  |" << endl;
    cout << "|   2. Ler matriz de arquivo - (Número da matriz a ser preenchida e o nome do arquivo e extensão - Ex: 2 0 matriz1.txt)         |" << endl;
    cout << "|   3. Inserir valor na matriz - (Número da matriz) n (Número da linha) n (Número da coluna) n (Valor) Ex: 0 1 1 99             |" << endl;
    cout << "|   4. Verificar valor na matriz - (Número da matriz) n (linha) n (coluna) Ex: 4 0 1 1                                          |" << endl;
    cout << "|   5. Somar matrizes - (Número da primeira matriz) n (Número da segunda matriz) Ex: 5 0 1                                      |" << endl;
    cout << "|   6. Multiplicar matrizes - (Número da primeira matriz) n (Número da segunda matriz) Ex: 6 0 1                                |" << endl;
    cout << "|   7. Imprimir matriz - (Número da matriz) Ex: 7 0                                                                             |" << endl;
    cout << "|   8. Sair                                                                                                                     |" << endl;
    cout << "=================================================================================================================================" << endl;

    cout << "Digite o número da opção desejada e mais as informações que você deseja: ";
}

int main()
{
    vector<SparseMatriz *> matrizes;
    limparTela();
    while (true)
    {

        mostrarMenu();

        string cmd;
        getline(cin, cmd);

        stringstream ss{cmd};
        vector<string> tokens;
        string buffer;

        while (ss >> buffer)
        {
            tokens.push_back(buffer);
        }

        // Cria matriz.
        else if (tokens[0] == "1")
        {
            int l = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            SparseMatriz *m = new SparseMatriz(l, c);
            matrizes.push_back(m);

            limparTela();
            cout << "Matriz " << matrizes.size() - 1 << " criada com sucesso!" << endl;
        }

        // Ler arquivo
        else if (tokens[0] == "2")
        {
            int k = stoi(tokens[1]);
            string arquivo = tokens[2];
            cout << "Lendo arquivo " << arquivo << endl;
            SparseMatriz *c;
            c = c->lerMatrizDeArquivo(arquivo);
            matrizes[k]->lerMatrizDeArquivo(arquivo);
            if (matrizes[k] != nullptr)
                delete matrizes[k];

            c = c->lerMatrizDeArquivo(arquivo);
            matrizes[k] = c;

            limparTela();
            cout << "Matriz " << k << " lida com sucesso!" << endl;
        }

        // Insere valor na matriz
        else if (tokens[0] == "3")
        {
            int k = stoi(tokens[1]);
            int i = stoi(tokens[2]);
            int j = stoi(tokens[3]);
            double v = stoi(tokens[4]);
            matrizes[k]->insert(i, j, v);

            limparTela();
            cout << "Valor " << v << " inserido na matriz " << k << " com sucesso!" << endl;
        }

        // Verifica valor na matriz
        else if (tokens[0] == "4")
        {
            int k = stoi(tokens[1]);
            int i = stoi(tokens[2]);
            int j = stoi(tokens[3]);
            double v = matrizes[k]->getValue(i, j);
            cout << "valor: " << v << endl;

            limparTela();
            cout << "Valor " << v << " verificado na matriz " << k << " com sucesso!" << endl;
        }

        // Soma matrizes
        else if (tokens[0] == "5")
        {
            limparTela();
            int p = stoi(tokens[1]);
            int q = stoi(tokens[2]);
            SparseMatriz *C = matrizes[p]->soma(matrizes[p], matrizes[q]);

            if (C == nullptr)
                cout << "nao foi possivel somar" << endl;
            else
            {
                C->print();
                delete C;
            }

            cout << "Matriz " << p << " somada com a matriz " << q << " com sucesso!" << endl;
        }

        // Multiplica matrizes
        else if (tokens[0] == "6")
        {
            limparTela();
            int p = stoi(tokens[1]);
            int q = stoi(tokens[2]);
            SparseMatriz *C = multiplica(matrizes[p], matrizes[q]);
            if (C == nullptr)
                cout << "nao foi possivel multiplicar" << endl;
            else
            {
                C->print();
                delete C;
            }

            cout << "Matriz " << p << " multiplicada com a matriz " << q << " com sucesso!" << endl;
        }

        // Imprime matriz
        else if (tokens[0] == "7")
        {
            limparTela();
            int k = stoi(tokens[1]);
            matrizes[k]->print();

            cout << "Matriz " << k << " impressa com sucesso!" << endl;
        }

        // Sair
        else if (tokens[0] == "8")
        {
            limparTela();
            cout << "Saindo..." << endl;
            break;
        }
        else
        {
            limparTela();
            cout << "comando inexistente" << endl;
        }

        cout << endl;
    }
    return 0;
}