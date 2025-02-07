#ifndef PET_H
#define PET_H

struct pet {
    char codigo[10];
    char nome[255];
    char codigo_tipo[10];
    char codigo_pes[10];
    struct pet *prox;
    struct pet *ant;
};

#endif