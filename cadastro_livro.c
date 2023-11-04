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
        printf("3. Excluir Livro (Logicamente)\n");
        printf("4. Excluir Todos os Livros (Fisicamente)\n");
        printf("5. Recuperar Livro Excluído\n");
        printf("6. Pesquisar Livro\n");
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
                excluirLivroLogicoPorTitulo(); // Função para exclusão lógica
                break;
            case '4':
                excluirLivroFisico(); // Função para exclusão física
                break;
            case '5':
                recuperarLivroExcluido(); // Função para recuperar livro excluído logicamente
                break;
            case '6':
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
    } while (1);  // Loop infinito até obter dados válidos

    do {
        printf("Categoria: ");
        scanf(" %[^\n]", novoLivro.categoria);
        if (!validarLetras(novoLivro.categoria)) {
            printf("Categoria inválida. Pressione Enter para continuar...\n");
            getchar();
            continue;
        }
        break;  // ssai do loop se a categoria for válida
    } while (1);  // Loop infinito até obter dados válidos

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
    } while (1);  // Loop infinito até obter dados válidos

    if (validarLivro(novoLivro)) {
        salvarLivroBinario(novoLivro); // Função para salvar o livro em binário
        printf("Livro cadastrado com sucesso!\n");
        printf("Pressione Enter para retornar...");
        getchar(); // Aguarda um Enter para retornar
    } else {
        printf("Dados do livro inválidos. Pressione Enter para retornar...");
        getchar();
    }
}

void excluirLivroLogicoPorTitulo() {
    char titulo[100];
    printf("Digite o título do livro a ser excluído logicamente: ");
    fgets(titulo, sizeof(titulo), stdin);

    int len = strlen(titulo);
    if (len > 0 && titulo[len - 1] == '\n') {
        titulo[len - 1] = '\0';
    }

    FILE *arquivo = fopen("livros.dat", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    Livro livro;
    int encontrado = 0;

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.status == 0 && strcoll(livro.titulo, titulo) == 0) {
            livro.status = 1; // Define o status como 1 para excluir logicamente
            fseek(arquivo, -sizeof(Livro), SEEK_CUR);
            fwrite(&livro, sizeof(Livro), 1, arquivo);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (encontrado) {
        printf("Livro excluído logicamente com sucesso!\n");
    } else {
        printf("Livro não encontrado ou já foi excluído logicamente.\n");
    }

    printf("Pressione Enter para retornar...");
    getchar();
}

void excluirLivroFisico() {
    if (remove("livros.dat") == 0) {
        printf("Todos os livros foram excluídos fisicamente.\n");
    } else {
        printf("Erro ao excluir fisicamente os livros.\n");
    }

    printf("Pressione Enter para retornar...");
    getchar();
}

void recuperarLivroExcluido() {
    char titulo[100];
    printf("Digite o título do livro a ser recuperado: ");
    fgets(titulo, sizeof(titulo), stdin);

    // Remova o caractere de nova linha (se existir) do título
    int len = strlen(titulo);
    if (len > 0 && titulo[len - 1] == '\n') {
        titulo[len - 1] = '\0';
    }

    FILE *arquivo = fopen("livros.dat", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    Livro livro;
    int encontrado = 0;

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (strcasecmp(livro.titulo, titulo) == 0 && livro.status == 1) {
            livro.status = 0; // Define o status como 0 para recuperar o livro
            fseek(arquivo, -sizeof(Livro), SEEK_CUR); // Volta para a posição do registro
            fwrite(&livro, sizeof(Livro), 1, arquivo);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (encontrado) {
        printf("Livro recuperado com sucesso!\n");
    } else {
        printf("Livro não encontrado ou não foi excluído logicamente.\n");
    }

    printf("Pressione Enter para retornar...");
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
