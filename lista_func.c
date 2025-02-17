#include "pessoa.h"
#include "tipo_de_pet.h"
#include "pet.h"
#include "comando.h"
#include "lista_func.h"
#include "validacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore_func.h"

// Métodos Lista Pessoa
void inserir_final_pessoa(struct pessoa **lista, char codigo[], char nome[], char fone[], char data_nascimento[], char endereco[]) {
    struct pessoa *aux = buscar_pessoa(*lista, codigo);

    if (aux != NULL) {
        return;
    }
    
    struct pessoa *nova_pessoa = malloc(sizeof(struct pessoa));
    if (nova_pessoa == NULL) {
        fprintf(stderr, "Erro ao alocar memória para nova pessoa\n");
        return;
    }

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

void remover_pessoa(struct pessoa **lista, struct pet *pet, char codigo[]) {
    if(*lista == NULL) {
        return;
    }

    if(buscar_pessoa_pet(pet, codigo)) {
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

int buscar_pessoa_pet(struct pet *lista, char codigo[]) {
    struct pet *aux = lista;
    while(aux && strcmp(aux->codigo_pes, codigo) != 0) {
        aux = aux->prox;
    }

    if(aux != NULL) {
        return 1;
    } else {
        return 0;
    }
}

void remover_comeco_pessoa(struct pessoa **lista) {
    if(*lista == NULL) {
        return;
    }

    struct pessoa *aux = *lista;
    *lista = (*lista)->prox;
    if(*lista) {
        (*lista)->ant = NULL;
    }
    free(aux);
}

void limpar_lista_pessoa(struct pessoa **lista) {

    while(*lista != NULL) {
        remover_comeco_pessoa(lista);
    }

}

void imprimir_lista_pessoa(struct pessoa *l_pessoa) {
    while(l_pessoa != NULL) {
        imprimir_pessoa(l_pessoa);

        l_pessoa->prox;
    }
}

// Métodos Lista Tipo de Pet
void inserir_final_tipo_pet(struct tipo_de_pet **lista, char codigo[], char descricao[]) {
    
    struct tipo_de_pet *aux = buscar_tipo_pet(*lista, codigo);

    if (aux != NULL) {
        return;
    }
    
    struct tipo_de_pet *novo_tipo_pet = malloc(sizeof(struct tipo_de_pet));
    if (novo_tipo_pet == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo tipo pet\n");
        return;
    }
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

void remover_tipo_pet(struct tipo_de_pet **lista, struct pet *pet, char codigo[]) {
    if(*lista == NULL) {
        return;
    }

    if(buscar_tipo_pet_pet(pet, codigo)) {
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

int buscar_tipo_pet_pet(struct pet *lista, char codigo[]) {
    struct pet *aux = lista;
    while(aux && strcmp(aux->codigo_tipo, codigo) != 0) {
        aux = aux->prox;
    }

    if(aux != NULL) {
        return 1;
    } else {
        return 0;
    }
}

void remover_comeco_tipo_pet(struct tipo_de_pet **lista) {
    if(*lista == NULL) {
        return;
    }

    struct tipo_de_pet *aux = *lista;
    *lista = (*lista)->prox;
    if(*lista) {
        (*lista)->ant = NULL;
    }
    free(aux);
}

void limpar_lista_tipo_pet(struct tipo_de_pet **lista) {

    while(*lista != NULL) {
        remover_comeco_tipo_pet(lista);
    }

}

void imprimir_lista_tipo_pet(struct tipo_de_pet *l_tipo_pet) {
    while(l_tipo_pet != NULL) {
        imprimir_tipo_pet(l_tipo_pet);

        l_tipo_pet->prox;
    }
}

// Métodos Lista Pet
void inserir_final_pet(struct pet **lista, struct pessoa *pessoa, struct tipo_de_pet *tipo_pet, char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]) {

    struct pet *aux = buscar_pet(*lista, codigo);

    if (aux != NULL) {
        return;
    }

    if(buscar_tipo_pet(tipo_pet, codigo_tipo) == NULL || buscar_pessoa(pessoa, codigo_pes) == NULL) {
        return;
    }

    struct pet *novo_pet = malloc(sizeof(struct pet));
    if (novo_pet == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo pet\n");
        return;
    }

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

void inserir_final_pet_sem_verificar(struct pet **lista, char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]) {
    struct pet *aux = buscar_pet(*lista, codigo);

    if (aux != NULL) {
        return;
    }

    struct pet *novo_pet = malloc(sizeof(struct pet));
    if (novo_pet == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo pet\n");
        return;
    }
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

void atualizar_pet(struct pet *lista, struct tipo_de_pet *tipo_pet, struct pessoa *pessoa,
    char codigo[], char nome[], char codigo_tipo[], char codigo_pes[]) {

    struct pet *aux = buscar_pet(lista, codigo);
    struct tipo_de_pet *tipo = buscar_tipo_pet(tipo_pet, codigo_tipo);
    struct pessoa *pes = buscar_pessoa(pessoa, codigo_pes);

    if(aux == NULL || tipo == NULL || pes == NULL) {
        return;
    }

    strcpy(aux->nome, nome);
    strcpy(aux->codigo_tipo, codigo_tipo);
    strcpy(aux->codigo_pes, codigo_pes);
}

void remover_comeco_pet(struct pet **lista) {
    if(*lista == NULL) {
        return;
    }

    struct pet *aux = *lista;
    *lista = (*lista)->prox;
    if(*lista) {
        (*lista)->ant = NULL;
    }
    free(aux);
}

void limpar_lista_pet(struct pet **lista) {

    while(*lista != NULL) {
        remover_comeco_pet(lista);
    }

}

void imprimir_lista_pet(struct pet *l_pet) {
    while(l_pet != NULL) {
        imprimir_pet(l_pet);

        l_pet->prox;
    }
}

// Métodos Lista Comando
void inserir_final_comando(struct comando **lista, int ordem_exec, char instrucao[]) {
    struct comando *novo_comando = malloc(sizeof(struct comando));
    if (novo_comando == NULL) {
        fprintf(stderr, "Erro ao alocar memória para inserir final comando\n");
        return;
    }
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
        remover_comeco_comando(lista);
        aux = (*lista);
    }

}

void limpar_listas(struct pessoa **pessoa, struct tipo_de_pet **tipo_pets, struct pet **pets) {

    limpar_lista_pessoa(pessoa);
    limpar_lista_tipo_pet(tipo_pets);
    limpar_lista_pet(pets);

}

void executar_comando_listas(struct comando **c_pessoa, struct comando **c_tipo_pet, struct comando **c_pet, struct pessoa **l_pessoa, struct tipo_de_pet **l_tipo_pet, struct pet **l_pet, struct arv_pessoa **a_pessoa, struct arv_tipo_de_pet **a_tipo_pet, struct arv_pet **a_pet) {

    int ord_exec = 1;

    while(*c_pessoa != NULL || *c_tipo_pet != NULL || *c_pet != NULL) {

        char tipo[20];

        if(*c_pessoa && (*c_pessoa)->ordem_exec == ord_exec) {

            strncpy(tipo, (*c_pessoa)->instrucao, 6);

            if(strcmp(tipo, "insert") == 0) {
                executar_insert_pessoa(*c_pessoa, l_pessoa);
            } else if(strcmp(tipo, "select") == 0) {
                executar_select_pessoa(*c_pessoa, *l_pessoa, a_pessoa);
            } else if(strcmp(tipo, "delete") == 0) {
                executar_delete_pessoa(*c_pessoa, l_pessoa, *l_pet);
            } else if(strcmp(tipo, "update") == 0) {
                executar_update_pessoa(*c_pessoa, *l_pessoa);
            }

            remover_comeco_comando(c_pessoa);

        } else if(*c_tipo_pet && (*c_tipo_pet)->ordem_exec == ord_exec) {

            strncpy(tipo, (*c_tipo_pet)->instrucao, 6);

            if(strcmp(tipo, "insert") == 0) {
                executar_insert_tipo_pet(*c_tipo_pet, l_tipo_pet);
            } else if(strcmp(tipo, "select") == 0) {
                executar_select_tipo_pet(*c_tipo_pet, *l_tipo_pet, a_tipo_pet);
            } else if(strcmp(tipo, "delete") == 0) {
                executar_delete_tipo_pet(*c_tipo_pet, l_tipo_pet, *l_pet);
            } else if(strcmp(tipo, "update") == 0) {
                executar_update_tipo_pet(*c_tipo_pet, *l_tipo_pet);
            }

            remover_comeco_comando(c_tipo_pet);

        } else if(*c_pet && (*c_pet)->ordem_exec == ord_exec) {

            strncpy(tipo, (*c_pet)->instrucao, 6);

            if(strcmp(tipo, "insert") == 0) {
                executar_insert_pet(*c_pet, l_pet, *l_pessoa, *l_tipo_pet);
            } else if(strcmp(tipo, "select") == 0) {
                executar_select_pet(*c_pet, *l_pet, a_pet);
            } else if(strcmp(tipo, "delete") == 0) {
                executar_delete_pet(*c_pet, l_pet);
            }  else if(strcmp(tipo, "update") == 0) {
                executar_update_pet(*c_pet, *l_pet, *l_tipo_pet, *l_pessoa);
            }

            remover_comeco_comando(c_pet);

        }

        ord_exec++;

    }

}

void executar_insert_pessoa(struct comando *c_pessoa, struct pessoa **l_pessoa) {

    char campos[5][255];
    char valores[5][255];

    extrair_campos_insert(c_pessoa, campos);
    extrair_valores_insert(c_pessoa, valores);

    char codigo[10];
    char nome[255];
    char fone[12];
    strcpy(fone, "");
    char data_nascimento[11];
    char endereco[255];
    strcpy(endereco, "");

    char aux[255];

    for(int i = 0; i < 5; i++) {

        strcpy(aux, campos[i]);

        if(strcmp(aux, "codigo") == 0) {
            strcpy(codigo, valores[i]);
        } else if(strcmp(aux, "nome") == 0) {
            strcpy(nome, valores[i]);
        } else if(strcmp(aux, "fone") == 0) {
            strcpy(fone, valores[i]);
        } else if(strcmp(aux, "data_nascimento") == 0) {
            strcpy(data_nascimento, valores[i]);
        } else if(strcmp(aux, "endereco") == 0) {
            strcpy(endereco, valores[i]);
        }
    }

    inserir_final_pessoa(l_pessoa, codigo, nome, fone, data_nascimento, endereco);

}

void executar_insert_tipo_pet(struct comando *c_tipo_pet, struct tipo_de_pet **l_tipo_pet) {

    char campos[2][255];
    char valores[2][255];

    extrair_campos_insert(c_tipo_pet, campos);
    extrair_valores_insert(c_tipo_pet, valores);

    char codigo[10];
    char descricao[255];

    char aux[255];

    for(int i = 0; i < 2; i++) {

        strcpy(aux, campos[i]);

        if(strcmp(aux, "codigo") == 0) {
            strcpy(codigo, valores[i]);
        } else if(strcmp(aux, "descricao") == 0) {
            strcpy(descricao, valores[i]);
        }
    }

    inserir_final_tipo_pet(l_tipo_pet, codigo, descricao);

}

void executar_insert_pet(struct comando *c_pet, struct pet **l_pet, struct pessoa *l_pessoa, struct tipo_de_pet *l_tipo_pet) {

    char campos[4][255];
    char valores[4][255];

    extrair_campos_insert(c_pet, campos);
    extrair_valores_insert(c_pet, valores);

    char codigo[10];
    char nome[255];
    char codigo_pes[12];
    char codigo_tipo[11];

    char aux[255];

    for(int i = 0; i < 4; i++) {

        strcpy(aux, campos[i]);

        if(strcmp(aux, "codigo") == 0) {
            strcpy(codigo, valores[i]);
        } else if(strcmp(aux, "nome") == 0) {
            strcpy(nome, valores[i]);
        } else if(strcmp(aux, "codigo_cli") == 0) {
            strcpy(codigo_pes, valores[i]);
        } else if(strcmp(aux, "codigo_tipo") == 0) {
            strcpy(codigo_tipo, valores[i]);
        }
    }

    inserir_final_pet(l_pet, l_pessoa, l_tipo_pet, codigo, nome, codigo_tipo, codigo_pes);

}

void executar_select_pessoa(struct comando *c_pessoa, struct pessoa *l_pessoa, struct arv_pessoa **a_pessoa) {
    char campos[4][255];

    extrair_select(c_pessoa, campos);

    if(strcmp(campos[1], "w") == 0) {
        struct pessoa *pessoa = buscar_pessoa(l_pessoa, campos[3]);
        imprimir_pessoa(pessoa);

    } else if(strcmp(campos[1], "o") == 0) {

        *a_pessoa = limpar_arvore_pessoa(*a_pessoa);

        if(strcmp(campos[2], "codigo") == 0) {
            transf_lista_arvore_pessoa_codigo(a_pessoa, l_pessoa);
        } else if(strcmp(campos[2], "nome") == 0) {
            transf_lista_arvore_pessoa_nome(a_pessoa, l_pessoa);
        }

        imprimir_arvore_pessoa(*a_pessoa);
    }

}

void executar_select_tipo_pet(struct comando *c_tipo_pet, struct tipo_de_pet *l_tipo_pet, struct arv_tipo_de_pet **a_tipo_pet) {

    char campos[4][255];

    extrair_select(c_tipo_pet, campos);

    if(strcmp(campos[1], "w") == 0) {
        struct tipo_de_pet *tipo_pet = buscar_tipo_pet(l_tipo_pet, campos[3]);
        imprimir_tipo_pet(tipo_pet);

    } else if(strcmp(campos[1], "o") == 0) {

        *a_tipo_pet = limpar_arvore_tipo_pet(*a_tipo_pet);

        if(strcmp(campos[2], "codigo") == 0) {
            transf_lista_arvore_tipo_pet_codigo(a_tipo_pet, l_tipo_pet);
        } else if(strcmp(campos[2], "descricao") == 0) {
            transf_lista_arvore_tipo_pet_descricao(a_tipo_pet, l_tipo_pet);
        }

        imprimir_arvore_tipo_pet(*a_tipo_pet);
    }

}

void executar_select_pet(struct comando *c_pet, struct pet *l_pet, struct arv_pet **a_pet) {

    char campos[4][255];

    extrair_select(c_pet, campos);

    if(strcmp(campos[1], "w") == 0) {
        struct pet *pet = buscar_pet(l_pet, campos[3]);
        imprimir_pet(pet);

    } else if(strcmp(campos[1], "o") == 0) {

        *a_pet = limpar_arvore_pet(*a_pet);

        if(strcmp(campos[2], "codigo") == 0) {
            transf_lista_arvore_pet_codigo(a_pet, l_pet);
        } else if(strcmp(campos[2], "nome") == 0) {
            transf_lista_arvore_pet_nome(a_pet, l_pet);
        }

        imprimir_arvore_pet(*a_pet);
    }

}

void executar_delete_pessoa(struct comando *c_pessoa, struct pessoa **l_pessoa, struct pet *pet) {
    char campos[4][255];

    extrair_delete(c_pessoa, campos);

    remover_pessoa(l_pessoa, pet, campos[3]);
}

void executar_delete_tipo_pet(struct comando *c_tipo_pet, struct tipo_de_pet **l_tipo_de_pet, struct pet *pet) {
    char campos[4][255];

    extrair_delete(c_tipo_pet, campos);

    remover_tipo_pet(l_tipo_de_pet, pet, campos[3]);
}

void executar_delete_pet(struct comando *c_pet, struct pet **l_pet) {
    char campos[4][255];

    extrair_delete(c_pet, campos);

    remover_pet(l_pet, campos[3]);
}

void executar_update_pessoa(struct comando *c_pessoa, struct pessoa *l_pessoa) {
    char tabela[10];
    char campos[5][255];
    char valores[5][255];

    char nome[255];
    char data_nascimento[255];
    char endereco[255];
    char fone[255];

    int qtd = extrair_update(c_pessoa, tabela, campos, valores);

    struct pessoa *pessoa = buscar_pessoa(l_pessoa, valores[0]);

    if(pessoa == NULL) {
        return;
    }

    strcpy(nome, pessoa->nome);
    strcpy(data_nascimento, pessoa->data_nascimento);
    strcpy(endereco, pessoa->endereco);
    strcpy(fone, pessoa->fone);

    for(int i = 1; i < qtd; i++) {
        if(strcmp(campos[i], "nome") == 0 && strcmp(valores[i], "") != 0) {
            strcpy(nome, valores[i]);
        } else if(strcmp(campos[i], "data_nascimento") == 0 && strcmp(valores[i], "") != 0) {
            strcpy(data_nascimento, valores[i]);
        } else if(strcmp(campos[i], "endereco") == 0 && strcmp(valores[i], "") != 0) {
            strcpy(endereco, valores[i]);
        } else if(strcmp(campos[i], "fone") == 0 && strcmp(valores[i], "") != 0) {
            strcpy(fone, valores[i]);
        }
    }

    atualizar_pessoa(l_pessoa, pessoa->codigo, nome, fone, data_nascimento, endereco);

}

void executar_update_tipo_pet(struct comando *c_tipo_pet, struct tipo_de_pet *l_tipo_pet) {
    char tabela[10];
    char campos[2][255];
    char valores[2][255];

    char descricao[255];

    int qtd = extrair_update(c_tipo_pet, tabela, campos, valores);

    struct tipo_de_pet *tipo_pet = buscar_tipo_pet(l_tipo_pet, valores[0]);

    if(tipo_pet == NULL) {
        return;
    }

    strcpy(descricao, tipo_pet->descricao);

    for(int i = 1; i < qtd; i++) {
        if(strcmp(campos[i], "descricao") == 0 && strcmp(valores[i], "") != 0) {
            strcpy(descricao, valores[i]);
        }
    }

    atualizar_tipo_pet(l_tipo_pet, tipo_pet->codigo, descricao);

}

void executar_update_pet(struct comando *c_pet, struct pet *l_pet, struct tipo_de_pet *l_tipo_pet, struct pessoa *l_pessoa) {
    char tabela[10];
    char campos[4][255];
    char valores[4][255];

    char nome[255];
    char codigo_cli[255];
    char codigo_tipo[255];

    int qtd = extrair_update(c_pet, tabela, campos, valores);

    struct pet *pet = buscar_pet(l_pet, valores[0]);

    if(pet == NULL) {
        return;
    }

    strcpy(nome, pet->nome);
    strcpy(codigo_cli, pet->codigo_pes);
    strcpy(codigo_tipo, pet->codigo_tipo);

    for(int i = 1; i < qtd; i++) {
        if(strcmp(campos[i], "nome") == 0 && strcmp(valores[i], "") != 0) {
            strcpy(nome, valores[i]);
        } else if(strcmp(campos[i], "codigo_cli") == 0 && strcmp(valores[i], "") != 0) {
            strcpy(codigo_cli, valores[i]);
        } else if(strcmp(campos[i], "codigo_tipo") == 0 && strcmp(valores[i], "") != 0) {
            strcpy(codigo_tipo, valores[i]);
        }
    }

    atualizar_pet(l_pet, l_tipo_pet, l_pessoa, pet->codigo, nome, codigo_tipo, codigo_cli);

}

void remover_comando(struct comando **comandos, struct comando *comando) {

    struct comando *aux = *comandos;

    while(aux && aux != comando) {
        aux = aux->prox;
    }

    if(aux == NULL) {
        return;
    }

    free(aux);
}

void filtrar_comandos(struct comando **comandos) {

    struct comando *aux = *comandos;
    struct comando *aux2 = NULL;

    while(aux != NULL) {

        aux2 = aux;
        aux = aux->prox;

        if(validar_instrucao(aux2) == 0) {

            if(aux2->ant == NULL) {
                *comandos = aux2->prox;
            } else if(aux2->prox == NULL) {
                aux2->ant->prox = aux2->prox;
            } else {
                aux2->ant->prox = aux2->prox;
                aux2->prox->ant = aux2->ant;
            }

            free(aux2);
        }

    }
}