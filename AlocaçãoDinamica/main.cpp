#include <iostream>

using namespace std;

int main()
{
    int **matriz;
    int linhas, colunas;

    cout << "Digite o numero de linhas: ";
    cin >> linhas;

    cout << "Digite o numero de colunas: ";
    cin >> colunas;

    matriz = new int*[linhas];

    for(int i = 0; i < linhas; i++){
        matriz[i] = new int[colunas];
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
        {
            cout << "Digite o elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz digitada: " << endl;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < linhas; i++){
        delete [] matriz[i];
    }

    delete [] matriz;

    return 0;
}