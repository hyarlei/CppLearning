#include <iostream>

using namespace std;

int main() {
    string str;
    char format;
    getline(cin, str);
    cin >> format;

    for (int i = 0; i < str.length(); i++) {
        switch (format) {
            case 'M':
                str[i] = toupper(str[i]);
                break;
            case 'm':
                str[i] = tolower(str[i]);
                break;
            case 'p':
                if(i == 0 && str[i + 1] == ' '){
                    str[i] = tolower(str[0]);
                } else {
                    if(str[i - 1] == ' ' && str[i + 1] == ' '){
                        str[i] = tolower(str[i]);
                    } else {
                        if (tolower(str[i - 1]) == ' ') {
                            str[i] = toupper(str[i]);
                        } else {
                            str[i] = tolower(str[i]);
                        }
                    }
                    
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