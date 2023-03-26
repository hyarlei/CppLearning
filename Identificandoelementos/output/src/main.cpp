#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

bool is_integer(const string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

bool is_float(const string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+') && (s[0] != '.'))) {
        return false;
    }

    char* p;
    strtod(s.c_str(), &p);

    return (*p == 0);
}

int main() {
    string frase;
    getline(cin, frase); // Lê a linha de entrada

    // Converte a string para um vetor de palavras
    // vector<string> palavras;
    // string palavra_atual = "";
    // for (char c : frase) {
    //     if (isalnum(c) || c == '.') { // Encontrou um caractere alfanumérico ou um ponto, significa que faz parte de uma palavra
    //         palavra_atual += c;
    //     } else {
    //         if (!palavra_atual.empty()) { // Verifica se já tinha alguma palavra anterior
    //             palavras.push_back(palavra_atual);
    //         }
    //         palavra_atual = "";
    //     }
    // }
    // if (!palavra_atual.empty()) { // Adiciona a última palavra
    //     palavras.push_back(palavra_atual);
    // }

    stringstream ss(frase);
    vector<string> palavras;
    string palavra_atual;
    while (ss >> palavra_atual) {
        palavras.push_back(palavra_atual);
    }

    // Identifica os tipos de elementos
    for (const string& palavra : palavras) {
        if (is_integer(palavra)) {
            cout << "int ";
        } else if (is_float(palavra)) {
            cout << "float ";
        } else {
            cout << "str ";
        }
    }
    cout << endl;

    return 0;
}
