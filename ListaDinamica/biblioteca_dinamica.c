#include "biblioteca_dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarBiblioteca(Biblioteca* b) {
    b->livros = (Livro*) malloc(10 * sizeof(Livro));  // Definindo diretamente o valor inicial
    if (b->livros == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    b->capacidade = 10;
    b->totalLivros = 0;
}

void redimensionarBiblioteca(Biblioteca* b, int novaCapacidade) {
    b->livros = (Livro*) realloc(b->livros, novaCapacidade * sizeof(Livro));
    if (b->livros == NULL) {
        printf("Erro ao realocar memória!\n");
        exit(1);
    }
    b->capacidade = novaCapacidade;
}

int cadastrarLivro(Biblioteca* b, char* titulo, char* autor, int ano, char* isbn) {
    int i;
    // Verifica se o livro já está cadastrado
    for (i = 0; i < b->totalLivros; i++) {
        if (strcmp(b->livros[i].isbn, isbn) == 0) {
            return 0;  // Livro já existe
        }
    }

    // Redimensiona a biblioteca se necessário
    if (b->totalLivros == b->capacidade) {
        redimensionarBiblioteca(b, b->capacidade * 2);
    }

    // Preenche os dados do novo livro
    Livro novo;
    strncpy(novo.titulo, titulo, MAX_TITULO - 1);
    novo.titulo[MAX_TITULO - 1] = '\0';  // Garantir que a string seja terminada corretamente

    strncpy(novo.autor, autor, MAX_AUTOR - 1);
    novo.autor[MAX_AUTOR - 1] = '\0';

    novo.ano = ano;

    strncpy(novo.isbn, isbn, MAX_ISBN - 1);
    novo.isbn[MAX_ISBN - 1] = '\0';

    novo.status = DISPONIVEL;
    novo.usuario[0] = '\0';  // Inicializa com string vazia
    novo.dataEmprestimo[0] = '\0';

    b->livros[b->totalLivros] = novo;
    b->totalLivros++;

    return 1;  // Livro cadastrado com sucesso
}

void listarTodosLivros(Biblioteca* b) {
    int i;
    for (i = 0; i < b->totalLivros; i++) {
        Livro l = b->livros[i];
        printf("Titulo: %s\nAutor: %s\nAno: %d\nISBN: %s\nStatus: %s\n", l.titulo, l.autor, l.ano, l.isbn, l.status == DISPONIVEL ? "Disponivel" : "Emprestado");
		printf("\n");
    }
}

int emprestarLivro(Biblioteca* b, char* isbn, char* usuario, char* data) {
    int i;
    for (i = 0; i < b->totalLivros; i++) {
        if (strcmp(b->livros[i].isbn, isbn) == 0) {
            if (b->livros[i].status == DISPONIVEL) {
                b->livros[i].status = EMPRESTADO;
                strncpy(b->livros[i].usuario, usuario, MAX_USUARIO - 1);
                b->livros[i].usuario[MAX_USUARIO - 1] = '\0';
                strncpy(b->livros[i].dataEmprestimo, data, MAX_DATA - 1);
                b->livros[i].dataEmprestimo[MAX_DATA - 1] = '\0';
                return 1;
            } else {
                return 0;  // Livro já emprestado
            }
        }
    }
    return 0;  // Livro não encontrado
}

int devolverLivro(Biblioteca* b, char* isbn) {
    int i;
    for (i = 0; i < b->totalLivros; i++) {
        if (strcmp(b->livros[i].isbn, isbn) == 0) {
            if (b->livros[i].status == EMPRESTADO) {
                b->livros[i].status = DISPONIVEL;
                b->livros[i].usuario[0] = '\0';  // Limpa o usuário
                b->livros[i].dataEmprestimo[0] = '\0';  // Limpa a data de empréstimo
                return 1;
            } else {
                return 0;  // O livro não estava emprestado
            }
        }
    }
    return 0;  // Livro não encontrado
}

Livro* consultarLivroPorISBN(Biblioteca* b, char* isbn) {
    int i;
    for (i = 0; i < b->totalLivros; i++) {
        if (strcmp(b->livros[i].isbn, isbn) == 0) {
            return &b->livros[i];
        }
    }
    return NULL;  // Livro não encontrado
}

void destruirBiblioteca(Biblioteca* b) {
    free(b->livros);
    b->livros = NULL;
    b->capacidade = 0;
    b->totalLivros = 0;
}

