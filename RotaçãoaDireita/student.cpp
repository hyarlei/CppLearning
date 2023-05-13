#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    int n = vet.size();
    nrot %= n;  // garantir que nrot < n
    
    // Fazer nrot rotações de uma posição
    for(int i = 0; i < nrot; i++){
        // Guardar o último elemento
        int last = vet[n-1];
        // Deslocar todos os elementos uma posição para a direita
        for(int j = n-1; j > 0; j--){
            vet[j] = vet[j-1];
        }
        // Colocar o último elemento na primeira posição
        vet[0] = last;
    }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}