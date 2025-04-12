#include <stdio.h>

#include "biblioteca_dinamica.h"


int main() {

Biblioteca b;

inicializarBiblioteca(&b);
cadastrarLivro(&b, "A Metamorfose", "Kafka", 1915, "1111111111111");
cadastrarLivro(&b, "O Pequeno Principe", "Saint-Exupery", 1943, "2222222222222");
printf("Lista todos livros:\n");
listarTodosLivros(&b);
emprestarLivro(&b, "1111111111111", "Ana", "04/04/2025");
printf("\n");
printf("Lista todos livros apos o emprestimo:\n");
listarTodosLivros(&b);
destruirBiblioteca(&b);
return 0;

}
