#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "matrizlista.h"
#include <cstdlib>

using namespace std;

/* comandos:

criar matriz: cria n n (cria matriz com n linhas e n colunas)
ler arquivo: arquivo n (numero da matriz a ser preenchida) A.txt (nome do arquivo e extenção) Ex: arquivo 0 A.txt
inserir valor na matriz: insere n (numero da matriz) n (linha) n (coluna) n (valor) Ex: insere 0 1 1 99
checar valor da matriz: valor n (numero da matriz) n (linha) n (coluna) Ex: valor 0 1 1
somar matrizes: soma n (numero da primeira matris) n (numero da segunda matris) Ex: soma 0 1
multiplicar matrizes: multiplica n (numero da primeira matris) n (numero da segunda matris) Ex: multiplica 0 1

obs: para preencher matriz através do arquivo é necessário que a matriz já tenha sido criada
Ex:
g++ main.cpp matrizfuncoes.cpp -o main
./main
cria 4 4
arquivo 0 A.txt */

void limparTela()
{
    std::system("clear");
}

void mostrarMenu()
{
    cout << "==== Menu ====" << endl;
    cout << "1. Criar matriz" << endl;
    cout << "2. Ler matriz de arquivo" << endl;
    cout << "3. Inserir valor na matriz" << endl;
    cout << "4. Verificar valor na matriz" << endl;
    cout << "5. Somar matrizes" << endl;
    cout << "6. Multiplicar matrizes" << endl;
    cout << "7. Imprimir matriz" << endl;
    cout << "8. Sair" << endl;
    cout << "Digite o número da opção desejada: ";
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

        if (tokens[0] == "libera" || tokens[0] == "exit")
        {
            for (int i = 0; i < matrizes.size(); ++i)
            {
                delete matrizes[i];
                matrizes[i] = nullptr;
            }
            matrizes.clear();
            break;
        }
        // cria matriz.
        else if (tokens[0] == "1")
        {
            int l = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            SparseMatriz *m = new SparseMatriz(l, c);
            matrizes.push_back(m);

            cout << "Matriz " << matrizes.size() - 1 << " criada com sucesso!" << endl;
        }
        // imprime matriz
        else if (tokens[0] == "7")
        {
            int k = stoi(tokens[1]);
            matrizes[k]->print();

            cout << "Matriz " << k << " impressa com sucesso!" << endl;
        }
        // insere valor na matriz
        else if (tokens[0] == "3")
        {
            int k = stoi(tokens[1]);
            int i = stoi(tokens[2]);
            int j = stoi(tokens[3]);
            double v = stoi(tokens[4]);
            matrizes[k]->insert(i, j, v);

            cout << "Valor " << v << " inserido na matriz " << k << " com sucesso!" << endl;
        }
        // ler arquivo
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

            cout << "Matriz " << k << " lida com sucesso!" << endl;
        }
        // soma matrizes
        else if (tokens[0] == "5")
        {
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
        // multiplica matrizes
        else if (tokens[0] == "6")
        {
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
        // verifica valor na matriz
        else if (tokens[0] == "4")
        {
            int k = stoi(tokens[1]);
            int i = stoi(tokens[2]);
            int j = stoi(tokens[3]);
            double v = matrizes[k]->getValue(i, j);
            cout << "valor: " << v << endl;

            cout << "Valor " << v << " verificado na matriz " << k << " com sucesso!" << endl;
        }
        else
        {
            cout << "comando inexistente" << endl;
        }

        cout << endl;

        limparTela();
    }
    return 0;
}
