#ifndef TIPO_DE_PET_H
#define TIPO_DE_PET_H

struct tipo_de_pet {
    char codigo[10];
    char descricao[255];
    struct tipo_de_pet *prox;
    struct tipo_de_pet *ant;
};

#endif