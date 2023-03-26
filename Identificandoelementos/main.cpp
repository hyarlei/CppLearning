#include <iostream>      // Inclui a biblioteca para entrada e saída de dados
#include <string>        // Inclui a biblioteca para trabalhar com strings
using namespace std;     // Define o namespace padrão como "std"

// Função que verifica se uma string representa um número inteiro
bool is_int(string s) {
    if (s.length() == 0) return false;      // Se a string estiver vazia, retorna falso
    int i = 0;                              // Inicializa o índice para percorrer a string
    if (s[0] == '-') i = 1;                 // Se a string começa com '-', incrementa o índice
    for (; i < s.length(); i++) {           // Percorre a string a partir do índice atual
        if (s[i] < '0' || s[i] > '9') {     // Se algum caractere não for um dígito numérico, retorna falso
            return false;
        }
    }
    return true;                            // Se todos os caracteres forem dígitos numéricos, retorna verdadeiro
}

// Função que verifica se uma string representa um número de ponto flutuante
bool is_float(string s) {
    if (s.length() == 0) return false;      // Se a string estiver vazia, retorna falso
    int i = 0;                              // Inicializa o índice para percorrer a string
    if (s[0] == '-') i = 1;                 // Se a string começa com '-', incrementa o índice
    bool point_found = false;               // Inicializa uma variável para indicar se já foi encontrado um ponto decimal
    for (; i < s.length(); i++) {           // Percorre a string a partir do índice atual
        if (s[i] == '.') {                  // Se o caractere atual for um ponto decimal
            if (point_found) return false;  // Se já foi encontrado um ponto decimal anteriormente, retorna falso
            point_found = true;             // Senão, marca que foi encontrado um ponto decimal
        } else if (s[i] < '0' || s[i] > '9') {     // Se algum caractere não for um dígito numérico
            return false;                   // Retorna falso
        }
    }
    return point_found;                     // Se foi encontrado pelo menos um ponto decimal, retorna verdadeiro
}

int main() {
    string input;                           // Declara uma variável para armazenar a entrada do usuário
    getline(cin, input);                    // Lê uma linha de texto da entrada padrão e armazena na variável input
    string word;                            // Declara uma variável para armazenar cada palavra separada por espaços na entrada
    for (int i = 0; i < input.length(); i++) {   // Percorre cada caractere da entrada
        if (input[i] == ' ') {              // Se encontrar um espaço em branco
            if (word.length() == 0) continue;   // Se a palavra atual estiver vazia, pula para o próximo caractere
            if (is_int(word)) {             // Se a palavra atual for um número inteiro
                cout << "int ";            // Imprime "int" seguido de um espaço
            } else if (is_float(word)) {
                cout << "float ";          // Se a palavra atual for um número de ponto flutuante
            } else {                        // Se a palavra atual não for um número inteiro nem de ponto flutuante
                cout << "string ";         // Imprime "string" seguido de um espaço
            }
            word = "";                      // Limpa a variável word para armazenar a próxima palavra
        } else {                            // Se o caractere atual não for um espaço em branco
            word += input[i];               // Adiciona o caractere atual à palavra atual
        }
    }
    if (word.length() > 0) {                // Se a última palavra não foi impressa
        if (is_int(word)) {                 // Se a palavra atual for um número inteiro
            cout << "int ";                // Imprime "int" seguido de um espaço
        } else if (is_float(word)) {
            cout << "float ";              // Se a palavra atual for um número de ponto flutuante
        } else {                            // Se a palavra atual não for um número inteiro nem de ponto flutuante
            cout << "string ";             // Imprime "string" seguido de um espaço
        }
    }
    cout << endl;                           // Imprime uma quebra de linha
    return 0;                               // Retorna 0 para indicar que o programa terminou com sucesso
}
