#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cadastro_livro.h"
#include "registro_vendas.h"
#include "cadastro_cliente.h"
#include "relatorios.h"
#include <conio.h>

void liberar_lista_livros(NodoLivro* lista) {
    while (lista != NULL) {
        NodoLivro* temp = lista;
        lista = lista->proximo;
        free(temp);
    }
}

void ordenar_lista_livros(NodoLivro** lista, int (*comparador)(const void*, const void*)) {
    int tamanhoLista = 0;
    NodoLivro* atual = *lista;

    while (atual != NULL) {
        tamanhoLista++;
        atual = atual->proximo;
    }

    if (tamanhoLista <= 1) {
        return;  // A lista já está ordenada (ou vazia)
    }

    Livro* arrayLivros = (Livro*)malloc(tamanhoLista * sizeof(Livro));

    // Copiar os livros da lista para o array
    int i = 0;
    atual = *lista;
    while (atual != NULL) {
        arrayLivros[i++] = atual->livro;
        atual = atual->proximo;
    }

    // Ordenar o array usando qsort
    qsort(arrayLivros, tamanhoLista, sizeof(Livro), comparador);

    // Atualizar a lista ordenada
    atual = *lista;
    for (i = 0; i < tamanhoLista; i++) {
        atual->livro = arrayLivros[i];
        atual = atual->proximo;
    }

    free(arrayLivros);
}

int comparar_livros_por_titulo(const void* a, const void* b) {
    setlocale(LC_ALL, "");

    // Converter títulos de multibyte para wide string
    wchar_t titulo_a[100];
    wchar_t titulo_b[100];
    mbstowcs(titulo_a, ((NodoLivro*)a)->livro.titulo, 100);
    mbstowcs(titulo_b, ((NodoLivro*)b)->livro.titulo, 100);

    return wcscoll(titulo_a, titulo_b);
}

void ordenar_lista_clientes(NodoCliente** lista, int (*comparador)(const void*, const void*)) {
    int tamanhoLista = 0;
    NodoCliente* atual = *lista;

    while (atual != NULL) {
        tamanhoLista++;
        atual = atual->proximo;
    }

    if (tamanhoLista <= 1) {
        return;  // A lista já está ordenada (ou vazia)
    }

    Cliente* arrayClientes = (Cliente*)malloc(tamanhoLista * sizeof(Cliente));

    // Copiar os clientes da lista para o array
    int i = 0;
    atual = *lista;
    while (atual != NULL) {
        arrayClientes[i++] = atual->cliente;
        atual = atual->proximo;
    }

    // Ordenar o array usando qsort
    qsort(arrayClientes, tamanhoLista, sizeof(Cliente), comparador);

    // Atualizar a lista ordenada
    atual = *lista;
    for (i = 0; i < tamanhoLista; i++) {
        atual->cliente = arrayClientes[i];
        atual = atual->proximo;
    }

    free(arrayClientes);
}

int comparar_clientes_por_nome(const void* a, const void* b) {
    setlocale(LC_ALL, "");

    // Converter nomes de multibyte para wide string
    wchar_t nome_a[100];
    wchar_t nome_b[100];
    mbstowcs(nome_a, ((NodoCliente*)a)->cliente.nome, 100);
    mbstowcs(nome_b, ((NodoCliente*)b)->cliente.nome, 100);

    return wcscoll(nome_a, nome_b);
}

void gerar_relatorio_estoque(FiltroLivro filtroLivro, OpcoesRelatorio opcoes) {
    FILE* arquivo = fopen("livros.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de livros.\n");
        return;
    }

    NodoLivro* listaLivros = NULL;
    Livro livro;

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        if (livro.status == 0 && strstr(livro.categoria, filtroLivro.genero) != NULL) {
            NodoLivro* novoNodo = (NodoLivro*)malloc(sizeof(NodoLivro));
            novoNodo->livro = livro;
            novoNodo->proximo = listaLivros;
            listaLivros = novoNodo;
        }
    }

    fclose(arquivo);

    if (opcoes.ordenacao == 'A') {
        ordenar_lista_livros(&listaLivros, comparar_livros_por_titulo);
    }

    printf("Relatório de Livros em Estoque:\n");
    printf("%-25s %-25s %-20s %-10s %s\n", "Título", "Autor", "Categoria", "Preço", "Quantidade em Estoque");
    printf("------------------------------------------------------------\n");

    NodoLivro* atual = listaLivros;

    while (atual != NULL) {
        Livro livroAtual = atual->livro;
        printf("%-25s %-25s %-20s %-10.2f %d\n", livroAtual.titulo, livroAtual.autor, livroAtual.categoria, livroAtual.preco, livroAtual.quantidadeEstoque);
        atual = atual->proximo;
    }

    liberar_lista_livros(listaLivros);

    printf("------------------------------------------------------------\n");
    printf("Fim do Relatório. Pressione Enter para retornar...");
    _getch();
}

