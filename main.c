#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/////
// Assinatura das fun��es
void tela_menu_principal(void);
void tela_cadastrar_livro(void);
void tela_gestao_estoque(void);
void tela_registro_vendas(void);
void tela_cadastrar_cliente(void);
void tela_relatorios(void);

/////
// Programa principal
int main(void) {  setlocale(LC_ALL, "Portuguese_Brazil");
    setlocale(LC_ALL, "Portuguese");
    tela_menu_principal();
    return 0;
}

/////
// Fun��es

// Fun��o de exibi��o do menu principal
void tela_menu_principal(void) {
    char op;
    while (1) {
        system("clear||cls");
        puts("///////////////////////////////////////////////////////////////////////////////");
        puts("///                                                                         ///");
        puts("///            = = = = = = Sistema de Gest�o para uma Livraria = = = = = =    ///");
        puts("///                                                                         ///");
        puts("///            1. Cadastro de Livros e Produtos                               ///");
        puts("///            2. Gest�o de Estoque                                          ///");
        puts("///            3. Registro de Vendas de Livros                               ///");
        puts("///            4. Cadastro de Clientes                                       ///");
        puts("///            5. Relat�rios                                                 ///");
        puts("///            0. Sair                                                       ///");
        puts("///                                                                         ///");
        puts("///            Escolha a op��o desejada: ");
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
                puts("Op��o inv�lida. Pressione Enter para continuar...");
                getchar();
        }
    }
}


// Fun��o de cadastro de livros e produtos
void tela_cadastrar_livro(void) {
    system("clear||cls");
    // ...
    printf("///            = = = = = = = = Cadastrar Livro e Produto = = = = = = = =              ///\n");
    // ...
    printf("///            T�tulo do livro:                                               ///\n");
    printf("///            Autor:                                                        ///\n");
    printf("///            Categoria:                                                    ///\n");
    printf("///            Pre�o:                                                        ///\n");
    printf("///            Quantidade em estoque:                                        ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Fun��o de gest�o de estoque
void tela_gestao_estoque(void) {
    system("clear||cls");
    // ...
    printf("///            = = = = = = = = Gest�o de Estoque = = = = = = = = =              ///\n");
    // ...
    printf("///            Informe o c�digo do livro/produto:                            ///\n");
    printf("///            Nova quantidade em estoque:                                   ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Fun��o de registro de vendas
void tela_registro_vendas(void) {
    system("clear||cls");
    // ...
    printf("///            = = = = = = = = Registro de Vendas de Livros = = = = = = = =              ///\n");
    // ...
    printf("///            Informe o c�digo do livro vendido:                            ///\n");
    printf("///            Quantidade vendida:                                           ///\n");
    printf("///            Valor total da venda:                                         ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Fun��o de cadastro de clientes
void tela_cadastrar_cliente(void) {
    system("clear||cls");
    // ...
    printf("///            = = = = = = = = Cadastrar Cliente = = = = = = = = =              ///\n");
    // ...
    printf("///            Nome completo do cliente:                                     ///\n");
    printf("///            E-mail:                                                       ///\n");
    printf("///            Telefone:                                                     ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Fun��o de relat�rios
void tela_relatorios(void) {
    system("clear||cls");
    // ...
    printf("///            = = = = = = = = Relat�rios = = = = = = = = =              ///\n");
    // ...
    printf("///            1. Relat�rio de Livros em Estoque                            ///\n");
    printf("///            2. Relat�rio de Vendas                                        ///\n");
    printf("///            3. Relat�rio de Clientes                                      ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}
