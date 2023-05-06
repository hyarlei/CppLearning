// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"

using namespace std;

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int m, int n){
	col = n;
	lin = m;
	mat = new int *[m];
	for (int i = 0; i < m; i++){
		mat[i] = new int [n];
	};
}

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz(){
	for (int i = 0; i < linhas(); i++){
		delete[] mat[i];
	}
	delete[] mat;
	cout << "matriz liberada" << endl;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas(){
	return lin;
}

// Retorna o numero de colunas da matriz
int Matriz::colunas(){
	return col;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j){
	return mat[i][j];
}

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j){
	mat[i][j] = valor;
}

// Imprimir a matriz
void Matriz::print(){
	for (int i = 0; i < lin; ++i){
		for (int j = 0; j < col; ++j){
			cout << setw(7) << mat[i][j];
		}
		cout << "\n";
	}
}

// Soma matrizes
Matriz *Matriz::soma(Matriz &B){
	if (B.linhas() == linhas() && B.colunas() == colunas()){
		Matriz *resultado = new Matriz(linhas(), colunas());
		for (int i = 0; i < linhas(); i++){
			for (int j = 0; j < colunas(); j++){
				 resultado->setValor(B.getValor(i, j) + getValor(i, j), i, j);
			}
		}
		return resultado;
	}
	else{
		return nullptr;
	}
}

//Multiplica matrizes
Matriz *Matriz::multiplica(Matriz &B){
	if (colunas() == B.linhas()){
		Matriz *resultado = new Matriz(linhas(), B.colunas());
		for (int i = 0; i < linhas(); i++){
			for (int j = 0; j < B.colunas(); j++){
				int soma = 0;
 				for (int k = 0; k < colunas(); k++){
 					soma += getValor(i, k) * B.getValor(k, j);
				}
 				resultado->setValor(soma, i, j);
 			}
 		}
 		return resultado;
 	}
 	else{
 		return nullptr;
	}
}