#ifndef CADASTRO_LIVRO_H
#define CADASTRO_LIVRO_H

typedef struct {
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
void excluirLivroLogicoPorTitulo(void); // Função para exclusão lógica por título
void excluirLivroFisico(void); // Função para exclusão física de todos os livros
void recuperarLivroExcluido(void); // Função para recuperar livro excluído logicamente
void tela_cadastrar_livro_pesquisar(void);

int validarLetras(const char *str);
int validarNumeros(const char *str);
int validarPreco(const char *preco);
int validarLivro(Livro livro);

void salvarLivroBinario(Livro livro); // Função para salvar livros em formato binário
void carregarLivrosBinario(void); // Função para carregar livros a partir de arquivos binários

#endif
