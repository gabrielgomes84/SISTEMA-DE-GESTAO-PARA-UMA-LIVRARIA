// cadastro_cliente.h
#ifndef CADASTRO_CLIENTE_H
#define CADASTRO_CLIENTE_H

typedef struct {
    char email[100];
    char cpf[15];
    char nome[100];
    char telefone[20];
    char cidade[50];  // Membro cidade adicionado
    int status; // Campo para indicar se o registro está excluído (0 para ativo, 1 para excluído logicamente)
} Cliente;

void limpar_tela(void);
void tela_cadastrar_cliente();
void tela_cadastrar_cliente_editar();
void tela_cadastrar_cliente_pesquisar();
void salvarCliente(Cliente cliente);
void excluirClienteLogicoPorCPF();
void excluirClienteFisico();
void recuperarClientePorCPF();
int editarClientePorCPF(char cpf[]);
int pesquisarClientePorCPF(char cpf[]);

// Funções de validação
int validarLetras(const char *str);
int validarNumeros(const char *str);
int validarCPF(const char *cpf);
int validarEmail(const char *email);

#endif // CADASTRO_CLIENTE_H