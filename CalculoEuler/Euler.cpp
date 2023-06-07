#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fatorial(int n) {
    double fat = 1.0;
    for (int i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

double euler(int n) {
    double soma = 1.0;
    for (int i = 1; i <= n; i++) {
        soma += 1.0 / fatorial(i);
    }
    return soma;
}

int main() {
    int n;
    cin >> n;
    cout << fixed << setprecision(6) << euler(n) << endl;
    return 0;
}

