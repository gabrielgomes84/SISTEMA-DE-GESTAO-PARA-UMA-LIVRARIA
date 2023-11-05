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
                excluirLivroLogicoPorID(); // Função para exclusão lógica
                break;
            case '4':
                excluirLivroFisico(); // Função para exclusão física
                break;
            case '5':
                recuperarLivroExcluidoPorID(); // Função para recuperar livro excluído logicamente
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

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void tela_cadastrar_livro_cadastro(void) {
    system("cls");
    printf("= = = = = = Cadastrar Livro = = = = = = =\n");
    Livro novoLivro;

    printf("Título do livro: ");
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = 0; // Remover a quebra de linha

    printf("Autor: ");
    fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = 0; // Remover a quebra de linha

    printf("Categoria: ");
    fgets(novoLivro.categoria, sizeof(novoLivro.categoria), stdin);
    novoLivro.categoria[strcspn(novoLivro.categoria, "\n")] = 0; // Remover a quebra de linha

    char precoStr[20];
    do {
        printf("Preço: ");
        fgets(precoStr, sizeof(precoStr), stdin);
        precoStr[strcspn(precoStr, "\n")] = 0; // Remover a quebra de linha
        if (validarPreco(precoStr)) {
            novoLivro.preco = atof(precoStr);
            break;
        } else {
            printf("Preço inválido. Pressione Enter para continuar...\n");
            getchar();
        }
    } while (1);

    char quantidadeStr[10];
    do {
        printf("Quantidade em estoque: ");
        fgets(quantidadeStr, sizeof(quantidadeStr), stdin);
        quantidadeStr[strcspn(quantidadeStr, "\n")] = 0; // Remover a quebra de linha
        if (validarNumeros(quantidadeStr)) {
            novoLivro.quantidadeEstoque = atoi(quantidadeStr);
            break;
        } else {
            printf("Quantidade inválida. Pressione Enter para continuar...\n");
            getchar();
        }
    } while (1);

    novoLivro.status = 0; // Define o status como 0 para um novo livro ativo

    do {
        printf("ID do livro: ");
        scanf("%d", &novoLivro.id);
        if (novoLivro.id <= 0) {
            printf("ID inválido. Deve ser um número positivo. Pressione Enter para continuar...\n");
            getchar();
        } else {
            break;
        }
    } while (1);

    if (validarLivro(novoLivro)) {
        salvarLivroBinario(novoLivro);
        printf("Livro cadastrado com sucesso!\n");
    } else {
        printf("Dados do livro inválidos. Livro não cadastrado.\n");
    }
    printf("Pressione Enter para retornar...");
    limparBuffer();
}

void excluirLivroLogicoPorID() {
    int idParaExcluir;
    printf("Digite o ID do livro a ser excluído logicamente: ");
    scanf("%d", &idParaExcluir);
    limparBuffer();

    FILE *arquivo = fopen("livros.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    Livro livro;
    int encontrado = 0;

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.id == idParaExcluir && livro.status == 0) {
            livro.status = 1; // Define o status como 1 para excluir logicamente
            fseek(arquivo, -sizeof(Livro), SEEK_CUR);
            fwrite(&livro, sizeof(Livro), 1, arquivo);
            encontrado = 1;
            printf("Livro com ID %d excluído logicamente.\n", idParaExcluir);
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Livro com ID %d não encontrado ou já foi excluído logicamente.\n", idParaExcluir);
    }

    printf("Pressione Enter para retornar...");
    limparBuffer();
}

void excluirLivroFisico() {
    if (remove("livros.bin") == 0) {
        printf("Todos os livros foram excluídos fisicamente.\n");
    } else {
        printf("Erro ao excluir fisicamente os livros ou o arquivo não existe.\n");
    }

    printf("Pressione Enter para retornar...");
    limparBuffer();
}

void recuperarLivroExcluidoPorID() {
    int idParaRecuperar;
    printf("Digite o ID do livro a ser recuperado: ");
    scanf("%d", &idParaRecuperar);

    FILE *arquivo = fopen("livros.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    Livro livro;
    int encontrado = 0;

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.id == idParaRecuperar && livro.status == 1) {
            livro.status = 0; // Define o status como 0 para recuperar o livro
            fseek(arquivo, -sizeof(Livro), SEEK_CUR);
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
    FILE *arquivo = fopen("livros.bin", "ab");  // Abre o arquivo binário para adicionar ao final
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    fwrite(&livro, sizeof(Livro), 1, arquivo);

    fclose(arquivo);
}

void carregarLivrosBinario(void) {
    FILE *arquivo = fopen("livros.bin", "rb");  // Abre o arquivo binário para leitura
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