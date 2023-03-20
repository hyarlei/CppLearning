#include <iostream>
using namespace std;

bool verificaQuadradoMagico(int matriz[3][3]) {
  int somaDiagonalPrincipal = 0;
  int somaDiagonalSecundaria = 0;

  // Verifica soma das diagonais principal e secundária
  for (int i = 0; i < 3; i++) {
    somaDiagonalPrincipal += matriz[i][i];
    somaDiagonalSecundaria += matriz[i][2-i];
  }
  if (somaDiagonalPrincipal != somaDiagonalSecundaria) {
    return false;
  }

  // Verifica soma das linhas e colunas
  for (int i = 0; i < 3; i++) {
    int somaLinha = 0;
    int somaColuna = 0;
    for (int j = 0; j < 3; j++) {
      somaLinha += matriz[i][j];
      somaColuna += matriz[j][i];
    }
    if (somaLinha != somaDiagonalPrincipal || somaColuna != somaDiagonalPrincipal) {
      return false;
    }
  }

  // Se chegou até aqui, é um quadrado mágico
  return true;
}

int main() {
  int matriz[3][3];
  cout << "Digite os elementos da matriz 3x3:" << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> matriz[i][j];
    }
  }
  if (verificaQuadradoMagico(matriz)) {
    cout << "sim" << endl;
  } else {
    cout << "nao" << endl;
  }
  return 0;
}