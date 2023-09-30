// gestao_estoque.h
#ifndef GESTAO_ESTOQUE_H
#define GESTAO_ESTOQUE_H

void adicionar_produto_ao_estoque(int codigo, int quantidade);
void remover_produto_do_estoque(int codigo, int quantidade);
int calcular_quantidade_disponivel(int codigo);

#endif // GESTAO_ESTOQUE_H
