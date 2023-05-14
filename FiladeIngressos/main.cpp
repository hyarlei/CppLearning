#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void removePessoa(vector<int>* fila, int id) {
    auto it = find(fila->begin(), fila->end(), id);
    if (it != fila->end()) {
        fila->erase(it);
    }
}

void imprimeFila(vector<int>* fila) {
    for (int i = 0; i < fila->size(); i++) {
        cout << (*fila)[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m, id;
    vector<int> fila;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id;
        fila.push_back(id);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> id;
        removePessoa(&fila, id);
    }

    imprimeFila(&fila);

    return 0;
}
