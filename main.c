#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "cadastro_cliente.h"
#include "cadastro_livro.h"
#include "registro_vendas.h"
#include "relatorios.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    while (1) {
        char op;
        system("cls");
        printf("///////////////////////////////////////////////////////////////////////////\n");
        printf("//                                                                       //\n");
        printf("//        = = = = = = Sistema de Gestão para uma Livraria = = = = = =    //\n");
        printf("//                                                                       //\n");
        printf("//        1. Cadastro de Livros e Produtos                               //\n");
        printf("//        2. Registro de Vendas de Livros                               //\n");
        printf("//        3. Cadastro de Clientes                                       //\n");
        printf("//        4. Relatórios                                                 //\n");
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
                tela_registrar_venda();
                break;
            case '3':
                tela_cadastrar_cliente();
                break;
            case '4':
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

    return 0;
}