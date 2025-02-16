#ifndef ARVORE_FUNC_H
#define ARVORE_FUNC_H

#include "arv_pessoa.h"
#include "pessoa.h"
#include "arv_tipo_de_pet.h"
#include "tipo_de_pet.h"
#include "pet.h"

struct arv_pessoa *inserir_arvore_pessoa_codigo(struct arv_pessoa *raiz, struct pessoa *pessoa);

struct arv_pessoa *inserir_arvore_pessoa_nome(struct arv_pessoa *raiz, struct pessoa *pessoa);

void transf_lista_arvore_pessoa_codigo(struct arv_pessoa **raiz, struct pessoa *lista);

void transf_lista_arvore_pessoa_nome(struct arv_pessoa **raiz, struct pessoa *lista);

void imprimir_pessoa(struct pessoa *pessoa);

void imprimir_arvore_pessoa(struct arv_pessoa *raiz);

struct arv_pessoa *limpar_arvore_pessoa(struct arv_pessoa *raiz);

struct arv_tipo_de_pet *inserir_arvore_tipo_pet_codigo(struct arv_tipo_de_pet *raiz, struct tipo_de_pet *tipo_de_pet);

struct arv_tipo_de_pet *inserir_arvore_tipo_pet_descricao(struct arv_tipo_de_pet *raiz, struct tipo_de_pet *tipo_de_pet);

void transf_lista_arvore_tipo_pet_codigo(struct arv_tipo_de_pet **raiz, struct tipo_de_pet *lista);

void transf_lista_arvore_tipo_pet_descricao(struct arv_tipo_de_pet **raiz, struct tipo_de_pet *lista);

void imprimir_tipo_pet(struct tipo_de_pet *tipo_pet);

void imprimir_arvore_tipo_pet(struct arv_tipo_de_pet *raiz);

struct arv_tipo_de_pet *limpar_arvore_tipo_pet(struct arv_tipo_de_pet *raiz);

struct arv_pet *inserir_arvore_pet_codigo(struct arv_pet *raiz, struct pet *pet);

struct arv_pet *inserir_arvore_pet_nome(struct arv_pet *raiz, struct pet *pet);

void transf_lista_arvore_pet_codigo(struct arv_pet **raiz, struct pet *lista);

void transf_lista_arvore_pet_nome(struct arv_pet **raiz, struct pet *lista);

void imprimir_pet(struct pet *pet);

void imprimir_arvore_pet(struct arv_pet *raiz);

struct arv_pet *limpar_arvore_pet(struct arv_pet *raiz);

void limpar_arvores(struct arv_pet **r_pet, struct arv_tipo_de_pet **r_tipo_pet, struct arv_pessoa **r_pessoa);

#endif