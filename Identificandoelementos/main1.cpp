#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool is_int(string s) {
    if (s.length() == 0) return false;
    int i = 0;
    if (s[0] == '-') i = 1;
    for (; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

bool is_float(string s) {
    if (s.length() == 0) return false;
    int i = 0;
    if (s[0] == '-') i = 1;
    bool point_found = false;
    for (; i < s.length(); i++) {
        if (s[i] == '.') {
            if (point_found) return false;
            point_found = true;
        } else if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return point_found;
}

int main() {
string frase;
getline(cin, frase);

vector<string> palavras;
istringstream ss(frase);
string palavra;
while (ss >> palavra) {
    palavras.push_back(palavra);
}

for (const auto& p : palavras) {
    if (is_int(p)) {
        cout << "int ";
    } else if (is_float(p)) {
        cout << "float ";
    } else {
        cout << "str ";
    }
}

cout << endl;

return 0;

}