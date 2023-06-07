#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c) {
    if (n == 0) { // Caso base: fim da string
        return 0;
    } else {
        int count = contaCaracteres(str, n-1, c); // Chamada recursiva com a string sem o último caractere
        if (str[n-1] == c) { // Verifica se o último caractere é igual ao caractere desejado
            return count + 1; // Incrementa o contador
        } else {
            return count;
        }
    }
}

int main() { 
    string str;
    char c;

    getline(cin, str);

    cin >> c;

    int n = str.length();
    int count = contaCaracteres(str, n, c);

    cout << count << endl;

    return 0;
}
