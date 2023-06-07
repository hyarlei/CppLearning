#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string frase;
    getline(cin, frase); // Lê a linha de entrada

    // Converte a string para um vetor de palavras
    vector<string> palavras;
    string palavra_atual = "";
    for (char c : frase) {
        if (c == ' ') { // Encontrou um espaço, significa que terminou uma palavra
            if (palavra_atual > "") { // Verifica se já tinha alguma palavra anterior
                palavras.push_back(palavra_atual);
            }
            palavra_atual = "";
        } else {
            palavra_atual += c;
        }
    }
    if (palavra_atual > "") { // Adiciona a última palavra
        palavras.push_back(palavra_atual);-
    }
    

    // Verifica se o vetor de palavras está ordenado
    bool ordenado = is_sorted(palavras.begin(), palavras.end());

    // Imprime "sim" ou "nao"
    if (ordenado) {
        cout << "sim\n";
    } else {
        cout << "nao\n";
    }

    return 0;
}
