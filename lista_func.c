#include "pessoa.h"
#include "tipo_de_pet.h"
#include "pet.h"
#include "comando.h"
#include "lista_func.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Métodos Lista Pessoa
void inserir_final_pessoa(struct pessoa **lista, char codigo[], char nome[], char fone[], char data_nascimento[], char endereco[]) {
    struct pessoa *aux = buscar_pessoa(*lista, codigo);

    if (aux != NULL) {
        return;
    }
    
    struct pessoa *nova_pessoa = malloc(sizeof(struct pessoa));
    strcpy(nova_pessoa->codigo, codigo);
    strcpy(nova_pessoa->nome, nome);
    strcpy(nova_pessoa->fone, fone);
    strcpy(nova_pessoa->data_nascimento, data_nascimento);
    strcpy(nova_pessoa->endereco, endereco);
    nova_pessoa->prox = NULL;

    if (*lista == NULL) {
        *lista = nova_pessoa;
        nova_pessoa->ant = NULL;
        return;
    }

    struct pessoa *ult = *lista;
    while (ult->prox != NULL) {
        ult = ult->prox;
    }

    ult->prox = nova_pessoa;
    nova_pessoa->ant = ult;

}

struct pessoa *buscar_pessoa(struct pessoa *lista, char codigo[]) {

    struct pessoa *aux = lista;
    while(aux && strcmp(aux->codigo, codigo) != 0) {
        aux = aux->prox;
    }

    return aux;

}

void remover_pessoa(struct pessoa **lista, char codigo[]) {
    if(*lista == NULL) {
        return;
    }

    struct pessoa *aux = buscar_pessoa(*lista, codigo);
    if(aux == NULL) {
        return;
    }

    if(aux->ant == NULL) {
        *lista = (*lista)->prox;
        if(*lista) {
            (*lista)->ant = NULL;
        }
    } else {
        aux->ant->prox = aux->prox;
        if(aux->prox) {
            aux->prox->ant = aux->ant;
        }
    }

    free(aux);

}

void atualizar_pessoa(struct pessoa *lista, char codigo[], char nome[], char fone[], char data_nascimento[], char endereco[]) {
    struct pessoa *aux = buscar_pessoa(lista, codigo);

    if(aux == NULL) {
        return;
    }

    strcpy(aux->nome, nome);
    strcpy(aux->fone, fone);
    strcpy(aux->data_nascimento, data_nascimento);
    strcpy(aux->endereco, endereco);

}

// Métodos Lista Tipo de Pet
void inserir_final_tipo_pet(struct tipo_de_pet **lista, char codigo[], char descricao[]) {
    
    struct tipo_de_pet *aux = buscar_tipo_pet(*lista, codigo);

    if (aux != NULL) {
        return;
    }
    
    struct tipo_de_pet *novo_tipo_pet = malloc(sizeof(struct tipo_de_pet));
    strcpy(novo_tipo_pet->codigo, codigo);
    strcpy(novo_tipo_pet->descricao, descricao);
    novo_tipo_pet->prox = NULL;

    if (*lista == NULL) {
        *lista = novo_tipo_pet;
        novo_tipo_pet->ant = NULL;
        return;
    }

    struct tipo_de_pet *ult = *lista;
    while (ult->prox != NULL) {
        ult = ult->prox;
    }

    ult->prox = novo_tipo_pet;
    novo_tipo_pet->ant = ult;
}

struct tipo_de_pet *buscar_tipo_pet(struct tipo_de_pet *lista, char codigo[]) {
    struct tipo_de_pet *aux = lista;
    while(aux && strcmp(aux->codigo, codigo) != 0) {
        aux = aux->prox;
    }

    return aux;
}

void remover_tipo_pet(struct tipo_de_pet **lista, char codigo[]) {
    if(*lista == NULL) {
        return;
    }

    struct tipo_de_pet *aux = buscar_tipo_pet(*lista, codigo);
    if(aux == NULL) {
        return;
    }

    if(aux->ant == NULL) {
        *lista = (*lista)->prox;
        if(*lista) {
            (*lista)->ant = NULL;
        }
    } else {
        aux->ant->prox = aux->prox;
        if(aux->prox) {
            aux->prox->ant = aux->ant;
        }
    }

    free(aux);

}

