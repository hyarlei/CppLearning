#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str;
    string artigos[] = {"e", "o"};
    char format;
    getline(cin, str);
    cin >> format;

    // aplica o formato selecionado
    for (int i = 0; i < str.length(); i++) {
        switch (format) {
            case 'M':
                str[i] = toupper(str[i]);
                break;
            case 'm':
                str[i] = tolower(str[i]);
                break;
            case 'P':
                if ((str[i - 1]== ' ' && str[i] + 1 == ' ') && i != 0 && i != str.length()) {
                    str[i] = toupper(str[i]);
                } else {
                    str[i] = tolower(str[i]);
                }
                break;
            case 'i':
                if (isupper(str[i])) {
                    str[i] = tolower(str[i]);
                } else if (islower(str[i])) {
                    str[i] = toupper(str[i]);
                }
                break;
        }
    }

    cout << str << endl;
    return 0;
}
