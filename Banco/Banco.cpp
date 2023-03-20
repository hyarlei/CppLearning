#include <iostream> // Biblioteca para entrada e saída de dados
#include <string> // Biblioteca para trabalhar com strings
#include <iomanip> // Biblioteca para formatar a saída de dados

using namespace std;

class Conta
{
    private:
        string conta;
        string nome;
        int numero;
        float saldo;
    public:
        Conta(string nome, string conta, int numero, float saldo);
        void depositar(float valor);
        void sacar(float valor);
        void mostrar();
};

Conta::Conta(string nome, string conta, int numero, float saldo)
{
    this->conta = conta;
    this->nome = nome;
    this->numero = numero;
    this->saldo = saldo;
}

void Conta::depositar(float valor)
{
    if (valor <= 0) {
        cout << "!Valor de depósito invalido!" << endl;
        return;
    }
    saldo += valor;
}

void Conta::sacar(float valor)
{
    if (valor <= 0) {
        cout << "!Valor de saque invalido!" << endl;
        return;
    }
    if (valor > saldo) {
        cout << "!Saldo insuficiente!" << endl;
        return;
    }
    saldo -= valor;
}

void Conta::mostrar()
{
    cout << "--------------------------------" << endl;
    cout << "Conta: " << conta << endl;
    cout << "Nome: " << nome << endl;
    cout << "Numero: " << numero << endl;
    cout << "Saldo: R$ " << fixed << setprecision(2) << saldo << endl;
    cout << "--------------------------------" << endl;
}

int main()
{
    string nome;
    string conta;
    int numero;
    float saldo;

    cout << "Digite o tipo da conta: ";
    getline(cin, conta);

    cout << "Digite o nome do Titular da conta: ";
    getline(cin, nome);

    cout << "Digite o numero da conta: ";
    cin >> numero;

    cout << "Digite o saldo da conta: ";
    cin >> saldo;

    Conta conta1(nome, conta, numero, saldo);
    conta1.mostrar();

    float valor;
    cout << "Digite o valor do deposito: ";
    cin >> valor;
    conta1.depositar(valor);
    conta1.mostrar();

    cout << "Digite o valor do saque: ";
    cin >> valor;
    conta1.sacar(valor);
    conta1.mostrar();

    return 0;
}
