#include <iostream>

struct Pessoa{
    
    int idade;
    std::string nome;

    Pessoa(int idade, std::string nome){
        this->idade = idade;
        this->nome = nome;
    }
};

void envelhecer(Pessoa* e){
    e->idade++;
}

int main(){
    Pessoa* Hyarlei = new Pessoa(18, "Hyarlei");
    envelhecer(Hyarlei);
    std::cout << Hyarlei->idade << std::endl;
}