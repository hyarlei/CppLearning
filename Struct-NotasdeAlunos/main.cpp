#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Aluno {
    string nome;// string é uma classe
    int matricula;// int é um tipo primitivo
    string disciplina;
    double nota;// double é um tipo primitivo
};

Aluno leAluno() {
    Aluno aluno; // aluno é uma variável do tipo Aluno
    cin >> aluno.nome; // Pega o nome do aluno
    cin >> aluno.matricula; // Pega a matricula do aluno
    cin >> aluno.disciplina; // Pega a disciplina do aluno
    cin >> aluno.nota; // Pega a nota do aluno
    return aluno; //retorna o aluno
}

void imprimeMaiorNota(Aluno aluno1, Aluno aluno2) {
    if (aluno1.nota > aluno2.nota) { // analisando a nota do aluno1 e aluno2
        cout << fixed << setprecision(1) << aluno1.nome << " , " << aluno1.nota << endl; //imprime o nome do aluno1 e a nota do aluno1
    } else if (aluno1.nota < aluno2.nota) { // analisando a nota do aluno1 e aluno2
        cout << fixed << setprecision(1) << aluno2.nome << " , " << aluno2.nota << endl; //imprime o nome do aluno2 e a nota do aluno2
    } else { // se as notas forem iguais
        cout << fixed << setprecision(1) << aluno1.nome << " e " << aluno2.nome << " , " << aluno1.nota << endl; //imprime o nome dos alunos e a nota
    }
}

int main() {
    Aluno aluno1 = leAluno(); //aluno1 é uma variável do tipo Aluno
    Aluno aluno2 = leAluno(); //aluno2 é uma variável do tipo Aluno
    imprimeMaiorNota(aluno1, aluno2); //imprime o aluno com a maior nota
    return 0;
}