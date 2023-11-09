#ifndef REGISTRO_VENDAS_H
#define REGISTRO_VENDAS_H

typedef struct {
    int id;
    char titulo[50];
    char autor[50];
    char cliente[50];
    float preco;
} Venda;

void registrarUmaVenda(void);
void ExcluirPeloID(void);
void ExcluirTodasAsVendas(void);
void tela_registrar_venda(void);

#endif
