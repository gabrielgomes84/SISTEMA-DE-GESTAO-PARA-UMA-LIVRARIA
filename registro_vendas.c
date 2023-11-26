#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro_vendas.h"
#include "validacoes.h"

void tela_registrar_venda() {
    int opcao;
    do {
        system("cls");
        printf("= = = = = = Registrar vendas = = = = = = =\n");
        printf("1. Registre uma venda\n");
        printf("2. Excluir uma venda pelo ID\n");
        printf("3. Excluir todas as vendas\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                registrarUmaVenda();
                break;
            case 2:
                ExcluirPeloID();
                break;
            case 3:
                ExcluirTodasAsVendas();
                break;
            case 0:
                return; // Voltar ao menu principal
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void registrarUmaVenda() {
    Venda novaVenda;

    printf("Digite o ID da venda: ");
    scanf("%d", &novaVenda.id);
    limparBuffer(); // Limpar o buffer

    printf("Digite o título do livro: ");
    fgets(novaVenda.titulo, sizeof(novaVenda.titulo), stdin);
    novaVenda.titulo[strcspn(novaVenda.titulo, "\n")] = '\0'; // Remover a quebra de linha

    printf("Digite o autor do livro: ");
    fgets(novaVenda.autor, sizeof(novaVenda.autor), stdin);
    novaVenda.autor[strcspn(novaVenda.autor, "\n")] = '\0'; // Remover a quebra de linha

    printf("Digite o nome do cliente: ");
    fgets(novaVenda.cliente, sizeof(novaVenda.cliente), stdin);
    novaVenda.cliente[strcspn(novaVenda.cliente, "\n")] = '\0'; // Remover a quebra de linha

    printf("Digite o preço do livro: ");
    scanf("%f", &novaVenda.preco);
    limparBuffer(); // Limpar o buffer

    // Solicitar a data sem barras
    printf("Digite a data da venda (DDMMAAAA, sem barras): ");
    scanf("%8s", novaVenda.data);
    limparBuffer(); // Limpar o buffer

    // Alerta ao usuário
    printf("Aviso: Digite a data sem barras (DDMMAAAA).\n");

    printf("Digite a quantidade do livro vendido: ");
    scanf("%d", &novaVenda.quantidade);
    limparBuffer(); // Limpar o buffer

    // Abrir o arquivo para escrita binária (modo "ab" para adicionar ao final)
    FILE *arquivo = fopen("vendas.bin", "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    // Salvar a venda no arquivo
    fwrite(&novaVenda, sizeof(Venda), 1, arquivo);

    // Fechar o arquivo
    fclose(arquivo);

    // Exemplo de como imprimir os dados da venda
    printf("Venda registrada e salva em vendas.bin:\n");
    printf("ID: %d\nTítulo: %s\nAutor: %s\nCliente: %s\nPreço: %.2f\nData: %.8s\nQuantidade: %d\n",
        novaVenda.id, novaVenda.titulo, novaVenda.autor, novaVenda.cliente,
        novaVenda.preco, novaVenda.data, novaVenda.quantidade);

    printf("Pressione Enter para retornar...");
    limparBuffer(); // Aguarda o Enter
}


void ExcluirPeloID() {
    int idExcluir;
    printf("Digite o ID da venda a ser excluída: ");
    scanf("%d", &idExcluir);
    getchar(); // Limpar o buffer

    // Abrir o arquivo para leitura binária e um arquivo temporário para escrita binária
    FILE *arquivo = fopen("vendas.bin", "rb");
    FILE *arquivoTemp = fopen("temp.bin", "wb");

    if (arquivo == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    Venda vendaAtual;

    // Ler as vendas do arquivo, copiando para o arquivo temporário, exceto a que queremos excluir
    while (fread(&vendaAtual, sizeof(Venda), 1, arquivo) == 1) {
        if (vendaAtual.id != idExcluir) {
            fwrite(&vendaAtual, sizeof(Venda), 1, arquivoTemp);
        }
    }

    // Fechar os arquivos
    fclose(arquivo);
    fclose(arquivoTemp);

    // Remover o arquivo original e renomear o temporário
    remove("vendas.bin");
    rename("temp.bin", "vendas.bin");

    printf("Venda excluída com sucesso.\n");
    printf("Pressione Enter para retornar...");
    getchar(); // Aguarda o Enter
}

void ExcluirTodasAsVendas() {
    // Abrir o arquivo para escrita binária (modo "wb" para criar um novo arquivo vazio)
    FILE *arquivo = fopen("vendas.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    // Fechar o arquivo para remover todos os registros
    fclose(arquivo);

    printf("Todas as vendas foram excluídas.\n");
    printf("Pressione Enter para retornar...");
    getchar(); // Aguarda o Enter
}
