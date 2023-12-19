#ifndef REGISTRO_VENDAS_H
#define REGISTRO_VENDAS_H

typedef struct {
    int id;
    char titulo[50];
    char autor[50];
    char cliente[50];
    float preco;
    char data[9]; // Atualizado para o formato DDMMAAAA
    int quantidade;
} Venda;

void limpar_tela(void);
void registrarUmaVenda(void);
void ExcluirPeloID(void);
void ExcluirTodasAsVendas(void);
void tela_registrar_venda(void);





#endif // REGISTRO_VENDAS_H