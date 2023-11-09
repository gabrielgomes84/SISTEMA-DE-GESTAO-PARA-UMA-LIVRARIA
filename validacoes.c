#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cadastro_livro.h"
#include "cadastro_cliente.h"

int validarLetras(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && !isspace(str[i])) {
            return 0; // Caractere inválido encontrado
        }
    }
    return 1; // Todos os caracteres são válidos
}

int validarNumeros(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // Caractere não é um dígito
        }
    }
    return 1; // Todos os caracteres são dígitos
}

int validarPreco(const char *precoStr) {
    // Verificar se a string contém apenas números e um único ponto (casas decimais)
    int pontos = 0;
    for (int i = 0; precoStr[i] != '\0'; i++) {
        if (!isdigit(precoStr[i])) {
            if (precoStr[i] == '.' && pontos == 0) {
                pontos++;
            } else {
                return 0; // Caractere inválido encontrado
            }
        }
    }
    return (pontos == 1); // Deve ter apenas um ponto (casas decimais)
}

int validarLivro(Livro livro) {
    // Validar se os campos do livro são válidos
    if (strlen(livro.titulo) == 0 || strlen(livro.autor) == 0 || strlen(livro.categoria) == 0 || livro.preco <= 0 || livro.quantidadeEstoque < 0) {
        return 0; // Dados do livro são inválidos
    }
    return 1; // Livro é válido
}


int validarCPF(const char *cpf) {
    int icpf[12];
    int i, somador = 0, digito1, result1, result2, digito2, valor;

    // Efetua a conversão de array de char para um array de int
    for (i = 0; i < 11; i++) {
        icpf[i] = cpf[i] - '0';
    }

    // Primeiro dígito
    for (i = 0; i < 9; i++) {
        somador += icpf[i] * (10 - i);
    }

    result1 = somador % 11;

    if ((result1 == 0) || (result1 == 1)) {
        digito1 = 0;
    } else {
        digito1 = 11 - result1;
    }

    // Segundo dígito
    somador = 0;

    for (i = 0; i < 10; i++) {
        somador += icpf[i] * (11 - i);
    }

    valor = (somador / 11) * 11;
    result2 = somador - valor;

    if ((result2 == 0) || (result2 == 1)) {
        digito2 = 0;
    } else {
        digito2 = 11 - result2;
    }

    // Verificação dos dígitos
    if ((digito1 == icpf[9]) && (digito2 == icpf[10])) {
        return 1; // CPF válido
    } else {
        return 0; // CPF inválido
    }
}

int validarEmail(const char *email) {
    int tam = strlen(email);
    int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

    for (i = 0; i < tam; i++) {
        char c = email[i];
        if (c == '@') {
            if (arroba)
                break; // não pode ter uma segunda @
            arroba = 1;
            if (i < 3)
                break; // se @ vier antes de 3 caracteres, erro
        } else if (arroba) { // se já encontrou @
            if (ponto) { // se já encontrou . depois de @
                depoisPonto++;
            } else if (c == '.') {
                ponto = 1;
                if (antesPonto < 3) {
                    break; // se . depois de @ vier antes de 3 caracteres, erro
                }
            } else {
                antesPonto++;
            }
        }
    } // for

    return (i == tam && depoisPonto > 1);
}