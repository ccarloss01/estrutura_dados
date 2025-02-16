#ifndef LISTA_FUNC_H
#define LISTA_FUNC_H

#include "pessoa.h"
#include "tipo_de_pet.h"
#include "pet.h"
#include "comando.h"
#include "lista_func.h"
#include "arv_pessoa.h"
#include "arv_tipo_de_pet.h"
#include "arv_pet.h"

void inserir_final_pessoa(struct pessoa **lista, char codigo[], char nome[], char fone[], char data_nascimento[], char endereco[]);

struct pessoa *buscar_pessoa(struct pessoa *lista, char codigo[]);

void remover_pessoa(struct pessoa **lista, struct pet *pet, char codigo[]);

void atualizar_pessoa(struct pessoa *lista, char codigo[], char nome[], char fone[], char data_nascimento[], char endereco[]);

int buscar_pessoa_pet(struct pet *lista, char codigo[]);

void remover_comeco_pessoa(struct pessoa **lista);

void limpar_lista_pessoa(struct pessoa **lista);

void imprimir_lista_pessoa(struct pessoa *l_pessoa);

void inserir_final_tipo_pet(struct tipo_de_pet **lista, char codigo[], char descricao[]);

struct tipo_de_pet *buscar_tipo_pet(struct tipo_de_pet *lista, char codigo[]);

void remover_tipo_pet(struct tipo_de_pet **lista, struct pet *pet, char codigo[]);

void atualizar_tipo_pet(struct tipo_de_pet *lista, char codigo[], char descricao[]);

void remover_comeco_tipo_pet(struct tipo_de_pet **lista);

void limpar_lista_tipo_pet(struct tipo_de_pet **lista);

void imprimir_lista_tipo_pet(struct tipo_de_pet *l_tipo_pet);

void inserir_final_pet(struct pet **lista, struct pessoa *pessoa, struct tipo_de_pet *tipo_pet,
    char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]);

void inserir_final_pet_sem_verificar(struct pet **lista,
    char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]);

int buscar_tipo_pet_pet(struct pet *lista, char codigo[]);

struct pet *buscar_pet(struct pet *lista, char codigo[]);

void remover_pet(struct pet **lista, char codigo[]);

void atualizar_pet(struct pet *lista, char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]);

void remover_comeco_pet(struct pet **lista);

void limpar_lista_pet(struct pet **lista);

void imprimir_lista_pet(struct pet *l_pet);

void inserir_final_comando(struct comando **lista, int ordem_exec, char instrucao[]);

void remover_comeco_comando(struct comando **lista);

void separar_comandos(struct comando **lista, struct comando **pessoa, struct comando **tipo_pet, struct comando **pet);

void limpar_listas(struct pessoa **pessoa, struct tipo_de_pet **tipo_pets, struct pet **pets);

void executar_comando_listas(struct comando **c_pessoa, struct comando **c_tipo_pet, struct comando **c_pet,
    struct pessoa **l_pessoa, struct tipo_de_pet **l_tipo_pet, struct pet **l_pet,
    struct arv_pessoa **a_pessoa, struct arv_tipo_de_pet **a_tipo_pet, struct arv_pet **a_pet);

void remover_comando(struct comando **comandos, struct comando *comando);

void filtrar_comandos(struct comando **comandos);

void executar_insert_pessoa(struct comando *c_pessoa, struct pessoa **l_pessoa);

void executar_insert_tipo_pet(struct comando *c_tipo_pet, struct tipo_de_pet **l_tipo_pet);

void executar_insert_pet(struct comando *c_pet, struct pet **l_pet, struct pessoa *l_pessoa, struct tipo_de_pet *l_tipo_pet);

void executar_select_pessoa(struct comando *c_pessoa, struct pessoa *l_pessoa, struct arv_pessoa **a_pessoa);

void executar_select_tipo_pet(struct comando *c_tipo_pet, struct tipo_de_pet *l_tipo_pet, struct arv_tipo_de_pet **a_tipo_pet);

void executar_select_pet(struct comando *c_pet, struct pet *l_pet, struct arv_pet **a_pet);

void executar_delete_pessoa(struct comando *c_pessoa, struct pessoa **l_pessoa, struct pet *pet);

void executar_delete_tipo_pet(struct comando *c_tipo_pet, struct tipo_de_pet **l_tipo_de_pet, struct pet *pet);

void executar_delete_pet(struct comando *c_pet, struct pet **l_pet);

#endif