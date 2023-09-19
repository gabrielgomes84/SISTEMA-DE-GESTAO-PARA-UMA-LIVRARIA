// cadastro_cliente.c
#include <stdio.h>
#include "cadastro_cliente.h"
#include <stdlib.h>



void tela_cadastrar_cliente(void) {
    system("cls");
    // ...
    printf("///            = = = = = = = = Cadastrar Cliente = = = = = = = = =              ///\n");
    // ...
    printf("///            Nome completo do cliente:                                     ///\n");
    printf("///            E-mail:                                                       ///\n");
    printf("///            Telefone:                                                     ///\n");
    // ...
    printf("\nPressione Enter para voltar ao menu principal...");
    getchar();
}

// Implementação da função para cadastrar um cliente
void cadastrar_cliente(const char *nome, const char *email, const char *telefone) {
    // Lógica para cadastrar o cliente, por exemplo, salvar em um arquivo ou banco de dados
    // ...
    printf("Cliente cadastrado com sucesso!\n");
}

// Outras funções relacionadas ao cadastro de clientes
