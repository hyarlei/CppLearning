#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Conta {
private:
    string titular;
    int numero;
    double saldo;

public:
    Conta(string titular, double saldo) {
        this->titular = titular;
        this->saldo = saldo;
        this->numero = rand() % 100000 + 1;
    }

    string getTitular() {
        return this->titular;
    }

    int getNumero() {
        return this->numero;
    }

    double getSaldo() {
        return this->saldo;
    }

    void depositar(double valor) {
        this->saldo += valor;
    }

    bool sacar(double valor) {
        if (this->saldo >= valor) {
            this->saldo -= valor;
            return true;
        } else {
            return false;
        }
    }

    bool transferir(Conta &destino, double valor) {
        if (this->saldo >= valor) {
            this->saldo -= valor;
            destino.depositar(valor);
            return true;
        } else {
            return false;
        }
    }
};

vector<Conta> contas;

void inserirConta() {
    string titular;
    double saldo;

    cout << "Digite o nome do titular da conta: ";
    cin >> titular;

    cout << "Digite o saldo inicial da conta: ";
    cin >> saldo;

    Conta novaConta(titular, saldo);
    contas.push_back(novaConta);

    cout << "Conta criada com sucesso! O numero da conta e " << novaConta.getNumero() << "." << endl;
}

void excluirConta() {
    int numeroConta;
    bool encontrada = false;

    cout << "Digite o numero da conta que deseja excluir: ";
    cin >> numeroConta;

    for (int i = 0; i < contas.size(); i++) {
        if (contas[i].getNumero() == numeroConta) {
            contas.erase(contas.begin() + i);
            encontrada = true;
            cout << "Conta excluida com sucesso!" << endl;
            break;
        }
    }

    if (!encontrada) {
        cout << "Conta nao encontrada." << endl;
    }
}

void realizarDeposito() {
    int numeroConta;
    double valor;
    bool encontrada = false;

    cout << "Digite o numero da conta que deseja depositar: ";
    cin >> numeroConta;

    for (int i = 0; i < contas.size(); i++) {
        if (contas[i].getNumero() == numeroConta) {
            cout << "Digite o valor do deposito: ";
            cin >> valor;
            contas[i].depositar(valor);
            encontrada = true;
            cout << "Deposito realizado com sucesso!" << endl;
            break;
        }
    }

    if (!encontrada) {
        cout << "Conta não encontrada." << endl;
    }
}

void realizarSaque() {
    int numeroConta;
    double valor;
    bool encontrada = false;

    cout << "Digite o número da conta que deseja sacar: ";
    cin >> numeroConta;

    for (int i = 0; i < contas.size(); i++) {
        if (contas[i].getNumero() == numeroConta) {
            cout << "Digite o valor do saque: ";
            cin >> valor;
            if (contas[i].sacar(valor)) {
                encontrada = true;
                cout << "Saque realizado com sucesso!" << endl;
            } else {
                cout << "Saldo insuficiente." << endl;
            }
            break;
        }
    }

    if (!encontrada) {
        cout << "Conta nao encontrada." << endl;
    }
}

void realizarTransferencia() {
    int numeroContaOrigem;
    int numeroContaDestino;
    double valor;
    bool encontradaOrigem = false;
    bool encontradaDestino = false;

    cout << "Digite o numero da conta de origem: ";
    cin >> numeroContaOrigem;

    cout << "Digite o numero da conta de destino: ";
    cin >> numeroContaDestino;

    for (int i = 0; i < contas.size(); i++) {
        if (contas[i].getNumero() == numeroContaOrigem) {
            encontradaOrigem = true;
            for (int j = 0; j < contas.size(); j++) {
                if (contas[j].getNumero() == numeroContaDestino) {
                    encontradaDestino = true;
                    cout << "Digite o valor da transferencia: ";
                    cin >> valor;
                    if (contas[i].transferir(contas[j], valor)) {
                        cout << "Transferencia realizada com sucesso!" << endl;
                    } else {
                        cout << "Saldo insuficiente." << endl;
                    }
                    break;
                }
            }
            break;
        }
    }

    if (!encontradaOrigem) {
        cout << "Conta de origem não encontrada." << endl;
    }

    if (!encontradaDestino) {
        cout << "Conta de destino nao encontrada." << endl;
    }
}

void consultarSaldo() {
    int numeroConta;
    bool encontrada = false;

    cout << "Digite o numero da conta que deseja consultar o saldo: ";
    cin >> numeroConta;

    for (int i = 0; i < contas.size(); i++) {
        if (contas[i].getNumero() == numeroConta) {
            cout << "O saldo da conta e R$ " << contas[i].getSaldo() << "." << endl;
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "Conta não encontrada." << endl;
    }
}

void consultarTitular() {
    int numeroConta;
    bool encontrada = false;

    cout << "Digite o numero da conta que deseja consultar o titular: ";
    cin >> numeroConta;

    for (int i = 0; i < contas.size(); i++) {
        if (contas[i].getNumero() == numeroConta) {
            cout << "O titular da conta e " << contas[i].getTitular() << "." << endl;
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "Conta nao encontrada." << endl;
    }
}

void listarContas() {
    if (contas.size() == 0) {
        cout << "Nao ha contas cadastradas." << endl;
    } else {
        for (int i = 0; i < contas.size(); i++) {
            cout << "Conta " << i + 1 << endl;
            cout << "Numero: " << contas[i].getNumero() << endl;
            cout << "Titular: " << contas[i].getTitular() << endl;
            cout << "Saldo: R$ " << contas[i].getSaldo() << endl;
            cout << endl;
        }
    }
}

int main() {
    int opcao;

    do {
        cout << "1 - Inserir conta" << endl;
        cout << "2 - Excluir conta" << endl;
        cout << "3 - Realizar deposito" << endl;
        cout << "4 - Realizar saque" << endl;
        cout << "5 - Realizar transferencia" << endl;
        cout << "6 - Consultar saldo" << endl;
        cout << "7 - Consultar titular" << endl;
        cout << "8 - Listar contas" << endl;
        cout << "9 - Sair" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserirConta();
                break;
            case 2:
                excluirConta();
                break;
            case 3:
                realizarDeposito();
                break;
            case 4:
                realizarSaque();
                break;
            case 5:
                realizarTransferencia();
                break;
            case 6:
                consultarSaldo();
                break;
            case 7:
                consultarTitular();
                break;
            case 8:
                listarContas();
                break;
            case 9:
                cout << "Obrigado por utilizar o sistema!" << endl;
                break;
            default:
                cout << "Opção invalida." << endl;
        }
    } while (opcao != 9);

    return 0;
}
               
