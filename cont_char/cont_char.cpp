#include <iostream>
#include <string>

using namespace std;

int countChar(char ch, string str) {
    if (str.length() == 0) {
        return 0;
    } else {
        int count = countChar(ch, str.substr(1)); // Chamada recursiva com a string a partir do segundo caractere
        if (str[0] == ch) {
            return count + 1;
        } else {
            return count;
        }
    }
}

int main() {
    string str;
    char ch;

    cout << "Digite uma string: ";
    getline(cin, str);

    cout << "Digite um caractere: ";
    cin >> ch;

    int count = countChar(ch, str);

    cout << "O caractere '" << ch << "' ocorre " << count << " vezes na string." << endl;

    return 0;
}
