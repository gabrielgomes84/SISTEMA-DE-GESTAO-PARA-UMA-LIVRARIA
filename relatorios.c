#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro_livro.h"
#include "relatorios.h"
#include "registro_vendas.h"
#include "cadastro_cliente.h"

void gerar_relatorio_estoque(FiltroLivro filtroLivro) {
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
        // Se o livro estiver ativo e a categoria contiver o filtro, exiba-o
        if (livro.status == 0 && strstr(livro.categoria, filtroLivro.genero) != NULL) {
            printf("%-25s %-25s %-20s %-10.2f %d\n", livro.titulo, livro.autor, livro.categoria, livro.preco, livro.quantidadeEstoque);
        }
    }

    fclose(arquivo);

    printf("------------------------------------------------------------\n");
    printf("Fim do Relatório. Pressione Enter para retornar...");
    getchar();
}


void gerar_relatorio_vendas(FiltroVenda filtroVenda) {
    FILE *arquivo = fopen("vendas.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    printf("Relatório de Vendas:\n");
    
    Venda vendaAtual;

    int vendasLidas = 0;
    int vendasAtendendoFiltro = 0;

    while (fread(&vendaAtual, sizeof(Venda), 1, arquivo) == 1) {
        vendasLidas++;

        // Verificar se a data informada pelo usuário corresponde à data da venda
        if (strncmp(vendaAtual.data, filtroVenda.data, 8) == 0) {
            vendasAtendendoFiltro++;

            // Imprimir os dados da venda um abaixo do outro
            printf("Cliente: %s\n", vendaAtual.cliente);
            printf("Título: %s\n", vendaAtual.titulo);
            printf("Autor: %s\n", vendaAtual.autor);
            printf("Preço: %.2f\n", vendaAtual.preco);
            printf("Data: %s\n", vendaAtual.data);
            printf("Quantidade: %d\n", vendaAtual.quantidade);

            // Adiciona uma linha em branco entre cada venda
            printf("\n");
        }
    }

    fclose(arquivo);

    printf("Vendas lidas: %-4d\n", vendasLidas);
    printf("Vendas atendendo à condição de data: %-4d\n", vendasAtendendoFiltro);
    printf("Fim do Relatório. Pressione Enter para retornar...");

    getchar(); // Aguarde a tecla Enter
}

void gerar_relatorio_clientes(FiltroCliente filtroCliente) {
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
        if (clientes[i].status == 0 && strcmp(clientes[i].cidade, filtroCliente.cidade) == 0) {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Email: %s\n", clientes[i].email);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Status: Ativo\n");
            printf("-----------------------------------\n");
        }
    }

    fclose(arquivo);
    free(clientes);

    getchar(); // Aguarde a tecla Enter
}

void tela_relatorios(void) {
    system("cls"); // Limpar a tela

    printf("//        = = = = = = = = Relatórios = = = = = = = = =              //\n");
    printf("//        1. Relatório de Livros em Estoque                            //\n");
    printf("//        2. Relatório de Vendas                                        //\n");
    printf("//        3. Relatório de Clientes                                      //\n");
    printf("//        0. Voltar ao menu anterior                                   //\n");
    printf("Escolha a opção desejada: ");

    char opcao;
    scanf(" %c", &opcao);

    switch (opcao) {
        case '1': {
            FiltroLivro filtroLivro;
            printf("Digite o gênero do livro: ");
            while (getchar() != '\n'); // Limpar o buffer antes de ler a entrada
            fgets(filtroLivro.genero, sizeof(filtroLivro.genero), stdin);
            filtroLivro.genero[strcspn(filtroLivro.genero, "\n")] = '\0'; // Remover a quebra de linha
            gerar_relatorio_estoque(filtroLivro);
            break;
        }
case '2': {
    FiltroVenda filtroVenda;
    printf("Digite a data desejada (DDMMAAAA): ");

    // Limpar o buffer antes de ler a entrada
    while (getchar() != '\n');

    // Ler a data
    if (fgets(filtroVenda.data, sizeof(filtroVenda.data), stdin) == NULL) {
        printf("Erro ao ler a data.\n");
        break;
    }

    // Remover a quebra de linha
    filtroVenda.data[strcspn(filtroVenda.data, "\n")] = '\0';

    // Chamar a função
    gerar_relatorio_vendas(filtroVenda);

    // Pausar a execução e aguardar a tecla Enter
    printf("Pressione Enter para retornar...");
    getchar(); // Aguardar a tecla Enter

    break;
}
        case '3': {
            FiltroCliente filtroCliente;
            printf("Digite a cidade: ");
            while (getchar() != '\n'); // Limpar o buffer antes de ler a entrada
            fgets(filtroCliente.cidade, sizeof(filtroCliente.cidade), stdin);
            filtroCliente.cidade[strcspn(filtroCliente.cidade, "\n")] = '\0'; // Remover a quebra de linha
            gerar_relatorio_clientes(filtroCliente);
            break;
        }
        case '0':
            // Voltar ao menu anterior
            break;
        default:
            printf("Opção inválida. Pressione Enter para continuar...");
            while (getchar() != '\n'); // Limpar o buffer antes de ler a entrada
            getchar(); // Aguardar a tecla Enter
            break;
    }
}