#include <iostream>
#include <string>
#include <vector>

/*

Comandos:

Para executar o programa, digite isso no terminal:
Ex:

g++ main.cpp -o main
./main

*/

using namespace std;

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class Produto
{
public:
    Produto(int id, const string &nome, int quantidade, const string &fabricante) : id(id), nome(nome), quantidade(quantidade), fabricante(fabricante) {}

    /*
    
    Essa linha de código faz parte da definição de função na classe Produto e corresponde a um método de acesso (getter) para o atributo id da classe.

    int é o tipo de retorno da função, indicando que ela retorna um valor inteiro.
    getID() é o nome do método.
    const após a lista de parâmetros indica que esse método não modifica o estado do objeto em que é chamado. Ou seja, ele não altera nenhum dos atributos da classe.
    return id; é a instrução que retorna o valor do atributo id quando o método é chamado. Isso permite que o valor do id seja obtido fora da classe.
    Portanto, quando o método getID() é chamado em um objeto da classe Produto, ele retorna o valor do atributo id desse objeto. Por exemplo:

    cpp
    Copy code
    Produto produto(1, "Produto A", 10, "Fabricante XYZ");
    int idProduto = produto.getID();  // idProduto receberá o valor 1
    Esse método é útil quando se deseja obter o valor de um atributo privado de uma classe sem permitir que ele seja alterado diretamente.
    Em vez disso, o valor é acessado por meio de um método de acesso, garantindo o encapsulamento e a integridade dos dados.
    
    */

    int getID() const
    {
        return id;
    }

    string getNome() const
    {
        return nome;
    }

    int getQuantidade() const
    {
        return quantidade;
    }

    string getFabricante() const
    {
        return fabricante;
    }

    void setNome(const string &novoNome)
    {
        nome = novoNome;
    }

    void setQuantidade(int novaQuantidade)
    {
        quantidade = novaQuantidade;
    }

    void setFabricante(const string &novoFabricante)
    {
        fabricante = novoFabricante;
    }

private:
    int id;
    string nome;
    int quantidade;
    string fabricante;
};

class Inventario
{
public:
    void adicionarProduto(const Produto &produto)
    {
        produtos.push_back(produto);
    }

    void excluirProduto(int id)
    {
        for (auto it = produtos.begin(); it != produtos.end(); ++it)
        {
            if (it->getID() == id)
            {
                produtos.erase(it);
                break;
            }
        }
    }

    void atualizarProduto(int id, const string &novoNome, int novaQuantidade, const string &novoFabricante)
    {
        for (auto &produto : produtos)
        {
            if (produto.getID() == id)
            {
                produto.setNome(novoNome);
                produto.setQuantidade(novaQuantidade);
                produto.setFabricante(novoFabricante);
                break;
            }
        }
    }

    Produto getProdutoPorID(int id) const
    {
        for (const auto &produto : produtos)
        {
            if (produto.getID() == id)
            {
                return produto;
            }
        }
        return Produto(-1, "", -1, ""); // Retornar um produto vazio caso não seja encontrado
    }

    vector<Produto> obterTodosProdutos() const
    {
        return produtos;
    }

private:
    vector<Produto> produtos;
};

int main()
{
    Inventario inventario;

    int escolha = 0;
    while (escolha != 6)
    {
        cout << " ============== MENU ==============" << endl;
        cout << "|   1. Adicionar produto          |" << endl;
        cout << "|   2. Excluir produto            |" << endl;
        cout << "|   3. Atualizar produto          |" << endl;
        cout << "|   4. Consultar produto por ID   |" << endl;
        cout << "|   5. Listar todos os produtos   |" << endl;
        cout << "|   6. Sair                       |" << endl;
        cout << " ==================================" << endl;
        cout << "Digite sua escolha: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
        { // Adicionar produto
            limparTela();
            int id, quantidade;
            string nome, fabricante;

            cout << "Digite o ID do produto: ";
            cin >> id;
            cout << "Digite o nome do produto: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite a quantidade do produto: ";
            cin >> quantidade;
            cout << "Digite o fabricante do produto: ";
            cin.ignore();
            getline(cin, fabricante);

            Produto produto(id, nome, quantidade, fabricante);
            inventario.adicionarProduto(produto);

            limparTela();
            cout << "Produto adicionado com sucesso!" << endl;
            break;
        }
        case 2:
        { // Excluir produto
            limparTela();
            int id;
            cout << "Digite o ID do produto a ser excluído: ";
            cin >> id;
            inventario.excluirProduto(id);

            limparTela();
            cout << "Produto excluído com sucesso!" << endl;
            break;
        }
        case 3:
        { // Atualizar produto
            limparTela();
            int id, novaQuantidade;
            string novoNome, novoFabricante;
            cout << "Digite o ID do produto a ser atualizado: ";
            cin >> id;
            cout << "Digite o novo nome do produto: ";
            cin.ignore();
            getline(cin, novoNome);
            cout << "Digite a nova quantidade do produto: ";
            cin >> novaQuantidade;
            cout << "Digite o novo fabricante do produto: ";
            cin.ignore();
            getline(cin, novoFabricante);
            inventario.atualizarProduto(id, novoNome, novaQuantidade, novoFabricante);

            limparTela();
            cout << "Produto atualizado com sucesso!" << endl;
            break;
        }
        case 4:
        { // Consultar produto por ID
            limparTela();
            int id;
            cout << "Digite o ID do produto a ser consultado: ";
            cin >> id;
            Produto produto = inventario.getProdutoPorID(id);
            if (produto.getID() != -1)
            {
                limparTela();
                cout << "Informações do produto (ID: " << produto.getID() << "):" << endl;
                cout << "Nome: " << produto.getNome() << endl;
                cout << "Quantidade: " << produto.getQuantidade() << endl;
                cout << "Fabricante: " << produto.getFabricante() << endl;
            }
            else
            {
                limparTela();
                cout << "Produto com ID " << id << " não encontrado." << endl;
            }
            break;
        }
        case 5:
        { // Listar todos os produtos
            limparTela();
            vector<Produto> todosProdutos = inventario.obterTodosProdutos();
            cout << "Lista de todos os produtos:" << endl;
            for (const auto &produto : todosProdutos)
            {
                cout << "ID: " << produto.getID() << " | Nome: " << produto.getNome() << " | Quantidade: " << produto.getQuantidade() << " | Fabricante: " << produto.getFabricante() << endl;
            }
            break;
        }
        case 6: // Sair
            limparTela();
            cout << "Encerrando o programa..." << endl;
            break;
        default:
            limparTela();
            cout << "Escolha inválida. Tente novamente." << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}