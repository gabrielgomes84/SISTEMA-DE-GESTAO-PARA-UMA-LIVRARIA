#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro_vendas.h"
#include "validacoes.h"

void tela_registro_vendas(void) {
    system("cls");
    printf("//        = = = = = = = = Registro de Vendas de Livros = = = = = = = =              //\n");

    Venda novaVenda;

    printf("Título do livro: ");
    fgets(novaVenda.tituloLivro, sizeof(novaVenda.tituloLivro), stdin);
    novaVenda.tituloLivro[strcspn(novaVenda.tituloLivro, "\n")] = 0; // Remova a quebra de linha

    char quantidadeStr[20];
    do {
        printf("Quantidade vendida: ");
        fgets(quantidadeStr, sizeof(quantidadeStr), stdin);
        quantidadeStr[strcspn(quantidadeStr, "\n")] = 0; // Remover a quebra de linha
        if (validarNumeros(quantidadeStr)) {
            novaVenda.quantidade = atoi(quantidadeStr);
            break;
        } else {
            printf("Quantidade inválida. Pressione Enter para continuar...\n");
            getchar();
        }
    } while (1);

    char valorTotalStr[20];
    do {
        printf("Valor total da venda: ");
        fgets(valorTotalStr, sizeof(valorTotalStr), stdin);
        valorTotalStr[strcspn(valorTotalStr, "\n")] = 0; // Remover a quebra de linha
        if (validarPreco(valorTotalStr)) {
            novaVenda.valorTotal = atof(valorTotalStr);
            break;
        } else {
            printf("Valor total inválido. Pressione Enter para continuar...\n");
            getchar();
        }
    } while (1);

    // Agora você tem as informações da venda.

    registrarVenda(novaVenda);

    printf("Venda registrada com sucesso!\n");
    printf("Pressione Enter para voltar ao menu principal...");
    getchar();
}

void registrarVenda(Venda novaVenda) {
    FILE *arquivo = fopen("vendas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    fprintf(arquivo, "Título do livro: %s, Quantidade: %d, Valor Total: %.2f\n", novaVenda.tituloLivro, novaVenda.quantidade, novaVenda.valorTotal);

    fclose(arquivo);
}
