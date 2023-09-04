#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Assinatura das funções
void tela_menu_principal(void);
void tela_cadastrar_livro(void);
void tela_gestao_estoque(void);
void tela_registro_vendas(void);
void tela_cadastrar_cliente(void);
void tela_relatorios(void);

// Função personalizada para ler um caractere
int my_getchar(void) {
    int c = getchar();
    return c;
}

// Programa principal
int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    setlocale(LC_ALL, "Portuguese");
    tela_menu_principal();
    return 0;
}

/////
// Funnções
void tela_menu_principal(void) {
    char op;
    while (1) {
        system("clear||cls");
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
                exit(0);
            default:
                puts("Opção inválida. Pressione Enter para continuar...");
                getchar();
        }
    }
}


// Função de cadastro de livros e produtos
void tela_cadastrar_livro(void) {
    system("clear||cls");
    // ...
    printf("///            = = = = = = = = Cadastrar Livro e Produto = = = = = = = =              ///\n");
    // ...
    printf("///            1.Título do livro:                                               ///\n");
    printf("///            2.Autor:                                                        ///\n");
    printf("///            3.Categoria:                                                    ///\n");
    printf("///            4.Preço:                                                        ///\n");
    printf("///            5.Quantidade em estoque:                                        ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Função de gestão de estoque
void tela_gestao_estoque(void) {
    system("clear||cls");
    // ...
    printf("///            = = = = = = = = Gestão de Estoque = = = = = = = = =              ///\n");
    // ...
    printf("///            1.Informe o código do livro/produto:                            ///\n");
    printf("///            2.Nova quantidade em estoque:                                   ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Função de registro de vendas
void tela_registro_vendas(void) {
    system("clear||cls");
    // ...
    printf("///            = = = = = = = = Registro de Vendas de Livros = = = = = = = =              ///\n");
    // ...
    printf("///            1.Informe o código do livro vendido:                            ///\n");
    printf("///            2.Quantidade vendida:                                           ///\n");
    printf("///            3.Valor total da venda:                                         ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Função de cadastro de clientes
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

// Função de relatórios
void tela_relatorios(void) {
    system("clear||cls");
    // ...
    printf("///            = = = = = = = = Relatórios = = = = = = = = =              ///\n");
    // ...
    printf("///            1. Relatório de Livros em Estoque                            ///\n");
    printf("///            2. Relatório de Vendas                                        ///\n");
    printf("///            3. Relatório de Clientes                                      ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}
