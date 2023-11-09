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
    cliente.nome[strcspn(cliente.nome, "\n")] = 0; // Remover a quebra de linha
    if (!validarLetras(cliente.nome)) {
        int opcao;
        printf("Nome inválido. Deseja tentar novamente? (1 para sim, 0 para voltar ao menu principal): ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        if (opcao == 1) {
            cadastrarCliente();
        } else {
            return; // Voltar ao menu principal
        }
    }
    printf("E-mail: ");
    fgets(cliente.email, sizeof(cliente.email), stdin);
    cliente.email[strcspn(cliente.email, "\n")] = 0; // Remover a quebra de linha

    // Validar email
    if (!validarEmail(cliente.email)) {
        int opcao;
        printf("E-mail inválido. Deseja tentar novamente? (1 para sim, 0 para voltar ao menu principal): ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        if (opcao == 1) {
            cadastrarCliente();
        } else {
            return; // Voltar ao menu principal
        }
    }

    printf("Telefone: ");
    fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
    cliente.telefone[strcspn(cliente.telefone, "\n")] = 0;
     if (!validarNumeros(cliente.telefone)) {
        int opcao;
        printf("Telefone inválido. Deseja tentar novamente? (1 para sim, 0 para voltar ao menu principal): ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        if (opcao == 1) {
            cadastrarCliente();
        } else {
            return; // Voltar ao menu principal
        }
    }
    printf("CPF: ");
    fgets(cliente.cpf, sizeof(cliente.cpf), stdin);
    cliente.cpf[strcspn(cliente.cpf, "\n")] = 0;
    if (!validarCPF(cliente.cpf)) {
        int opcao;
        printf("CPF inválido. Deseja tentar novamente? (1 para sim, 0 para voltar ao menu principal): ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        if (opcao == 1) {
            cadastrarCliente();
        } else {
            return; // Voltar ao menu principal
        }
    }

    cliente.status = 0; // Define o status como 0 para um novo cliente ativo

    salvarCliente(cliente); // Salva os dados do cliente em um arquivo

    printf("Cliente cadastrado com sucesso!\n");
    printf("Pressione Enter para voltar ao menu principal...");
    getchar();
}

void tela_cadastrar_cliente() {
    int opcao;
    do {
        system("cls");
        printf("= = = = = = Cadastrar Cliente = = = = = = =\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Editar cliente\n");
        printf("3. Excluir cliente logicamente\n");
        printf("4. Excluir todos os clientes fisicamente\n");
        printf("5. Recuperar cliente\n");
        printf("6. Pesquisar cliente\n");
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
                excluirClienteLogicoPorCPF();
                break;
            case 4:
                excluirClienteFisico();
                break;
            case 5:
                recuperarClientePorCPF();
                break;
            case 6:
                tela_cadastrar_cliente_pesquisar();
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
    printf("= = = = = = Editar Cliente = = = = = = =\n");

    char cpf[15];
    printf("Digite o CPF do cliente a ser editado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0; // Remover a quebra de linha

    // Validar CPF
    if (!validarCPF(cpf)) {
        int opcao;
        printf("CPF inválido. Deseja tentar novamente? (1 para sim, 0 para voltar ao menu principal): ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        if (opcao == 1) {
            tela_cadastrar_cliente_editar();
        } else {
            return; // Voltar ao menu principal
        }
    }

    if (editarClientePorCPF(cpf)) {
        printf("Cliente editado com sucesso!\n");
    } else {
        printf("Cliente não encontrado.\n");
    }

    printf("Pressione Enter para retornar...");
    getchar();
}

void tela_cadastrar_cliente_pesquisar() {
    system("cls");
    printf("= = = = = = Pesquisar Cliente = = = = = = =\n");

    char cpf[15];
    printf("Digite o CPF do cliente a ser pesquisado: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0; // Remover a quebra de linha

    // Validar CPF
    if (!validarCPF(cpf)) {
        int opcao;
        printf("CPF inválido. Deseja tentar novamente? (1 para sim, 0 para voltar ao menu principal): ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer

        if (opcao == 1) {
            tela_cadastrar_cliente_pesquisar();
        } else {
            return; // Voltar ao menu principal
        }
    }

    if (pesquisarClientePorCPF(cpf)) {
        printf("Pressione Enter para retornar...");
    } else {
        printf("Cliente não encontrado.\nPressione Enter para retornar...");
    }

    getchar();
}


void excluirClienteLogicoPorCPF() {
    char cpf[15];
    printf("Digite o CPF do cliente a ser excluído logicamente: ");
    fgets(cpf, sizeof(cpf), stdin);

    FILE *arquivo = fopen("clientes.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    Cliente cliente;
    int encontrado = 0;

    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            cliente.status = 1; // Define o status como 1 para excluir logicamente
            fseek(arquivo, -sizeof(Cliente), SEEK_CUR); // Volta para a posição do registro
            fwrite(&cliente, sizeof(Cliente), 1, arquivo);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (encontrado) {
        printf("Cliente excluído logicamente com sucesso!\n");
    } else {
        printf("Cliente não encontrado.\n");
    }

    printf("Pressione Enter para retornar...");
    getchar();
}

void excluirClienteFisico() {
    if (remove("clientes.bin") == 0) {
        printf("Todos os clientes foram excluídos fisicamente.\n");
    } else {
        printf("Erro ao excluir os clientes.\n");
    }

    printf("Pressione Enter para retornar...");
    getchar();
}

void recuperarClientePorCPF() {
    char cpf[15];
    printf("Digite o CPF do cliente a ser recuperado: ");
    fgets(cpf, sizeof(cpf), stdin);

    FILE *arquivo = fopen("clientes.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    Cliente cliente;
    int encontrado = 0;

    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            cliente.status = 0; // Define o status como 0 para recuperar o cliente
            fseek(arquivo, -sizeof(Cliente), SEEK_CUR); // Volta para a posição do registro
            fwrite(&cliente, sizeof(Cliente), 1, arquivo);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (encontrado) {
        printf("Cliente recuperado com sucesso!\n");
    } else {
        printf("Cliente não encontrado.\n");
    }

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


int editarClientePorCPF(char cpf[]) {
    FILE *arquivo = fopen("clientes.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return 0;
    }

    Cliente cliente;
    int encontrado = 0;

    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            printf("Novo nome: ");
            fgets(cliente.nome, sizeof(cliente.nome), stdin);
            printf("Novo e-mail: ");
            fgets(cliente.email, sizeof(cliente.email), stdin);
            printf("Novo telefone: ");
            fgets(cliente.telefone, sizeof(cliente.telefone), stdin);

            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(Cliente), 1, arquivo);
            
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    return encontrado;
}

int pesquisarClientePorCPF(char cpf[]) {
    FILE *arquivo = fopen("clientes.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return 0;
    }

    Cliente cliente;
    int encontrado = 0;

    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            printf("Nome: %s\n", cliente.nome);
            printf("E-mail: %s\n", cliente.email);
            printf("Telefone: %s\n", cliente.telefone);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    return encontrado;
}