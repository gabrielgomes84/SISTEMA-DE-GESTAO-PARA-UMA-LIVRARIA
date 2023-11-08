#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Adicione esta linha
#include "cadastro_livro.h"
#include "relatorios.h"
#include "registro_vendas.h"


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

void gerar_relatorio_vendas(){
  // em desenvolvimento
}
void gerar_relatorio_clientes() {
    // Lógica para gerar e imprimir o relatório de clientes
}