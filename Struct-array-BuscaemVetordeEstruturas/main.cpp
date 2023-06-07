#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Aluno{
    int matricula;
    string nome;
    double media;
};

int main(){
    int n;
    cout << "Quantos alunos deseja cadastrar? ";
    cin >> n;

    vector<Aluno> alunos(n);

    for(int i = 0; i < n; i++){
        cout << "Matricula: ";
        cin >> alunos[i].matricula;
        cin.ignore(); // Ignora o '\n' deixado pelo cin antes de ler a string
        cout << "Nome: ";
        getline(cin, alunos[i].nome);
        cout << "Media: ";
        cin >> alunos[i].media;
    }

    int matricula;
    cout << "Qual matricula deseja buscar? ";
    cin >> matricula;

    bool encontrou = false;

    for(int i = 0; i < alunos.size(); i++){
        if(alunos[i].matricula == matricula){
            cout << "Nome: " << alunos[i].nome << endl;
            cout << fixed << setprecision(1) << "Media: " << alunos[i].media << endl;
            encontrou = true;
            break;
        }
    }

    if(!encontrou){
        cout << "NAO ENCONTRADA" << endl;
    }

    return 0;
}
