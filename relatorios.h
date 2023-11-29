
#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "registro_vendas.h"
#include "cadastro_livro.h"

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

// Definição da estrutura do nó da lista de livros
typedef struct NodoLivro {
    Livro livro;
    struct NodoLivro* proximo;
} NodoLivro;

void tela_relatorios(void);
void gerar_relatorio_estoque(FiltroLivro filtroLivro);
void gerar_relatorio_vendas(FiltroVenda filtroVenda);
void gerar_relatorio_clientes(FiltroCliente filtroCliente);

// Função para liberar a memória da lista dinâmica de livros
void liberar_lista_livros(NodoLivro* lista);

#endif // RELATORIOS_H
