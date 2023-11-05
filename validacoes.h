#ifndef VALIDACOES_H
#define VALIDACOES_H

#include "cadastro_livro.h"  // Inclua o arquivo de cabeçalho que define a estrutura Livro

// Declaração de funções de validação
int validarLetras(const char *str);
int validarNumeros(const char *str);
int validarPreco(const char *precoStr);
int validarLivro(Livro livro);  // Agora pode usar a estrutura Livro
int validarCPF(const char *cpf);

#endif
