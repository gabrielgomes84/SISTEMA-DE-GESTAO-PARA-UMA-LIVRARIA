// registro_vendas.c
#include <stdio.h>
#include "registro_vendas.h"
#include <stdlib.h>

void tela_registro_vendas(void) {
    system("cls");
    // ...
    printf("///            = = = = = = = = Registro de Vendas de Livros = = = = = = = =              ///\n");
    // ...
    printf("///            Informe o código do livro vendido:                            ///\n");
    printf("///            Quantidade vendida:                                           ///\n");
    printf("///            Valor total da venda:                                         ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

void registrar_venda(int codigo_livro, int quantidade_vendida, float valor_total) {
    // Lógica para registrar vendas, por exemplo, salvar em um arquivo ou banco de dados
    printf("Venda registrada com sucesso!\n");
}