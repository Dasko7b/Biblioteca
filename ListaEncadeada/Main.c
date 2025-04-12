#include <stdio.h>

#include "biblioteca_encadeada.h"


int main() {

Biblioteca b;

inicializarBiblioteca(&b);


cadastrarLivro(&b, "Capit�es da Areia", "Jorge Amado", 1937, "3333333333333");

cadastrarLivro(&b, "Dom Casmurro", "Machado de Assis", 1899, "4444444444444");


listarTodosLivros(&b);


emprestarLivro(&b, "3333333333333", "Jo�o", "04/04/2025");

listarTodosLivros(&b);


destruirBiblioteca(&b);

return 0;

}
