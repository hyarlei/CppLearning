// Dado uma matriz que representa espaços vazios e árvores e um ponto inicial onde começa o fogo, retorne a matriz com as árvores queimadas. O fogo não se espalha nas diagonais, apenas nas 4 direções cardeais.

// A matriz está codificada assim:

// 1a linha: nl, nc, l, c respectivamente - número de linhas e colunas da matriz, linha e coluna onde começa o fogo.

// - Nas linhas subsequentes:

// ‘#’ representa uma árvore
// ‘.’ representa um espaço vazio
// ‘o’ representa uma árvore queimada
// Saída esperada:

// Imprima a matriz após a queimada acontecer.
// Testes
// >>>>>>>> 01
// 2 3 1 1
// #.#
// .##
// ========
// #.o
// .oo
// <<<<<<<<

// Você pode utilizar um array de strings para representar uma matriz de caracteres. Uma string é um vetor de caracteres. Dessa forma, um string mat[5] é um vetor de caracteres bidimensional com 5 linhas, por exemplo. O exemplo a seguir já carrega a matriz na main e já faz um método capaz de imprimir a matriz. Você só precisa implementar o método tocar_fogo.

// Utilize as seguintes regras para recursão:

// Se a posição for fora da matriz, retorne.
// Se a posição não for uma arvore retorne.
// Queime a arvore.
// Chame a recursão para todos os vizinhos.

#include <iostream>
#include <string>

using namespace std;


void show(string *mat, int nl) {
    for(int l = 0; l < nl; l++)
        cout << mat[l] << "\n";
}

void tocar_fogo(int nl, int nc, string* mat, int l, int c){
    if (l < 0 || l >= nl || c < 0 || c >= nc || mat[l][c] != '#') {
        return;
    }
    mat[l][c] = 'o';
    tocar_fogo(nl, nc, mat, l - 1, c);
    tocar_fogo(nl, nc, mat, l + 1, c);
    tocar_fogo(nl, nc, mat, l, c - 1);
    tocar_fogo(nl, nc, mat, l, c + 1);
}

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    cin >> nl >> nc >> lfire >> cfire;
    string* mat = new string[nl];
    for(int l = 0; l < nl; l++){
        string line;
        cin >> line;
        mat[l] = line;
    }
    tocar_fogo(nl, nc, mat, lfire, cfire);
    show(mat, nl);
    delete[] mat;
    return 0;
}