#include <iostream>
#include <string>

using namespace std;

struct Paciente {
    int identificador;
    string nome;
    float altura;
    int idade;
    float peso;
};

void imprimirMenu() {
    cout << "---------PONTUARIO MEDICO---------" << endl;
    cout << "Digite 1: Inicializar o pontuario." << endl;
    cout << "Digite 2: imprimir um paciente." << endl;
    cout << "Digite 3: inserir um paciente." << endl;
    cout << "Digite 4: editar um paciente." << endl;
    cout << "Digite 5: Sair." << endl;
    cout << "------------------------------------" << endl;
}

void inicializarPontuario(Paciente pontuario[], int tam) {
    for(int i = 0; i < tam; i++){
        pontuario[i].identificador = -1;
    }
    cout << "pontuario medico inicializado com sucesso!" << endl;
}

Paciente lerPaciente() {
    Paciente paciente;

    cout << "Digite o indentificador do paciente: " << endl;
    cin >> paciente.identificador;

    cout << "Digite o seu nome: " << endl;
    cin >> paciente.nome;

    cout << "Digite a sua altura: " << endl;
    cin >> paciente.altura;

    cout << "Digite a sua idade: " << endl;
    cin >> paciente.idade;

    cout << "Digite o seu peso: " << endl;
    cin >> paciente.peso;

    return paciente;
}

void imprimirPaciente(Paciente paciente) {
    cout << "--------Paciente----------" << endl;
    cout << "Indentificador: " << paciente.identificador << endl;
    cout << "Nome: " << paciente.nome << endl;
    cout << "Altura: " << paciente.altura << endl;
    cout << "Idade: " << paciente.idade << endl;
    cout << "Peso: " << paciente.peso << endl;
    cout << "--------------------------" << endl;
}

void adicionarpaciente(Paciente pontuario[], int tam) {
    cout << "Adicionando pacientes no pontuario medico..." << endl;

    int adicionou = 0;

    for(int i = 0; i < tam; i++) {
        if(pontuario[i].identificador == -1) {
            Paciente pacienteAdicionar = lerPaciente();
            pontuario[i] = pacienteAdicionar;
            adicionou = 1;
            break;
        }
    }
    if(adicionou == 1) cout << "Paciente adicionado no pontuario com sucesso!" << endl;
    else cout << "Paciente nao adicionado no pontuario! Pontuario cheio." << endl;
}

void imprimirPontuario(Paciente pontuario[], int tam) {
    cout << "Imprimindo pontuario medico..." << endl;
    int imprimiu = 0;

    for(int i = 0; i < tam; i++) {
        if(pontuario[i].identificador != -1) {
            imprimirPaciente(pontuario[i]);
            imprimiu = 1;
        }
    }
    if(imprimiu == 0) cout << "Pontuario medico vazio! Adicione um paciente." << endl;
}

void editarPacienteNome(Paciente pontuario[], int tam, string editarNome) {
    int editou = 0;

    for(int i = 0; i < tam; i++) {
        if(pontuario[i].nome == editarNome) {
            cout << "Digite o novo nome: " << endl;
            cin >> pontuario[i].nome;
            editou = 1;
            break;
        }
    }
    if(editou == 1) cout << "Nome editado com sucesso!" << endl;
    else cout << "Nome nao encontrado no pontuario!" << endl;
}

void editarPacienteAltura(Paciente pontuario[], int tam, string editarAltura) {
    int editou = 0;

    for(int i = 0; i < tam; i++) {
        if(pontuario[i].nome == editarAltura) {
            cout << "Digite a nova altura: " << endl;
            cin >> pontuario[i].altura;
            editou = 1;
            break;
        }
    }
    if(editou == 1) cout << "Altura editada com sucesso!" << endl;
    else cout << "Altura nao encontrada no pontuario!" << endl;
}

void editarPacienteIdade(Paciente pontuario[], int tam, string editarIdade) {
    int editou = 0;

    for(int i = 0; i < tam; i++) {
        if(pontuario[i].nome == editarIdade) {
            cout << "Digite a nova idade: " << endl;
            cin >> pontuario[i].idade;
            editou = 1;
            break;
        }
    }
    if(editou == 1) cout << "Idade editada com sucesso!" << endl;
    else cout << "Idade nao encontrada no pontuario!" << endl;
}

void editarPacientePeso(Paciente pontuario[], int tam, string editarPeso) {
    int editou = 0;

    for(int i = 0; i < tam; i++) {
        if(pontuario[i].nome == editarPeso) {
            cout << "Digite o novo peso: " << endl;
            cin >> pontuario[i].peso;
            editou = 1;
            break;
        }
    }
    if(editou == 1) cout << "Peso editado com sucesso!" << endl;
    else cout << "Peso nao encontrado no pontuario!" << endl;
}

void editarPaciente(Paciente pontuario[], int tam) {
    cout << "Digite o nome do paciente que deseja editar: " << endl;
    string editarNome;
    cin >> editarNome;

    cout << "Digite o que deseja editar: " << endl;
    cout << "Digite 1: Nome." << endl;
    cout << "Digite 2: Altura." << endl;
    cout << "Digite 3: Idade." << endl;
    cout << "Digite 4: Peso." << endl;
    int opcao;
    cin >> opcao;

    switch(opcao) {
        case 1:
            editarPacienteNome(pontuario, tam, editarNome);
            break;
        case 2:
            editarPacienteAltura(pontuario, tam, editarNome);
            break;
        case 3:
            editarPacienteIdade(pontuario, tam, editarNome);
            break;
        case 4:
            editarPacientePeso(pontuario, tam, editarNome);
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
    }
}

void removerPaciente(Paciente pontuario[], int tam) {
    cout << "Digite o nome do paciente que deseja remover: " << endl;
    string removerNome;
    cin >> removerNome;

    int removeu = 0;

    for(int i = 0; i < tam; i++) {
        if(pontuario[i].nome == removerNome) {
            pontuario[i].identificador = -1;
            removeu = 1;
            break;
        }
    }
    if(removeu == 1) cout << "Paciente removido com sucesso!" << endl;
    else cout << "Paciente nao encontrado no pontuario!" << endl;
}

int main() {
    int tam = 10;
    Paciente pontuario[tam];

    for(int i = 0; i < tam; i++) {
        pontuario[i].identificador = -1;
    }

    int opcao = 0;

    while(opcao != 6) {
        cout << "Digite a opcao desejada: " << endl;
        cout << "Digite 1: Adicionar paciente." << endl;
        cout << "Digite 2: Imprimir pontuario." << endl;
        cout << "Digite 3: Editar paciente." << endl;
        cout << "Digite 4: Remover paciente." << endl;
        cout << "Digite 5: Sair." << endl;
        cin >> opcao;

        switch(opcao) {
            case 1:
                adicionarpaciente(pontuario, tam);
                break;
            case 2:
                imprimirPontuario(pontuario, tam);
                break;
            case 3:
                editarPaciente(pontuario, tam);
                break;
            case 4:
                removerPaciente(pontuario, tam);
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    }

    return 0;
}