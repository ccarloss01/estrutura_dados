#ifndef LISTA_FUNC_H
#define LISTA_FUNC_H

#include "pessoa.h"
#include "tipo_de_pet.h"
#include "pet.h"
#include "comando.h"
#include "lista_func.h"

void inserir_final_pessoa(struct pessoa **lista, char codigo[], char nome[], char fone[], char data_nascimento[], char endereco[]);

struct pessoa *buscar_pessoa(struct pessoa *lista, char codigo[]);

void remover_pessoa(struct pessoa **lista, char codigo[]);

void atualizar_pessoa(struct pessoa *lista, char codigo[], char nome[], char fone[], char data_nascimento[], char endereco[]);

void inserir_final_tipo_pet(struct tipo_de_pet **lista, char codigo[], char descricao[]);

struct tipo_de_pet *buscar_tipo_pet(struct tipo_de_pet *lista, char codigo[]);

void remover_tipo_pet(struct tipo_de_pet **lista, char codigo[]);

void atualizar_tipo_pet(struct tipo_de_pet *lista, char codigo[], char descricao[]);

void inserir_final_pet(struct pet **lista, char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]);

struct pet *buscar_pet(struct pet *lista, char codigo[]);

void remover_pet(struct pet **lista, char codigo[]);

void atualizar_pet(struct pet *lista, char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]);

void inserir_final_comando(struct comando **lista, int ordem_exec, char instrucao[]);

void remover_comeco_comando(struct comando **lista);

void separar_comandos(struct comando **lista, struct comando **pessoa, struct comando **tipo_pet, struct comando **pet);

#endif