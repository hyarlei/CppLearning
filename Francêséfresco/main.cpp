#include <iostream>

using namespace std;

int main() {
    string frase;
    // vai pegar tudo que for digitado e aramazenar na variável
    getline(cin, frase);
    // percorrer a frase
    for (int i = 0; i < (int) frase.length(); i++) {
        if (i == frase.length() - 2) {
            cout << frase[i] << frase[i+1];
            break;
        }
        // condicionais para juntar as palavras, se for igual a vogal ou se o índice seguinte é um espaço ou após o espaço é uma letra igual a atual
        if ((frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u') && frase[i+1] == ' ' && frase[i] == frase[i+2]) {
            // imprimi
            cout << frase[i];
            char vogal = frase[i];
            // enquanto "vogal" == a letra ou for um espaço, continua o incremento;
            while ((frase[i] == vogal) || (frase[i] == ' ')) {
                i++;
            }
            // saiu do enquanto, retorna uma letra e continua o laço
            i--;
        } else {
            cout << frase[i];
        }
    }
}
