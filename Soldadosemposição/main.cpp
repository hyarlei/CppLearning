#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nl, nc;
    cin >> nl >> nc;

    vector<vector<int>> soldados(nl, vector<int>(nc));

    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            cin >> soldados[i][j];
        }
    }

    int cont = 0;

    for (int j = 0; j < nc; j++) {
        int menor = soldados[0][j];
        for (int i = 1; i < nl; i++) {
            if (soldados[i][j] < menor) {
                menor = soldados[i][j];
                cont++;
            }
        }
    }

    cout << cont << endl;
    return 0;
}
