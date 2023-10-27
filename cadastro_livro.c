#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro_livro.h"
#include "validacoes.h"

void tela_cadastrar_livro(void) {
    char op;
    do {
        system("cls");
        printf("///////////////////////////////////////////////////////////////////////////\n");
        printf("//        = = = = = = = = Cadastrar Livro e Produto = = = = = = = =       //\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Editar Livro\n");
        printf("3. Excluir Livro\n");
        printf("4. Pesquisar Livro\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha a opção desejada: ");
        scanf(" %c", &op);
        getchar();

        switch (op) {
            case '1':
                tela_cadastrar_livro_cadastro();
                break;
            case '2':
                tela_cadastrar_livro_editar();
                break;
            case '3':
                tela_cadastrar_livro_excluir();
                break;
            case '4':
                tela_cadastrar_livro_pesquisar();
                break;
            case '0':
                break;
            default:
                printf("Opção inválida. Pressione Enter para continuar...");
                getchar();
                break;
        }
    } while (op != '0');
}

void tela_cadastrar_livro_cadastro(void) {
    system("cls");
    printf("//            = = = = = = = = Cadastrar Livro = = = = = = = = =              //\n");

    Livro novoLivro;
    int valido = 1;

    do {
        printf("Título do livro: ");
        scanf(" %[^\n]", novoLivro.titulo);
        if (!validarLetras(novoLivro.titulo)) {
            printf("Título inválido. Pressione Enter para continuar...\n");
            getchar();
            continue;
        }
        break;  // Sai do loop se o título for válido

    } while (1);  // Loop infinito até obter dados válidos

    do {
        printf("Autor: ");
        scanf(" %[^\n]", novoLivro.autor);
        if (!validarLetras(novoLivro.autor)) {
            printf("Autor inválido. Pressione Enter para continuar...\n");
            getchar();
            continue;
        }
        break;  // aqui sai do loop se o autor for válido

    } while (1);  // l.oop infinito até obter dados válidos

    do {
        printf("Categoria: ");
        scanf(" %[^\n]", novoLivro.categoria);
        if (!validarLetras(novoLivro.categoria)) {
            printf("Categoria inválida. Pressione Enter para continuar...\n");
            getchar();
            continue;
        }
        break;  // ssai do loop se a categoria for válida

    } while (1);  // loop infinito até obter dados válidos

    char precoStr[20];
    do {
        printf("Preço: ");
        scanf(" %[^\n]", precoStr);
        if (validarPreco(precoStr)) {
            novoLivro.preco = atof(precoStr);
            break;  // Sai do loop se o preço for válido
        } else {
            printf("Preço inválido. Pressione Enter para continuar...\n");
            getchar();
        }

    } while (1);  // Loop infinito até obter dados válidos

    char quantidadeStr[10];
    do {
        printf("Quantidade em estoque: ");
        scanf(" %[^\n]", quantidadeStr);
        if (validarNumeros(quantidadeStr)) {
            novoLivro.quantidadeEstoque = atoi(quantidadeStr);
            break;  // Sai do loop se a quantidade for válida
        } else {
            printf("Quantidade inválida. Pressione Enter para continuar...\n");
            getchar();
        }

    } while (1);  // loop infinito até obter dados válidos

    if (validarLivro(novoLivro)) {
        salvarLivroBinario(novoLivro);  // aqui chama a função para salvar o livro em binário
        printf("Livro cadastrado com sucesso! Pressione Enter para retornar...");
    } else {
        printf("Dados do livro inválidos. Pressione Enter para retornar...");
    }

    getchar();
}

void salvarLivroBinario(Livro livro) {
    FILE *arquivo = fopen("livros.dat", "ab");  // Abre o arquivo binário para adicionar ao final
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    fwrite(&livro, sizeof(Livro), 1, arquivo);

    fclose(arquivo);
}

void carregarLivrosBinario(void) {
    FILE *arquivo = fopen("livros.dat", "rb");  // Abre o arquivo binário para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    Livro livro;
    while (fread(&livro, sizeof(Livro), 1, arquivo)) {
        // Processar o livro carregado (por exemplo, exibir na tela)
    }

    fclose(arquivo);
}


void tela_cadastrar_livro_editar(void) {
    system("cls");
    printf("//            = = = = = = = = Editar Livro = = = = = = = = =                  //\n");
    printf("Pressione Enter para retornar...");
    getchar();
}

void tela_cadastrar_livro_excluir(void) {
    system("cls");
    printf("//            = = = = = = = = Excluir Livro = = = = = = = = =                  //\n");
    printf("Pressione Enter para retornar...");
    getchar();
}

void tela_cadastrar_livro_pesquisar(void) {
    system("cls");
    printf("//            = = = = = = = = Pesquisar Livro = = = = = = = = =                  //\n");
    printf("Pressione Enter para retornar...");
    getchar();
}
