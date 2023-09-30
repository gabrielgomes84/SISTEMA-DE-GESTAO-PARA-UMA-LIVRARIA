// gestao_estoque.c
#include <stdio.h>
#include "gestao_estoque.h"
#include <stdlib.h>

void tela_gestao_estoque(void) {
    system("cls");
    printf("///            = = = = = = = = Gestão de Estoque = = = = = = = = =              ///\n");
    printf("///            1. Informe o código do livro/produto:                         ///\n");
    printf("///            2. Nova quantidade em estoque:                                ///\n");
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

void adicionar_produto_ao_estoque(int codigo, int quantidade) {
    // Lógica para adicionar produtos ao estoque
}

void remover_produto_do_estoque(int codigo, int quantidade) {
    // Lógica para remover produtos do estoque
}

int calcular_quantidade_disponivel(int codigo) {
    // Lógica para calcular a quantidade disponível em estoque
}
