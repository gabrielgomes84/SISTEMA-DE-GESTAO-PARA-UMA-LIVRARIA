#include <stdio.h>
#include <stdlib.h>

// Assinatura da função do menu principal
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
                return; // Voltar ao menu principal
            default:
                puts("Opção inválida. Pressione Enter para continuar...");
                getchar();
        }
    }
}