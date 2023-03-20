#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Ordenar lista de inteiros

int main()
{
    vector<int> lista;//vector: Função que cria um vetor. 
    int n, i, x;

    cout << "Digite o numero de elementos da lista: ";//cout: Função que imprime na tela.
    cin >> n;//cin: Função que lê o que o usuário digita.

    for (i = 0; i < n; i++)
{
        cout << "Digite o elemento " << i + 1 << ": ";
        cin >> x;
        lista.push_back(x);//pushed back: Função que armazena o elemento x no final do vetor.
    }

    sort(lista.begin(), lista.end());
    //sort: Função que ordena os elementos do vetor em ordem crescente.
    //begin: Função que retorna o primeiro elemento do vetor (posição 0).
    //end: Função que retorna o primeiro elemento do vetor (posição n-1).

    cout << "Lista ordenada: ";
    for (i = 0; i < n; i++)
        cout << lista[i] << " ";
        cout << endl;//endl: Função que pula uma linha.

    return 0;
}