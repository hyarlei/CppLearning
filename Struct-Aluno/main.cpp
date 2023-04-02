#include <iostream>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

Aluno leAluno() {
    Aluno aluno;
    cin >> aluno.nome;
    cin >> aluno.matricula;
    cin.ignore(); // limpa o buffer do caractere \n
    getline(cin, aluno.disciplina);
    cin >> aluno.nota;
    return aluno;
}

void imprimeAlunoAprovado(Aluno aluno) {
    if(aluno.nota >= 7.0) {
        cout << aluno.nome << " aprovado(a) em " << aluno.disciplina << endl;
    } else {
        cout << aluno.nome << " reprovado(a) em " << aluno.disciplina << endl;
    }
}

int main() {
    Aluno aluno = leAluno();
    imprimeAlunoAprovado(aluno);
    return 0;
}
