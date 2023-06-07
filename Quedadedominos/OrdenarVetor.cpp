#include <iostream>

using namespace std;

int main() {
    int n, i, v[50];
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            cout << "precisa de ajuste" << endl;
            return 0;
        }
    }
    cout << "ok" << endl;
    return 0;
}
