#ifndef CADASTRO_CLIENTE_H
#define CADASTRO_CLIENTE_H

typedef struct {
    char email[100];
    char cpf[15];  // Tamanho típico de um CPF no Brasil
    char nome[100];
} Cliente;

void tela_cadastrar_cliente(void);

int validarEmail(const char *email);
int validarCPF(const char *cpf);
int validarCliente(Cliente cliente);

#endif