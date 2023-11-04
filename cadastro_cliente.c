#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro_cliente.h"

void cadastrarCliente() {
    system("cls");
    printf("= = = = = = Cadastrar Cliente = = = = = = =\n");
    Cliente cliente;

    printf("Nome completo do cliente: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    printf("E-mail: ");
    fgets(cliente.email, sizeof(cliente.email), stdin);
    printf("Telefone: ");
    fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
    printf("CPF: ");
    fgets(cliente.cpf, sizeof(cliente.cpf), stdin);

    salvarCliente(cliente); // Salva os dados do cliente em um arquivo

    printf("Cliente cadastrado com sucesso!\n");
    printf("Pressione Enter para voltar ao menu principal...");
    getchar();
}

void excluirClienteLogicamente(const char* cpf) {
    FILE* arquivo = fopen("clientes.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    Cliente cliente;
    int encontrado = 0;

    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            cliente.status = 1; // Marcando como excluído logicamente
            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(Cliente), 1, arquivo);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (encontrado) {
        printf("Cliente excluído logicamente com sucesso.\n");
    } else {
        printf("Cliente não encontrado.\n");
    }
}

void excluirClientesFisicamente() {
    remove("clientes.bin");
    printf("Todos os clientes foram excluídos fisicamente.\n");
}

void recuperarClientesExcluidos() {
    FILE* arquivo = fopen("clientes.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    Cliente cliente;

    int recuperados = 0;

    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (cliente.status == 1) {
            printf("CPF: %s\n", cliente.cpf);
            printf("Nome: %s\n", cliente.nome);
            printf("Email: %s\n", cliente.email);
            printf("Telefone: %s\n", cliente.telefone);
            
            int opcao;
            printf("Deseja recuperar este cliente? (1 - Sim, 0 - Não): ");
            scanf("%d", &opcao);
            
            if (opcao == 1) {
                cliente.status = 0; // Recuperando o cliente excluído logicamente
                fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
                fwrite(&cliente, sizeof(Cliente), 1, arquivo);
                recuperados++;
            }
        }
    }

    fclose(arquivo);

    if (recuperados > 0) {
        printf("Clientes excluídos logicamente recuperados com sucesso.\n");
    } else {
        printf("Nenhum cliente excluído logicamente foi recuperado.\n");
    }
}
void tela_cadastrar_cliente() {
    int opcao;
    do {
        system("cls");
        printf("= = = = = = Cadastrar Cliente = = = = = = =\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Editar cliente\n");
        printf("3. Excluir cliente\n");
        printf("4. Pesquisar cliente\n");
        printf("5. Recuperar clientes excluídos\n"); // Adicione essa opção
        printf("0. Voltar ao menu principal\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                tela_cadastrar_cliente_editar();
                break;
            case 3:
                tela_cadastrar_cliente_excluir();
                break;
            case 4:
                tela_cadastrar_cliente_pesquisar();
                break;
            case 5:
                recuperarClientesExcluidos(); // Chame a função para recuperar clientes excluídos
                break;
            case 0:
                return; // Voltar ao menu principal
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void tela_cadastrar_cliente_editar() {
    system("cls");
    printf("// = = = = = = = = Editar Cliente = = = = = = = =\n");
    printf("Pressione Enter para retornar...");
    getchar();
}

void tela_cadastrar_cliente_excluir() {
    system("cls");
    printf("// = = = = = = = = Excluir Cliente = = = = = = = =\n");
    printf("1. Excluir logicamente\n");
    printf("2. Excluir fisicamente (todos os dados)\n");
    printf("0. Voltar\n");
    
    int opcao;
    char cpf[15];  // Mova a declaração para o início do bloco
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Limpa o buffer de entrada
    
    switch (opcao) {
        case 1:
            // Excluir logicamente
            printf("Digite o CPF do cliente a ser excluído logicamente: ");
            fgets(cpf, sizeof(cpf), stdin);
            excluirClienteLogicamente(cpf);
            break;
        case 2:
            // Excluir fisicamente
            excluirClientesFisicamente();
            break;
        case 0:
            return; // Voltar
        default:
            printf("Opção inválida. Tente novamente.\n");
    }
}
void tela_cadastrar_cliente_pesquisar() {
    system("cls");
    printf("// = = = = = = = = Pesquisar Cliente = = = = = = = = =\n");
    printf("Pressione Enter para retornar...");
    getchar();
}

void salvarCliente(Cliente cliente) {
    FILE *arquivo = fopen("clientes.bin", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    fwrite(&cliente, sizeof(Cliente), 1, arquivo);

    fclose(arquivo);
}
