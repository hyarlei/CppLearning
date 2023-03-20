#include <iostream>

using namespace std;

int main() {
    int valor, chute1, chute2;
    cin >> valor >> chute1 >> chute2;
    if (abs(valor - chute1) < abs(valor - chute2)) {
        cout << "primeiro" << endl;
    } else if (abs(valor - chute1) > abs(valor - chute2)) {
        cout << "segundo" << endl;
    } else {
        cout << "empate" << endl;
    }
    return 0;
}