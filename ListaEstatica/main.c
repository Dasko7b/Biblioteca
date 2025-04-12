#include <stdio.h>
#include <string.h>
#include "biblioteca_estatica.h"

int main() {
    Biblioteca b;

    // Inicializa a biblioteca
    inicializarBiblioteca(&b);

    // Cadastro de livros
    cadastrarLivro(&b, "O Senhor dos Aneis", "J.R.R. Tolkien", 1954, "123456");
    cadastrarLivro(&b, "Harry Potter", "J.K. Rowling", 1997, "654321");
    cadastrarLivro(&b, "O Hobbit", "J.R.R. Tolkien", 1937, "111222");

    printf("Lista de livros cadastrados:\n");
    listarTodosLivros(&b);

    // Empréstimo de um livro
    if (emprestarLivro(&b, "123456", "Dyego", "10/04/2025")) {
        printf("\nLivro emprestado com sucesso!\n");
    } else {
        printf("\nNao foi possivel emprestar o livro.\n");
    }

    printf("\nLista de livros apos emprestimo:\n");
    listarTodosLivros(&b);

    // Devolução do livro
    if (devolverLivro(&b, "123456")) {
        printf("\nLivro devolvido com sucesso!\n");
    } else {
        printf("\nNao foi possivel devolver o livro.\n");
    }

    printf("\nLista de livros apos devolucao:\n");
    listarTodosLivros(&b);

    // Consulta de um livro por ISBN
    Livro* livro = consultarLivroPorISBN(&b, "654321");
    if (livro != NULL) {
        printf("\nLivro encontrado:\n");
        printf("%s - %s - %d - %s\n", livro->titulo, livro->autor, livro->ano, livro->isbn);
    } else {
        printf("\nLivro nao encontrado!\n");
    }

    printf("\nLista final de livros:\n");
    listarTodosLivros(&b);

    return 0;
}
