#include <stdio.h>
#include <stdlib.h>
#include "registro_vendas.h"

// Estrutura para representar uma venda
typedef struct {
    int codigoLivro;  // Código do livro vendido
    int quantidade;   // Quantidade vendida
    double valorTotal;  // Valor total da venda
} Venda;

void tela_registro_vendas(void) {
    system("cls");
    printf("//        = = = = = = = = Registro de Vendas de Livros = = = = = = = =              //\n");
    printf("//        Informe o código do livro vendido:(Apenas Números)                            //\n");
    printf("//        Quantidade vendida:(Apenas Números)                                           //\n");
    printf("//        Valor total da venda:                                         //\n");
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Função para registrar uma venda no arquivo de texto
void registrarVenda(int codigoLivro, int quantidade, double valorTotal) {
    FILE *arquivo = fopen("vendas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    fprintf(arquivo, "Código do livro: %d, Quantidade: %d, Valor Total: %.2f\n",
            codigoLivro, quantidade, valorTotal);

    fclose(arquivo);
}