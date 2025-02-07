#ifndef PESSOA_H
#define PESSOA_H

struct pessoa {
    char codigo[10];
    char nome[255];
    char fone[12];
    char data_nascimento[11];
    char endereco[255];
    struct pessoa *prox;
    struct pessoa *ant;
};

#endif