#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "MatrizLista.cpp"

using namespace std;

/* comandos:

criar matriz: cria n n (cria matriz com n linhas e n colunas)
ler arquivo: arquivo n (numero da matriz a ser preenchida) A.txt (nome do arquivo e extenção) Ex: arquivo 0 A.txt
inserir valor na matriz: insere n (numero da matriz) n (linha) n (coluna) n (valor) Ex: insere 0 1 1 99
checar valor da matriz: valor n (numero da matriz) n (linha) n (coluna) Ex: valor 0 1 1
somar matrizes: soma n (numero da primeira matris) n (numero da segunda matris) Ex: soma 0 1
multiplicar matrizes: multiplica n (numero da primeira matris) n (numero da segunda matris) Ex: multiplica 0 1

obs: para preencher matriz através do arquivo é necessário que a matriz já tenha sido criada
Ex:
g++ main.cpp matrizfuncoes.cpp -o main
./main
cria 4 4
arquivo 0 A.txt */

int main()
{
	vector<SparseMatriz*> matrizes;

	while (true) {
		string cmd;
		getline(cin, cmd);

		std::stringstream ss{ cmd };
		vector<string> tokens;
		string buffer;

		while (ss >> buffer) {
			tokens.push_back(buffer);
		}

		if (tokens.empty()) {
			cout << "Por favor, insira um comando." << endl;
			continue;
		}

		if (tokens[0] == "libera" || tokens[0] == "exit") {
			for (int i = 0; i < matrizes.size(); ++i) {
				delete matrizes[i];
				matrizes[i] = nullptr;
			}
			matrizes.clear();
			break;
		}
		// cria matriz.
		else if (tokens[0] == "cria") {
			if (tokens.size() < 3) {
				cout << "Comando 'cria' requer 2 argumentos: cria <linhas> <colunas>" << endl;
				continue;
			}
			int l = std::stoi(tokens[1]);
			int c = std::stoi(tokens[2]);
			SparseMatriz* m = new SparseMatriz(l, c);
			matrizes.push_back(m);
		}
		// imprime matriz
		else if (tokens[0] == "imprime") {
			if (tokens.size() < 2) {
				cout << "Comando 'imprime' requer 1 argumento: imprime <numero da matriz>" << endl;
				continue;
			}
			int k = std::stoi(tokens[1]);
			if (k >= 0 && k < matrizes.size()) {
				matrizes[k]->print();
			}
			else {
				cout << "Matriz não encontrada." << endl;
			}
		}
		// insere valor na matriz
		else if (tokens[0] == "insere") {
			if (tokens.size() < 5) {
				cout << "Comando 'insere' requer 4 argumentos: insere <numero da matriz> <linha> <coluna> <valor>" << endl;
				continue;
			}
			int k = std::stoi(tokens[1]);
			if (k >= 0 && k < matrizes.size()) {
				int i = std::stoi(tokens[2]);
				int j = std::stoi(tokens[3]);
				double v = std::stod(tokens[4]);
				matrizes[k]->insert(i, j, v);
			}
			else {
				cout << "Matriz não encontrada." << endl;
			}
		}
		// ler arquivo
		else if (tokens[0] == "arquivo") {
			if (tokens.size() < 3) {
				cout << "Comando 'arquivo' requer 2 argumentos: arquivo <numero da matriz> <nome do arquivo>" << endl;
				continue;
			}
			int k = std::stoi(tokens[1]);
			if (k >= 0 && k < matrizes.size()) {
				std::string arquivo = tokens[2];
				cout << "Lendo arquivo " << arquivo << endl;
				SparseMatriz* c = matrizes[k]->lerMatrizDeArquivo(arquivo);
				if (c != nullptr) {
					delete matrizes[k];
					matrizes[k] = c;
				}
			}
			else {
				cout << "Matriz não encontrada." << endl;
			}
		}
		// soma matrizes
		else if (tokens[0] == "soma") {
			if (tokens.size() < 3) {
				cout << "Comando 'soma' requer 2 argumentos: soma <numero da primeira matriz> <numero da segunda matriz>" << endl;
				continue;
			}
			int p = std::stoi(tokens[1]);
			int q = std::stoi(tokens[2]);
			if (p >= 0 && p < matrizes.size() && q >= 0 && q < matrizes.size()) {
				SparseMatriz* C = matrizes[p]->soma(matrizes[q]);
				if (C == nullptr) {
					cout << "Não foi possível somar as matrizes." << endl;
				}
				else {
					C->print();
					delete C;
				}
			}
			else {
				cout << "Matriz não encontrada." << endl;
			}
		}
		// multiplica matrizes
		else if (tokens[0] == "multiplica") {
			if (tokens.size() < 3) {
				cout << "Comando 'multiplica' requer 2 argumentos: multiplica <numero da primeira matriz> <numero da segunda matriz>" << endl;
				continue;
			}
			int p = std::stoi(tokens[1]);
			int q = std::stoi(tokens[2]);
			if (p >= 0 && p < matrizes.size() && q >= 0 && q < matrizes.size()) {
				SparseMatriz* C = matrizes[p]->multiplica(matrizes[q]);
				if (C == nullptr) {
					cout << "Não foi possível multiplicar as matrizes." << endl;
				}
				else {
					C->print();
					delete C;
				}
			}
			else {
				cout << "Matriz não encontrada." << endl;
			}
		}
		// verifica valor na matriz
		else if (tokens[0] == "valor") {
			if (tokens.size() < 4) {
				cout << "Comando 'valor' requer 3 argumentos: valor <numero da matriz> <linha> <coluna>" << endl;
				continue;
			}
			int k = std::stoi(tokens[1]);
			if (k >= 0 && k < matrizes.size()) {
				int i = std::stoi(tokens[2]);
				int j = std::stoi(tokens[3]);
				double v = matrizes[k]->getValue(i, j);
				cout << "Valor: " << v << endl;
			}
			else {
				cout << "Matriz não encontrada." << endl;
			}
		}
		else {
			cout << "Comando inexistente." << endl;
		}
	}

	return 0;
}
