#include <stdio.h>

#include "biblioteca_encadeada.h"


int main() {

Biblioteca b;

inicializarBiblioteca(&b);


cadastrarLivro(&b, "Capitaes da Areia", "Jorge Amado", 1937, "3333333333333");

cadastrarLivro(&b, "Dom Casmurro", "Machado de Assis", 1899, "4444444444444");

printf("lista dos livros apos o cadastro:\n");
listarTodosLivros(&b);


emprestarLivro(&b, "3333333333333", "Joao", "04/04/2025");
printf("\n");
printf("lista dos livros apos o emprestimo:\n");
listarTodosLivros(&b);


destruirBiblioteca(&b);

return 0;

}
