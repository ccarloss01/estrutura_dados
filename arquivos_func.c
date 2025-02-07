#include "arquivos_func.h"
#include "pessoa.h"
#include "tipo_de_pet.h"
#include "pet.h"
#include "lista_func.h"

#include <stdio.h>
#include <stdlib.h>

FILE *abrir_arquivo(char path[]) {
    FILE *arquivo = fopen(path, "rb+");
    if (arquivo == NULL) {
        arquivo = fopen(path, "wb+");
        if (arquivo == NULL) {
            exit(-1);
        }
    }

    return arquivo;
}

void ler_arquivo(FILE *arquivo, struct comando **lista) {
    char linha[255];
    while (!feof(arquivo)) {
        fgets(linha, 255, arquivo);
        inserir_final_comando(lista, 0, linha);
    }
}

void armazenar_dados_pessoas(struct pessoa *lista, FILE *f) {

    struct pessoa *aux = lista;

    while (aux != NULL) {
        fseek(f, 0, SEEK_END);
        fwrite(aux, sizeof(struct pessoa), 1, f);
        aux = aux->prox;
    }
}

struct pessoa *ler_dados_pessoas() {
    FILE *arquivo = abrir_arquivo("pessoa.bin");

    fseek(arquivo, 0, SEEK_END);
    int len = ftell(arquivo) / sizeof(struct pessoa);

    struct pessoa pessoas[len];
    fseek(arquivo, 0, SEEK_SET);
    fread(pessoas, sizeof(struct pessoa), len, arquivo);

    struct pessoa *lista = NULL;
    for (int i = 0; i < len; i++) {
        inserir_final_pessoa(&lista,
            pessoas[i].codigo, pessoas[i].nome, pessoas[i].fone, pessoas[i].data_nascimento, pessoas[i].endereco);
    }

    return lista;

}

void armazenar_dados_tipo_pet(struct tipo_de_pet *lista, FILE *f) {

    struct tipo_de_pet *aux = lista;

    while (aux != NULL) {
        fseek(f, 0, SEEK_END);
        fwrite(aux, sizeof(struct tipo_de_pet), 1, f);
        aux = aux->prox;
    }
}

struct tipo_de_pet *ler_dados_tipo_pets() {

    FILE *arquivo = abrir_arquivo("tipo_de_pet.bin");

    fseek(arquivo, 0, SEEK_END);
    int len = ftell(arquivo) / sizeof(struct tipo_de_pet);

    struct tipo_de_pet tipo_de_pets[len];
    fseek(arquivo, 0, SEEK_SET);
    fread(tipo_de_pets, sizeof(struct tipo_de_pet), len, arquivo);

    struct tipo_de_pet *lista = NULL;
    for (int i = 0; i < len; i++) {
        inserir_final_tipo_pet(&lista, tipo_de_pets[i].codigo, tipo_de_pets[i].descricao);
    }

    return lista;

}

void armazenar_dados_pet(struct pet *lista, FILE *f) {

    struct pet *aux = lista;

    while (aux != NULL) {
        fseek(f, 0, SEEK_END);
        fwrite(aux, sizeof(struct pet), 1, f);
        aux = aux->prox;
    }
}

struct pet *ler_dados_pets() {
    FILE *arquivo = abrir_arquivo("pet.bin");

    fseek(arquivo, 0, SEEK_END);
    int len = ftell(arquivo) / sizeof(struct pet);

    struct pet pets[len];
    fseek(arquivo, 0, SEEK_SET);
    fread(pets, sizeof(struct pet), len, arquivo);

    struct pet *lista = NULL;
    for (int i = 0; i < len; i++) {
        inserir_final_pet(&lista, pets[i].codigo, pets[i].nome, pets[i].codigo_tipo, pets[i].codigo_pes);
    }

    return lista;
}