void atualizar_tipo_pet(struct tipo_de_pet *lista, char codigo[], char descricao[]) {
    struct tipo_de_pet *aux = buscar_tipo_pet(lista, codigo);

    if(aux == NULL) {
        return;
    }

    strcpy(aux->descricao, descricao);
}

// Métodos Lista Pet
void inserir_final_pet(struct pet **lista, char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]) {

    struct pet *aux = buscar_pet(*lista, codigo);

    if (aux != NULL) {
        return;
    }

    struct pet *novo_pet = malloc(sizeof(struct pet));
    strcpy(novo_pet->codigo, codigo);
    strcpy(novo_pet->nome, nome);
    strcpy(novo_pet->codigo_tipo, codigo_tipo);
    strcpy(novo_pet->codigo_pes, codigo_pes);

    novo_pet->prox = NULL;

    if (*lista == NULL) {
        *lista = novo_pet;
        novo_pet->ant = NULL;
        return;
    }

    struct pet *ult = *lista;
    while (ult->prox != NULL) {
        ult = ult->prox;
    }

    ult->prox = novo_pet;
    novo_pet->ant = ult;

}

struct pet *buscar_pet(struct pet *lista, char codigo[]) {
    struct pet *aux = lista;
    while(aux && strcmp(aux->codigo, codigo) != 0) {
        aux = aux->prox;
    }

    return aux;
}

void remover_pet(struct pet **lista, char codigo[]) {
    if(*lista == NULL) {
        return;
    }

    struct pet *aux = buscar_pet(*lista, codigo);
    if(aux == NULL) {
        return;
    }

    if(aux->ant == NULL) {
        *lista = (*lista)->prox;
        if(*lista) {
            (*lista)->ant = NULL;
        }
    } else {
        aux->ant->prox = aux->prox;
        if(aux->prox) {
            aux->prox->ant = aux->ant;
        }
    }

    free(aux);
}

void atualizar_pet(struct pet *lista, char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]) {
    struct pet *aux = buscar_pet(lista, codigo);

    if(aux == NULL) {
        return;
    }

    strcpy(aux->nome, nome);
    strcpy(aux->codigo_tipo, codigo_tipo);
    strcpy(aux->codigo_pes, codigo_pes);
}

// Métodos Lista Comando
void inserir_final_comando(struct comando **lista, int ordem_exec, char instrucao[]) {
    struct comando *novo_comando = malloc(sizeof(struct comando));
    novo_comando->ordem_exec = ordem_exec;

    strcpy(novo_comando->instrucao, instrucao);
    novo_comando->prox = NULL;

    if(*lista == NULL) {
        *lista = novo_comando;
        novo_comando->ant = NULL;
        return;
    }

    struct comando *ult = *lista;
    while (ult->prox != NULL) {
        ult = ult->prox;
    }

    ult->prox = novo_comando;
    novo_comando->ant = ult;
}

void remover_comeco_comando(struct comando **lista) {
    if(*lista == NULL) {
        return;
    }

    struct comando *aux = *lista;
    *lista = (*lista)->prox;
    if(*lista) {
        (*lista)->ant = NULL;
    }
    free(aux);
}

void separar_comandos(struct comando **lista, struct comando **pessoa, struct comando **tipo_pet, struct comando **pet) {

    int ordem_exec = 1;

    if(lista == NULL) {
        return;
    }

    struct comando *aux = *lista;
    while(aux) {
        if (!strcmp(aux->fila, "pessoa")) {
            inserir_final_comando(pessoa, ordem_exec, aux->instrucao);
        } else if (!strcmp(aux->fila, "tipo_pet")) {
            inserir_final_comando(tipo_pet, ordem_exec, aux->instrucao);
        } else if (!strcmp(aux->fila, "pet")) {
            inserir_final_comando(pet, ordem_exec, aux->instrucao);
        }

        ordem_exec++;
        aux = (*lista) ? (*lista)->prox : NULL;
        remover_comeco_comando(lista);
    }

}