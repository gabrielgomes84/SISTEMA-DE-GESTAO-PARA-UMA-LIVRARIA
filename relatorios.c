#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "cadastro_livro.h"
#include "relatorios.h"
#include "registro_vendas.h"
#include "cadastro_cliente.h"


void tela_relatorios(void) {
    system("cls");
    printf("//        = = = = = = = = Relatórios = = = = = = = = =              //\n");
    printf("//        1. Relatório de Livros em Estoque                            //\n");
    printf("//        2. Relatório de Vendas                                        //\n");
    printf("//        3. Relatório de Clientes                                      //\n");
    printf("//        0. Voltar ao menu anterior                                   //\n");
    printf("Escolha a opção desejada: ");
    char opcao;
    scanf(" %c", &opcao);
    getchar();

    switch (opcao) {
        case '1':
            gerar_relatorio_estoque();
            break;
        case '2':
            gerar_relatorio_vendas(); // Implementar esta função de relatório
            break;
        case '3':
            gerar_relatorio_clientes(); // Implementar esta função de relatório
            break;
        case '0':
            // Voltar ao menu anterior
            break;
        default:
            printf("Opção inválida. Pressione Enter para continuar...");
            getchar();
            break;
    }
}

void gerar_relatorio_estoque() {
    FILE *arquivo = fopen("livros.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    printf("Relatório de Livros em Estoque:\n");
    printf("%-25s %-25s %-20s %-10s %s\n", "Título", "Autor", "Categoria", "Preço", "Quantidade em Estoque");
    printf("------------------------------------------------------------\n");

    Livro livro;
    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.status == 0) {
            printf("%-25s %-25s %-20s %-10.2f %d\n", livro.titulo, livro.autor, livro.categoria, livro.preco, livro.quantidadeEstoque);
        }
    }

    fclose(arquivo);

    printf("------------------------------------------------------------\n");
    printf("Fim do Relatório. Pressione Enter para retornar...");
    getchar();
}

void gerar_relatorio_vendas() {
    FILE *arquivo = fopen("vendas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    printf("Relatório de Vendas:\n");
    printf("%-10s %-25s %-25s %-25s %-10s %s\n", "ID", "Título", "Autor", "Cliente", "Preço", "Data");
    printf("---------------------------------------------------------------------------------------------------------------------\n");

    Venda vendaAtual;
    while (fscanf(arquivo, "%d;%49[^;];%49[^;];%49[^;];%f\n", &vendaAtual.id, vendaAtual.titulo, vendaAtual.autor, vendaAtual.cliente, &vendaAtual.preco) == 5) {
        printf("%-10d %-25s %-25s %-25s %-10.2f\n", vendaAtual.id, vendaAtual.titulo, vendaAtual.autor, vendaAtual.cliente, vendaAtual.preco);
    }

    fclose(arquivo);

    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("Fim do Relatório. Pressione Enter para retornar...");
    getchar(); // Aguarde a tecla Enter
}

void gerar_relatorio_clientes() {
    FILE *arquivo = fopen("clientes.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    // Contar o número de clientes no arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    int numClientes = tamanhoArquivo / sizeof(Cliente);
    rewind(arquivo);

    // Ler todos os clientes para um array
    Cliente *clientes = malloc(tamanhoArquivo);
    fread(clientes, sizeof(Cliente), numClientes, arquivo);

    // Exibir o relatório ordenado
    printf("Relatório de Clientes:\n");

    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].status == 0) {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Email: %s\n", clientes[i].email);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Status: Ativo\n");
            printf("-----------------------------------\n");
        }
    }

    printf("Fim do Relatório. Pressione Enter para retornar...");

    fclose(arquivo);
    free(clientes);

    getchar(); // Aguarde a tecla Enter
}