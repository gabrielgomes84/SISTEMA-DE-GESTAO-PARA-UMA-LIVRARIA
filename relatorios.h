// relatorios.h
#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "registro_vendas.h"

typedef struct {
    char genero[50];
} FiltroLivro;

typedef struct {
    char data[9];
} FiltroVenda;

typedef struct {
    char cidade[50];
    char estado[50];
} FiltroCliente;

void tela_relatorios(void);
void gerar_relatorio_estoque(FiltroLivro filtroLivro);
void gerar_relatorio_vendas(FiltroVenda filtroVenda);
void gerar_relatorio_clientes(FiltroCliente filtroCliente);

#endif // RELATORIOS_H
