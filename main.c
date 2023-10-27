#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "cadastro_cliente.h"
#include "cadastro_livro.h"
#include "gestao_estoque.h"
#include "registro_vendas.h"
#include "relatorios.h"

void tela_menu_principal(void) {
    char op;
    system("cls");
    printf("///////////////////////////////////////////////////////////////////////////\n");
    printf("//                                                                       //\n");
    printf("//        = = = = = = Sistema de Gestão para uma Livraria = = = = = =    //\n");
    printf("//                                                                       //\n");
    printf("//        1. Cadastro de Livros e Produtos                               //\n");
    printf("//        2. Gestão de Estoque                                          //\n");
    printf("//        3. Registro de Vendas de Livros                               //\n");
    printf("//        4. Cadastro de Clientes                                       //\n");
    printf("//        5. Relatórios                                                 //\n");
    printf("//        0. Sair                                                       //\n");
    printf("//                                                                       //\n");
    printf("//        Escolha a opção desejada: ");
    scanf(" %c", &op);
    getchar();
    switch (op) {
        case '1':
            tela_cadastrar_livro();
            break;
        case '2':
            tela_gestao_estoque();
            break;
        case '3':
            tela_registro_vendas();
            break;
        case '4':
            tela_cadastrar_cliente();
            break;
        case '5':
            tela_relatorios();
            break;
        case '0':
            exit(0);
        default:
            printf("Opção inválida. Pressione Enter para continuar...");
            getchar();
            break;
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    setlocale(LC_ALL, "Portuguese");
    char op = '1';

    while (op != '0') {
        tela_menu_principal();
    }

    return 0;
}
