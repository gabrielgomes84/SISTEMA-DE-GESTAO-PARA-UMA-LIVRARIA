#ifndef VALIDACOES_H
#define VALIDACOES_H

#include "cadastro_livro.h"

// Declaração de funções de validação
int validarLetras(const char *str);
int validarNumeros(const char *str);
int validarPreco(const char *precoStr);
int validarLivro(Livro livro);
int validarCPF(const char *cpf);
int validarEmail(const char *email);

#endif
