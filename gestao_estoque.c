#include <stdio.h>
#include <stdlib.h>
#include "gestao_estoque.h"

// Estrutura para representar um produto no estoque
typedef struct {
    int codigo;  // Código do produto
    int quantidade;  // quantidade em estoque
} Produto;

void tela_gestao_estoque(void) {
    system("cls");
    printf("//        = = = = = = = = Gestão de Estoque = = = = = = = = = =              //\n");
    printf("//        1. Informe o código do livro/produto:(Apenas Números)                         //\n");
    printf("//        2. Nova quantidade em estoque:(Apenas Números)                                //\n");
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Função para atualizar a quantidade de um produto no estoque
void atualizarEstoque(int codigo, int novaQuantidade) {
    // Abre o arquivo binário para leitura e gravação
    FILE *arquivo = fopen("estoque.bin", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de estoque.\n");
        return;
    }

    Produto produto;
    int encontrado = 0;

    // Lê o arquivo para encontrar o produto com o código informado
    while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
        if (produto.codigo == codigo) {
            produto.quantidade = novaQuantidade;
            encontrado = 1;
            // Volta o ponteiro de leitura/escrita para a posição correta
            fseek(arquivo, -sizeof(Produto), SEEK_CUR);
            // Escreve os dados atualizados no arquivo
            fwrite(&produto, sizeof(Produto), 1, arquivo);
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado no estoque.\n");
    } else {
        printf("Estoque atualizado com sucesso.\n");
    }

    fclose(arquivo);
}

// Função para carregar o estoque do arquivo binário
void carregarEstoque() {
    FILE *arquivo = fopen("estoque.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de estoque não encontrado. Criando novo arquivo.\n");
        // Se o arquivo não existe, ele será criado ao adicionar produtos.
        return;
    }

    Produto produto;

    printf("Estoque carregado:\n");
    while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
        printf("Código: %d, Quantidade: %d\n", produto.codigo, produto.quantidade);
    }

    fclose(arquivo);
}