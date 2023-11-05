#ifndef REGISTRO_VENDAS_H
#define REGISTRO_VENDAS_H

typedef struct {
    char tituloLivro[100];  // Título do livro vendido
    int quantidade;        // Quantidade vendida
    double valorTotal;     // Valor total da venda
} Venda;

void tela_registro_vendas(void);
void registrarVenda(const Venda venda);  // Definição atualizada da função

#endif
