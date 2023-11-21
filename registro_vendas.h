// registro_vendas.h
#ifndef REGISTRO_VENDAS_H
#define REGISTRO_VENDAS_H

typedef struct {
    int id;
    char titulo[50];
    char autor[50];
    char cliente[50];
    float preco;
    char data[11]; // Novo membro adicionado (formato DD/MM/AAAA)
    int quantidade; // Novo membro adicionado
} Venda;

void registrarUmaVenda(void);
void ExcluirPeloID(void);
void ExcluirTodasAsVendas(void);
void tela_registrar_venda(void);

#endif // REGISTRO_VENDAS_H
