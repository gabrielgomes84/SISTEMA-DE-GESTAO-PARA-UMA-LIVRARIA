// gestao_estoque.h
#ifndef GESTAO_ESTOQUE_H
#define GESTAO_ESTOQUE_H

// Declaração da função para adicionar produtos ao estoque
void adicionar_produto_ao_estoque(int codigo, int quantidade);

// Declaração da função para remover produtos do estoque
void remover_produto_do_estoque(int codigo, int quantidade);

// Declaração da função para calcular a quantidade disponível em estoque
int calcular_quantidade_disponivel(int codigo);

// Outras declarações relacionadas à gestão de estoque

#endif // GESTAO_ESTOQUE_H
