#include <iostream>
#include <vector>
#include <string>

/*

Nome: Caio Yuri Cavalcante Soares Ferreira

Comandos:

Para executar o programa, digite isso no terminal:
Ex:

g++ main.cpp -o main
./main

*/

// Função para limpar a tela
void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

// Classe que representa um livro
class Book {
public:
    Book(int id, const std::string& title, const std::string& author)
        : id(id), title(title), author(author) {}

    int getID() const {
        return id;
    }

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

private:
    int id;
    std::string title;
    std::string author;
};

// Classe que representa uma biblioteca
class Library {
public:
    // Adiciona um livro à biblioteca
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Exclui um livro da biblioteca
    void deleteBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getID() == id) {
                books.erase(it);
                break;
            }
        }
    }

    // Atualiza um livro da biblioteca
    void updateBook(int id, const std::string& newTitle, const std::string& newAuthor) {
        for (auto& book : books) {
            if (book.getID() == id) {
                book.setTitle(newTitle);
                book.setAuthor(newAuthor);
                break;
            }
        }
    }

    // Retorna um livro da biblioteca com base no ID
    Book getBookByID(int id) const {
        for (const auto& book : books) {
            if (book.getID() == id) {
                return book;
            }
        }
        return Book(-1, "", ""); // Retornar um livro vazio caso não seja encontrado
    }

    // Retorna todos os livros da biblioteca
    std::vector<Book> getAllBooks() const {
        return books;
    }

private:
    std::vector<Book> books;
};

int main() {
    Library library;

    int choice = 0;
    while (choice != 6) {
        std::cout << " ============== MENU ==============" << std::endl;
        std::cout << "|   1. Adicionar livro            |" << std::endl;
        std::cout << "|   2. Excluir livro              |" << std::endl;
        std::cout << "|   3. Atualizar livro            |" << std::endl;
        std::cout << "|   4. Consultar livro por ID     |" << std::endl;
        std::cout << "|   5. Listar todos os livros     |" << std::endl;
        std::cout << "|   6. Sair                       |" << std::endl;
        std::cout << " ==================================" << std::endl;
        std::cout << "Digite sua escolha: ";
        std::cin >> choice;

        switch (choice) {
            case 1: { // Adicionar livro
                clearScreen();
                int id;
                std::string title, author;

                std::cout << "Digite o ID do livro: ";
                std::cin >> id;
                std::cout << "Digite o título do livro: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Digite o autor do livro: ";
                std::getline(std::cin, author);

                Book book(id, title, author);
                library.addBook(book);

                clearScreen();
                std::cout << "Livro adicionado com sucesso!" << std::endl;
                break;
            }
            case 2: { // Excluir livro
                clearScreen();
                int id;
                std::cout << "Digite o ID do livro a ser excluído: ";
                std::cin >> id;
                library.deleteBook(id);

                clearScreen();
                std::cout << "Livro excluído com sucesso!" << std::endl;
                break;
            }
            case 3: { // Atualizar livro
                clearScreen();
                int id;
                std::string newTitle, newAuthor;
                std::cout << "Digite o ID do livro a ser atualizado: ";
                std::cin >> id;
                std::cout << "Digite o novo título do livro: ";
                std::cin.ignore();
                std::getline(std::cin, newTitle);
                std::cout << "Digite o novo autor do livro: ";
                std::getline(std::cin, newAuthor);
                library.updateBook(id, newTitle, newAuthor);

                clearScreen();
                std::cout << "Livro atualizado com sucesso!" << std::endl;
                break;
            }
            case 4: { // Consultar livro por ID
                clearScreen();
                int id;
                std::cout << "Digite o ID do livro a ser consultado: ";
                std::cin >> id;
                Book book = library.getBookByID(id);
                if (book.getID() != -1) {
                    clearScreen();
                    std::cout << "Informações do livro (ID: " << book.getID() << "):" << std::endl;
                    std::cout << "Título: " << book.getTitle() << std::endl;
                    std::cout << "Autor: " << book.getAuthor() << std::endl;
                } else {
                    clearScreen();
                    std::cout << "Livro com ID " << id << " não encontrado." << std::endl;
                }
                break;
            }
            case 5: { // Listar todos os livros
                clearScreen();
                std::vector<Book> allBooks = library.getAllBooks();
                std::cout << "Lista de todos os livros:" << std::endl;
                for (const auto& book : allBooks) {
                    std::cout << "ID: " << book.getID() << " | Título: " << book.getTitle() << " | Autor: " << book.getAuthor() << std::endl;
                }
                break;
            }
            case 6: // Sair
                clearScreen();
                std::cout << "Encerrando o programa..." << std::endl;
                break;
            default:
                clearScreen();
                std::cout << "Escolha inválida. Tente novamente." << std::endl;
                break;
        }
        std::cout << std::endl;
    }

    return 0;
}
