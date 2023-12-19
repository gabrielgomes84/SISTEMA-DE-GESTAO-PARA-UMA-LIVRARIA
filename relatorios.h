// relatorios.h
#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "registro_vendas.h"
#include "cadastro_livro.h"
#include "cadastro_cliente.h"


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

typedef struct {
    char ordenacao; // 'C' para ordem de cadastramento, 'A' para ordem alfabética
} OpcoesRelatorio;

typedef struct NodoLivro {
    Livro livro;
    struct NodoLivro* proximo;
} NodoLivro;

typedef struct NodoCliente {
    Cliente cliente;
    struct NodoCliente* proximo;
} NodoCliente;

void limpar_tela(void); // Adicione a declaração da função limpar_tela
void tela_relatorios(void);
void gerar_relatorio_estoque(FiltroLivro filtroLivro, OpcoesRelatorio opcoes);
void gerar_relatorio_vendas(FiltroVenda filtroVenda);
void gerar_relatorio_clientes(FiltroCliente filtroCliente, OpcoesRelatorio opcoes);

void liberar_lista_livros(NodoLivro* lista);

#endif // RELATORIOS_H
