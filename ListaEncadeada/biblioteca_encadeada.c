#include "biblioteca_encadeada.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void inicializarBiblioteca(Biblioteca* b) {
    b->primeiro = NULL;
    b->totalLivros = 0;
}

int cadastrarLivro(Biblioteca* b, char* titulo, char* autor, int ano, char* isbn) {
    NoLivro* atual = b->primeiro;

    // Verifica se o livro já existe
    while (atual != NULL) {
        if (strcmp(atual->livro.isbn, isbn) == 0) {
            return 0; // ISBN já cadastrado
        }
        atual = atual->proximo;
    }

    // Aloca e preenche o novo livro
    NoLivro* novo = (NoLivro*)malloc(sizeof(NoLivro));
    if (novo == NULL) return 0;

    strcpy(novo->livro.titulo, titulo);
    strcpy(novo->livro.autor, autor);
    novo->livro.ano = ano;
    strcpy(novo->livro.isbn, isbn);
    novo->livro.status = DISPONIVEL;

    novo->proximo = b->primeiro;
    b->primeiro = novo;
    b->totalLivros++;

    return 1; // Sucesso
}

void listarTodosLivros(Biblioteca* b) {
    NoLivro* atual = b->primeiro;

    while (atual != NULL) {
        printf("Titulo: %s\n", atual->livro.titulo);
        printf("Autor: %s\n", atual->livro.autor);
        printf("Ano: %d\n", atual->livro.ano);
        printf("ISBN: %s\n", atual->livro.isbn);
        printf("Status: %s\n", atual->livro.status == DISPONIVEL ? "Disponivel" : "Emprestado");

        if (atual->livro.status == EMPRESTADO) {
            printf("Emprestado para: %s\n", atual->livro.usuario);
            printf("Data do emprestimo: %s\n", atual->livro.dataEmprestimo);
        }
        printf("---------------------------\n");

        atual = atual->proximo;
    }
}

int emprestarLivro(Biblioteca* b, char* isbn, char* usuario, char* data) {
    NoLivro* atual = b->primeiro;

    while (atual != NULL) {
        if (strcmp(atual->livro.isbn, isbn) == 0) {
            if (atual->livro.status == EMPRESTADO) {
                return 0; // Já está emprestado
            }

            atual->livro.status = EMPRESTADO;
            strcpy(atual->livro.usuario, usuario);
            strcpy(atual->livro.dataEmprestimo, data);

            return 1; // Sucesso
        }
        atual = atual->proximo;
    }

    return 0; // Não encontrado
}

int devolverLivro(Biblioteca* b, char* isbn) {
    NoLivro* atual = b->primeiro;

    while (atual != NULL) {
        if (strcmp(atual->livro.isbn, isbn) == 0) {
            if (atual->livro.status == DISPONIVEL) {
                return 0; // Já está disponível
            }

            atual->livro.status = DISPONIVEL;
            return 1; // Sucesso
        }
        atual = atual->proximo;
    }

    return 0; // Não encontrado
}

NoLivro* consultarLivroPorISBN(Biblioteca* b, char* isbn) {
    NoLivro* atual = b->primeiro;

    while (atual != NULL) {
        if (strcmp(atual->livro.isbn, isbn) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL; // Não encontrado
}

void destruirBiblioteca(Biblioteca* b) {
    NoLivro* atual = b->primeiro;
    NoLivro* temp;

    while (atual != NULL) {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    b->primeiro = NULL;
    b->totalLivros = 0;
}

