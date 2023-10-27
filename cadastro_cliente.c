#include <stdio.h>
#include <stdlib.h>
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

void tela_cadastrar_cliente() {
    int opcao;
    do {
        system("cls");
        printf("= = = = = = Cadastrar Cliente = = = = = = =\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Editar cliente\n");
        printf("3. Excluir cliente\n");
        printf("4. Pesquisar cliente\n");
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
    printf("Pressione Enter para retornar...");
    getchar();
}

void tela_cadastrar_cliente_pesquisar() {
    system("cls");
    printf("// = = = = = = = = Pesquisar Cliente = = = = = = = = =\n");
    printf("Pressione Enter para retornar...");
    getchar();
}

void salvarCliente(Cliente cliente) {
    FILE *arquivo = fopen("clientes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    fprintf(arquivo, "Nome: %sE-mail: %sTelefone: %sCPF: %s\n",
            cliente.nome, cliente.email, cliente.telefone, cliente.cpf);
    
    fclose(arquivo);
}
