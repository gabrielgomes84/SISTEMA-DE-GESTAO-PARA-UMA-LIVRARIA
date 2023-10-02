//cadastro_livro.h
#ifndef CADASTRO_LIVRO_H
#define CADASTRO_LIVRO_H

typedef struct {
    char titulo[100];
    char autor[100];
    char categoria[100];
    double preco;
    int quantidadeEstoque;
} Livro;

void tela_cadastrar_livro(void);
void tela_cadastrar_livro_cadastro(void);
void tela_cadastrar_livro_editar(void);
void tela_cadastrar_livro_excluir(void);
void tela_cadastrar_livro_pesquisar(void);

int validarLetras(const char *str);
int validarNumeros(const char *str);
int validarPreco(const char *preco);
int validarLivro(Livro livro);

#endif
