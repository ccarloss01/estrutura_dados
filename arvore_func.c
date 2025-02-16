#include "arvore_func.h"

#include "arv_pessoa.h"
#include "pessoa.h"
#include "arv_tipo_de_pet.h"
#include "tipo_de_pet.h"
#include "arv_pet.h"
#include "pet.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arv_pessoa *inserir_arvore_pessoa_codigo(struct arv_pessoa *raiz, struct pessoa *pessoa) {
    if (raiz == NULL) {
        struct arv_pessoa *novo = malloc(sizeof(struct arv_pessoa));
        if (novo == NULL) {
            fprintf(stderr, "Erro de alocacao\n");
            exit(EXIT_FAILURE);
        }
        novo->pessoa = pessoa;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }

    if (atoi(pessoa->codigo) > atoi(raiz->pessoa->codigo)) {
        raiz->dir = inserir_arvore_pessoa_codigo(raiz->dir, pessoa);
    } else if (atoi(pessoa->codigo) < atoi(raiz->pessoa->codigo)) {
        raiz->esq = inserir_arvore_pessoa_codigo(raiz->esq, pessoa);
    }

    return raiz;
}

struct arv_pessoa *inserir_arvore_pessoa_nome(struct arv_pessoa *raiz, struct pessoa *pessoa) {
    if (raiz == NULL) {
        struct arv_pessoa *novo = malloc(sizeof(struct arv_pessoa));
        if (novo == NULL) {
            fprintf(stderr, "Erro de alocacao\n");
            exit(EXIT_FAILURE);
        }
        novo->pessoa = pessoa;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }

    if (strcmp(pessoa->nome, raiz->pessoa->nome) > 0) {
        raiz->dir = inserir_arvore_pessoa_nome(raiz->dir, pessoa);
    } else if (strcmp(pessoa->nome, raiz->pessoa->nome) < 0) {
        raiz->esq = inserir_arvore_pessoa_nome(raiz->esq, pessoa);
    }

    return raiz;
}

void transf_lista_arvore_pessoa_codigo(struct arv_pessoa **raiz, struct pessoa *lista) {
    while (lista != NULL) {
        *raiz = inserir_arvore_pessoa_codigo(*raiz, lista);
        lista = lista->prox;
    }
}

void transf_lista_arvore_pessoa_nome(struct arv_pessoa **raiz, struct pessoa *lista) {
    while (lista != NULL) {
        *raiz = inserir_arvore_pessoa_nome(*raiz, lista);
        lista = lista->prox;
    }
}

void imprimir_pessoa(struct pessoa *pessoa) {
    printf("Código: %s", pessoa->codigo);
    printf("\n- %s", pessoa->nome);
    printf("\n- %s", pessoa->fone);
    printf("\n- %s", pessoa->data_nascimento);
    printf("\n- %s\n", pessoa->endereco);
}

void imprimir_arvore_pessoa(struct arv_pessoa *raiz) {
    if (raiz == NULL) {
        return;
    }

    imprimir_arvore_pessoa(raiz->esq);
    imprimir_pessoa(raiz->pessoa);
    imprimir_arvore_pessoa(raiz->dir);
}

struct arv_tipo_de_pet *inserir_arvore_tipo_pet_codigo(struct arv_tipo_de_pet *raiz, struct tipo_de_pet *tipo_de_pet) {
    if (raiz == NULL) {
        struct arv_tipo_de_pet *novo = malloc(sizeof(struct arv_tipo_de_pet));
        if (novo == NULL) {
            fprintf(stderr, "Erro de alocacao\n");
            exit(EXIT_FAILURE);
        }
        novo->tipo_de_pet = tipo_de_pet;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }

    if (atoi(tipo_de_pet->codigo) > atoi(raiz->tipo_de_pet->codigo)) {
        raiz->dir = inserir_arvore_tipo_pet_codigo(raiz->dir, tipo_de_pet);
    } else if (atoi(tipo_de_pet->codigo) < atoi(raiz->tipo_de_pet->codigo)) {
        raiz->esq = inserir_arvore_tipo_pet_codigo(raiz->esq, tipo_de_pet);
    }

    return raiz;
}

