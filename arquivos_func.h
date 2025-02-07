#ifndef ARQUIVOS_FUNC_H
#define ARQUIVOS_FUNC_H

#include <stdio.h>

#include "pessoa.h"
#include "tipo_de_pet.h"
#include "pet.h"
#include "comando.h"

FILE *abrir_arquivo(char path[]);

void ler_arquivo(FILE *arquivo, struct comando **lista);

void armazenar_dados_pessoas(struct pessoa *lista, FILE *f);

struct pessoa *ler_dados_pessoas();

void armazenar_dados_tipo_pet(struct tipo_de_pet *lista, FILE *f);

struct tipo_de_pet *ler_dados_tipo_pets();

void armazenar_dados_pet(struct pet *lista, FILE *f);

struct pet *ler_dados_pets();

#endif