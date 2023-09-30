// cadastro_livro.c
#include <stdio.h>
#include <stdlib.h>
#include "cadastro_livro.h"

void tela_cadastrar_livro(void) {
        system("cls");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = Cadastrar Livro e Produto = = = = = = = =              ///\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Editar Livro\n");
        printf("3. Excluir Livro\n");
        printf("4. Pesquisar Livro\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha a opção desejada: ");
        getchar();}