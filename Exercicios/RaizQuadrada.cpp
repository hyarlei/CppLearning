#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double numero, raiz;
    cout << "Digite um numero: ";//cout: Função que imprime na tela.
    cin >> numero;//cin: Função que lê o que o usuário digita.
    raiz = sqrt(numero);//sqrt: Função que calcula a raiz quadrada de um número.
    cout << "A raiz quadrada de " << numero << " e " << raiz << endl;
    return 0;
}