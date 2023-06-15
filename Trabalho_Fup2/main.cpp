#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Função para limpar a tela
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Estrutura para representar um produto
struct Produto {
    int id;
    string nome;
    int quantidade;
    string fabricante;
};

// Função para adicionar um produto ao inventário
void adicionarProduto(vector<Produto>& inventario) {
    int id;
    string nome;
    int quantidade;
    string fabricante;

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

    Produto produto = {id, nome, quantidade, fabricante};
    inventario.push_back(produto);

    limparTela();
    cout << "Produto adicionado com sucesso!" << endl;
}

// Função para excluir um produto do inventário
void excluirProduto(vector<Produto>& inventario, int id) {
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if (it->id == id) {
            inventario.erase(it);
            break;
        }
    }
}

// Função para atualizar um produto do inventário
void atualizarProduto(vector<Produto>& inventario, int id) {
    for (auto& produto : inventario) {
        if (produto.id == id) {
            string novoNome;
            int novaQuantidade;
            string novoFabricante;

            cout << "Digite o novo nome do produto: ";
            cin.ignore();
            getline(cin, novoNome);
            cout << "Digite a nova quantidade do produto: ";
            cin >> novaQuantidade;
            cout << "Digite o novo fabricante do produto: ";
            cin.ignore();
            getline(cin, novoFabricante);

            produto.nome = novoNome;
            produto.quantidade = novaQuantidade;
            produto.fabricante = novoFabricante;

            break;
        }
    }
}

// Função para obter um produto do inventário com base no ID
Produto getProdutoPorID(const vector<Produto>& inventario, int id) {
    for (const auto& produto : inventario) {
        if (produto.id == id) {
            return produto;
        }
    }

    // Retornar um produto vazio caso não seja encontrado
    return { -1, "", -1, "" };
}

// Função para listar todos os produtos do inventário
void listarTodosProdutos(const vector<Produto>& inventario) {
    cout << "Lista de todos os produtos:" << endl;
    for (const auto& produto : inventario) {
        cout << "ID: " << produto.id << " | Nome: " << produto.nome << " | Quantidade: " << produto.quantidade
             << " | Fabricante: " << produto.fabricante << endl;
    }
}

int main() {
    vector<Produto> inventario;

    int escolha = 0;
    while (escolha != 6) {
        limparTela();

        cout << "============= MENU ==============" << endl;
        cout << "|   1. Adicionar produto        |" << endl;
        cout << "|   2. Excluir produto          |" << endl;
        cout << "|   3. Atualizar produto        |" << endl;
        cout << "|   4. Consultar produto por ID |" << endl;
        cout << "|   5. Listar todos os produtos |" << endl;
        cout << "|   6. Sair                     |" << endl;
        cout << "=================================" << endl;
        cout << "Digite sua escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1: {
                adicionarProduto(inventario);
                break;
            }
            case 2: {
                int id;
                cout << "Digite o ID do produto a ser excluído: ";
                cin >> id;
                excluirProduto(inventario, id);
                limparTela();
                cout << "Produto excluído com sucesso!" << endl;
                break;
            }
            case 3: {
                int id;
                cout << "Digite o ID do produto a ser atualizado: ";
                cin >> id;
                atualizarProduto(inventario, id);
                limparTela();
                cout << "Produto atualizado com sucesso!" << endl;
                break;
            }
            case 4: {
                int id;
                cout << "Digite o ID do produto a ser consultado: ";
                cin >> id;
                Produto produto = getProdutoPorID(inventario, id);
                limparTela();
                if (produto.id != -1) {
                    cout << "Informações do produto (ID: " << produto.id << "):" << endl;
                    cout << "Nome: " << produto.nome << endl;
                    cout << "Quantidade: " << produto.quantidade << endl;
                    cout << "Fabricante: " << produto.fabricante << endl;
                } else {
                    cout << "Produto com ID " << id << " não encontrado." << endl;
                }
                break;
            }
            case 5: {
                limparTela();
                listarTodosProdutos(inventario);
                break;
            }
            case 6: {
                limparTela();
                cout << "Encerrando o programa..." << endl;
                break;
            }
            default: {
                limparTela();
                cout << "Escolha inválida. Tente novamente." << endl;
                break;
            }
        }

        cout << endl;
    }

    return 0;
}