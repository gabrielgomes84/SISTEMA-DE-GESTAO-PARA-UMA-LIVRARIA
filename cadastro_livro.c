// cadastro_livro.c
#include <stdio.h>
#include <stdlib.h>
#include "cadastro_livro.h"

void tela_menu_principal(void) {
    char op;
    
    while (1) {
        system("cls");
        puts("///////////////////////////////////////////////////////////////////////////////");
        puts("///                                                                         ///");
        puts("///            = = = = = = Sistema de Gestão para uma Livraria = = = = = =    ///");
        puts("///                                                                         ///");
        puts("///            1. Cadastro de Livros e Produtos                               ///");
        puts("///            2. Gestão de Estoque                                          ///");
        puts("///            3. Registro de Vendas de Livros                               ///");
        puts("///            4. Cadastro de Clientes                                       ///");
        puts("///            5. Relatórios                                                 ///");
        puts("///            0. Sair                                                       ///");
        puts("///                                                                         ///");
        puts("///            Escolha a opção desejada: ");
        scanf(" %c", &op);
        getchar();
    }
}

void tela_cadastrar_livro(void) {
    char op;
    
    while (1) {
        system("cls");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = Cadastrar Livro e Produto = = = = = = = =              ///\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Editar Livro\n");
        printf("3. Excluir Livro\n");
        printf("4. Pesquisar Livro\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha a opção desejada: ");
        scanf(" %c", &op);
        getchar();

        switch (op) {
            case '1':
                printf("///            = = = = = = = = Cadastrar Livro e Produto = = = = = = = =              ///\n");
                printf("///            Título do livro:                                               ///\n");
                printf("///            Autor:                                                        ///\n");
                printf("///            Categoria:                                                    ///\n");
                printf("///            Preço:                                                        ///\n");
                printf("///            Quantidade em estoque:                                        ///\n");
                printf("Pressione Enter para retornar...");
                getchar();
                break;
            case '2':
                printf("Editar Livro\n");
                printf("Pressione Enter para retornar...");
                getchar();
                break;
            case '3':
                printf("Excluir Livro\n");
                printf("Pressione Enter para retornar...");
                getchar();
                break;
            case '4':
                printf("Pesquisar Livro\n");
                printf("Pressione Enter para retornar...");
                getchar();
                break;
            case '0':
                return; // Voltar ao menu principal
            default:
                puts("Opção inválida. Pressione Enter para continuar...");
                getchar();
        }
    }
}
