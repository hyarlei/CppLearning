#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void printTriangle(vector<int> v) {
    int n = v.size();
    if (n == 1) { // caso base
        cout << "[" << v[0] << "]" << endl;
        return;
    }
    vector<int> v_new(n-1);
    for (int i = 0; i < n-1; i++) {
        v_new[i] = v[i] + v[i+1];
    }
    printTriangle(v_new);
    cout << "[";
    for (int i = 0; i < n-1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[n-1] << "]" << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    printTriangle(v);
    return 0;
}
