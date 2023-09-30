#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cadastro_livro.h"
#include "gestao_estoque.h"
#include "registro_vendas.h"
#include "cadastro_cliente.h"
#include "relatorios.h"

// Assinatura das funções
void tela_menu_principal(void);
void tela_cadastrar_livro(void);
void tela_gestao_estoque(void);
void tela_registro_vendas(void);
void tela_cadastrar_cliente(void);
void tela_relatorios(void);

// Função personalizada para limpar a tela
void clear_screen() {
    system("cls"); // Para Windows
}

// Função personalizada para ler um caractere
int my_getchar(void) {
    int c = getchar();
    return c;
}

// Função para mostrar o menu principal
void tela_menu_principal(void) {
    char op;
    clear_screen(); // Limpar a tela
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = Sistema de Gestão para uma Livraria = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastro de Livros e Produtos                               ///\n");
    printf("///            2. Gestão de Estoque                                          ///\n");
    printf("///            3. Registro de Vendas de Livros                               ///\n");
    printf("///            4. Cadastro de Clientes                                       ///\n");
    printf("///            5. Relatórios                                                 ///\n");
    printf("///            0. Sair                                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf(" %c", &op);
    getchar();
    if (op >= '0' && op <= '5') {
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
        }
    } else {
        printf("Opção inválida. Pressione Enter para continuar...");
        getchar();
    }
}

// Resto do seu código

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    setlocale(LC_ALL, "Portuguese");
    char op; // Declare a variável op

    do {
        tela_menu_principal();
    } while (op != '0');
    
    return 0;
}
