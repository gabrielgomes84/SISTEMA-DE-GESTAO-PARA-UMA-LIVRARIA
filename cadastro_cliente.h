#ifndef CADASTRO_CLIENTE_H
#define CADASTRO_CLIENTE_H

typedef struct {
    char email[100];
    char cpf[15];
    char nome[100];
    char telefone[20];
    int status; // 0 para ativo, 1 para excluído logicamente
} Cliente;

void tela_cadastrar_cliente();
void tela_cadastrar_cliente_editar();
void tela_cadastrar_cliente_excluir();
void tela_cadastrar_cliente_pesquisar();
void salvarCliente(Cliente cliente);
void excluirClienteLogicamente(const char* cpf);
void excluirClientesFisicamente();
void recuperarClientesExcluidos();

#endif
