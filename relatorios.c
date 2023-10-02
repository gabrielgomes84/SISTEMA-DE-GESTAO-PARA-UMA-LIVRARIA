#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

void tela_relatorios(void) {
    system("cls");
    printf("//        = = = = = = = = Relatórios = = = = = = = = =              //\n");
    printf("//        1. Relatório de Livros em Estoque                            //\n");
    printf("//        2. Relatório de Vendas                                        //\n");
    printf("//        3. Relatório de Clientes                                      //\n");
    printf("//        0. Voltar ao menu anterior                                   //\n");
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

void gerar_relatorio_estoque() {
    // Lógica para gerar e imprimir o relatório de livros em estoque
}

void gerar_relatorio_vendas() {
    // Lógica para gerar e imprimir o relatório de vendas
}

void gerar_relatorio_clientes() {
    // Lógica para gerar e imprimir o relatório de clientes
}
