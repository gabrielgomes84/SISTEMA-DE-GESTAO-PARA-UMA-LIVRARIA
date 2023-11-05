#ifndef CADASTRO_LIVRO_H
#define CADASTRO_LIVRO_H

typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    char categoria[100];
    double preco;
    int quantidadeEstoque;
    int status; // Campo para indicar se o registro está excluído (0 para ativo, 1 para excluído logicamente)
} Livro;

void tela_cadastrar_livro(void);
void tela_cadastrar_livro_cadastro(void);
void tela_cadastrar_livro_editar(void);
void excluirLivroLogicoPorID(void);
void excluirLivroFisico(void);
void recuperarLivroExcluidoPorID(void);
void tela_cadastrar_livro_pesquisar(void);
void limparBuffer();

int validarLetras(const char *str);
int validarNumeros(const char *str);
int validarPreco(const char *preco);
int validarLivro(Livro livro);

void salvarLivroBinario(Livro livro);
void carregarLivrosBinario(void);

#endif