struct arv_tipo_de_pet *inserir_arvore_tipo_pet_descricao(struct arv_tipo_de_pet *raiz, struct tipo_de_pet *tipo_de_pet) {
    if (raiz == NULL) {
        struct arv_tipo_de_pet *novo = malloc(sizeof(struct arv_tipo_de_pet));
        if (novo == NULL) {
            fprintf(stderr, "Erro de alocacao\n");
            exit(EXIT_FAILURE);
        }
        novo->tipo_de_pet = tipo_de_pet;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }

    if (strcmp(tipo_de_pet->descricao, raiz->tipo_de_pet->descricao) > 0) {
        raiz->dir = inserir_arvore_tipo_pet_descricao(raiz->dir, tipo_de_pet);
    } else if (strcmp(tipo_de_pet->descricao, raiz->tipo_de_pet->descricao) < 0) {
        raiz->esq = inserir_arvore_tipo_pet_descricao(raiz->esq, tipo_de_pet);
    }

    return raiz;
}

void transf_lista_arvore_tipo_pet_codigo(struct arv_tipo_de_pet **raiz, struct tipo_de_pet *lista) {
    while (lista != NULL) {
        *raiz = inserir_arvore_tipo_pet_codigo(*raiz, lista);
        lista = lista->prox;
    }
}

void transf_lista_arvore_tipo_pet_descricao(struct arv_tipo_de_pet **raiz, struct tipo_de_pet *lista) {
    while (lista != NULL) {
        *raiz = inserir_arvore_tipo_pet_descricao(*raiz, lista);
        lista = lista->prox;
    }
}

void imprimir_tipo_pet(struct tipo_de_pet *tipo_pet) {
    printf("Código: %s", tipo_pet->codigo);
    printf("\n- %s\n", tipo_pet->descricao);
}

void imprimir_arvore_tipo_pet(struct arv_tipo_de_pet *raiz) {
    if (raiz == NULL) {
        return;
    }

    imprimir_arvore_tipo_pet(raiz->esq);
    imprimir_tipo_pet(raiz->tipo_de_pet);
    imprimir_arvore_tipo_pet(raiz->dir);
}

struct arv_pet *inserir_arvore_pet_codigo(struct arv_pet *raiz, struct pet *pet) {
    if (raiz == NULL) {
        struct arv_pet *novo = malloc(sizeof(struct arv_pet));
        if (novo == NULL) {
            fprintf(stderr, "Erro de alocacao\n");
            exit(EXIT_FAILURE);
        }
        novo->pet = pet;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }

    if (atoi(pet->codigo) > atoi(raiz->pet->codigo)) {
        raiz->dir = inserir_arvore_pet_codigo(raiz->dir, pet);
    } else if (atoi(pet->codigo) < atoi(raiz->pet->codigo)) {
        raiz->esq = inserir_arvore_pet_codigo(raiz->esq, pet);
    }

    return raiz;
}

struct arv_pet *inserir_arvore_pet_nome(struct arv_pet *raiz, struct pet *pet) {
    if (raiz == NULL) {
        struct arv_pet *novo = malloc(sizeof(struct arv_pet));
        if (novo == NULL) {
            fprintf(stderr, "Erro de alocacao\n");
            exit(EXIT_FAILURE);
        }
        novo->pet = pet;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }

    if (strcmp(pet->nome, raiz->pet->nome) > 0) {
        raiz->dir = inserir_arvore_pet_nome(raiz->dir, pet);
    } else if (strcmp(pet->nome, raiz->pet->nome) < 0) {
        raiz->esq = inserir_arvore_pet_nome(raiz->esq, pet);
    }

    return raiz;
}

void transf_lista_arvore_pet_codigo(struct arv_pet **raiz, struct pet *lista) {
    while (lista != NULL) {
        *raiz = inserir_arvore_pet_codigo(*raiz, lista);
        lista = lista->prox;
    }
}

void transf_lista_arvore_pet_nome(struct arv_pet **raiz, struct pet *lista) {
    while (lista != NULL) {
        *raiz = inserir_arvore_pet_nome(*raiz, lista);
        lista = lista->prox;
    }
}

void imprimir_pet(struct pet *pet) {
    printf("Código: %s", pet->codigo);
    printf("\n- %s", pet->nome);
    printf("\n- %s", pet->codigo_pes);
    printf("\n- %s\n", pet->codigo_tipo);
}

void imprimir_arvore_pet(struct arv_pet *raiz) {
    if (raiz == NULL) {
        return;
    }

    imprimir_arvore_pet(raiz->esq);
    imprimir_pet(raiz->pet);
    imprimir_arvore_pet(raiz->dir);
}
