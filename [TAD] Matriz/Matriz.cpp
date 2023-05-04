// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int n, int m) {
	lin = n;
	col = m;
	mat = new int *[lin];
	for(int i = 0; i < lin; i++){
		mat[i] = new int [col];
	}
}

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz() {
	for(int i = 0; i < lin; i++){
		delete[] mat[i];
	}
	delete[] mat;
}   

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
	return lin;
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
	return col;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j) {
	return mat[i][j];
} 

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j) {
	mat[i][j] = valor;
}

// Imprimir a matriz 
void Matriz::print(int largura) {
    for(int i = 0; i < lin; i++) {
		for(int j = 0; j < col; ++j) {
			std::cout << std::setw(largura) << mat[i][j];
		}
		std::cout << std::endl;
	}
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz *B) {
	for(int i = 0; i < lin; i++) {
		for(int j = 0; j < col; ++j) {
			std::cout << mat[i][j] + B->mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz *B) {
	for(int i = 0; i < lin; i++) {
		for(int j = 0; j < col; ++j) {
			std::cout << mat[i][j] * B->mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