void gerar_relatorio_vendas(FiltroVenda filtroVenda) {
    FILE* arquivo = fopen("vendas.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    printf("Relatório de Vendas:\n");

    Venda vendaAtual;

    int vendasLidas = 0;
    int vendasAtendendoFiltro = 0;

    while (fread(&vendaAtual, sizeof(Venda), 1, arquivo) == 1) {
        vendasLidas++;

        if (strncmp(vendaAtual.data, filtroVenda.data, 8) == 0) {
            vendasAtendendoFiltro++;

            printf("Cliente: %s\n", vendaAtual.cliente);
            printf("Título: %s\n", vendaAtual.titulo);
            printf("Autor: %s\n", vendaAtual.autor);
            printf("Preço: %.2f\n", vendaAtual.preco);
            printf("Data: %s\n", vendaAtual.data);
            printf("Quantidade: %d\n", vendaAtual.quantidade);

            printf("\n");
        }
    }

    fclose(arquivo);

    printf("Vendas lidas: %-4d\n", vendasLidas);
    printf("Vendas atendendo à condição de data: %-4d\n", vendasAtendendoFiltro);
    printf("Fim do Relatório. Pressione Enter para retornar...");

    _getch();
}

void gerar_relatorio_clientes(FiltroCliente filtroCliente, OpcoesRelatorio opcoes) {
    FILE* arquivo = fopen("clientes.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    int numClientes = tamanhoArquivo / sizeof(Cliente);
    rewind(arquivo);

    Cliente* clientes = malloc(tamanhoArquivo);
    fread(clientes, sizeof(Cliente), numClientes, arquivo);

    NodoCliente* listaClientes = NULL;

    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].status == 0 && strcmp(clientes[i].cidade, filtroCliente.cidade) == 0) {
            NodoCliente* novoNodo = (NodoCliente*)malloc(sizeof(NodoCliente));
            novoNodo->cliente = clientes[i];
            novoNodo->proximo = listaClientes;
            listaClientes = novoNodo;
        }
    }

    fclose(arquivo);

    if (opcoes.ordenacao == 'A') {
        ordenar_lista_clientes(&listaClientes, comparar_clientes_por_nome);
    }

    printf("Relatório de Clientes:\n");

    NodoCliente* atual = listaClientes;

    while (atual != NULL) {
        Cliente clienteAtual = atual->cliente;
        printf("Nome: %s\n", clienteAtual.nome);
        printf("Email: %s\n", clienteAtual.email);
        printf("Telefone: %s\n", clienteAtual.telefone);
        printf("CPF: %s\n", clienteAtual.cpf);
        printf("Status: Ativo\n");
        printf("-----------------------------------\n");

        NodoCliente* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    printf("Fim do Relatório. Pressione Enter para retornar...");
    _getch();
}

void tela_relatorios(void) {
    system("cls"); // Limpar a tela

    printf("//        = = = = = = = = Relatórios = = = = = = = = =              //\n");
    printf("//        1. Relatório de Livros em Estoque                            //\n");
    printf("//        2. Relatório de Vendas                                        //\n");
    printf("//        3. Relatório de Clientes                                      //\n");
    printf("//        0. Voltar ao menu anterior                                   //\n");
    printf("Escolha a opção desejada: ");

    char opcao;
    scanf(" %c", &opcao);

    switch (opcao) {
        case '1': {
            FiltroLivro filtroLivro;
            OpcoesRelatorio opcoes;

            printf("Digite o gênero do livro: ");
            while (getchar() != '\n'); // Limpar o buffer antes de ler a entrada
            fgets(filtroLivro.genero, sizeof(filtroLivro.genero), stdin);
            filtroLivro.genero[strcspn(filtroLivro.genero, "\n")] = '\0'; // Remover a quebra de linha

            printf("Escolha a ordem de exibição (C - Cadastramento, A - Alfabética) MAIÚSCULO: ");
            scanf(" %c", &opcoes.ordenacao);

            gerar_relatorio_estoque(filtroLivro, opcoes);
            break;
        }
        case '2': {
            FiltroVenda filtroVenda;
            printf("Digite a data desejada (DDMMAAAA): ");

            // Limpar o buffer antes de ler a entrada
            while (getchar() != '\n');

            // Ler a data
            if (fgets(filtroVenda.data, sizeof(filtroVenda.data), stdin) == NULL) {
                printf("Erro ao ler a data.\n");
                break;
            }

            // Remover a quebra de linha
            filtroVenda.data[strcspn(filtroVenda.data, "\n")] = '\0';

            // Chamar a função
            gerar_relatorio_vendas(filtroVenda);

            // Pausar a execução e aguardar a tecla Enter
            printf("Pressione Enter para retornar...");
            getchar(); // Aguardar a tecla Enter

            break;
        }
        case '3': {
            FiltroCliente filtroCliente;
            OpcoesRelatorio opcoesClientes;

            printf("Digite a cidade: ");
            while (getchar() != '\n'); // Limpar o buffer antes de ler a entrada
            fgets(filtroCliente.cidade, sizeof(filtroCliente.cidade), stdin);
            filtroCliente.cidade[strcspn(filtroCliente.cidade, "\n")] = '\0'; // Remover a quebra de linha

            printf("Escolha a ordem de exibição (C - Cadastramento, A - Alfabética) MAIÚSCULO:");
            scanf(" %c", &opcoesClientes.ordenacao);

            gerar_relatorio_clientes(filtroCliente, opcoesClientes);
            break;
        }
        case '0':
            // Voltar ao menu anterior
            break;
        default:
            printf("Opção inválida. Pressione Enter para continuar...");
            while (getchar() != '\n'); // Limpar o buffer antes de ler a entrada
            getchar(); // Aguardar a tecla Enter
            break;
    }
}