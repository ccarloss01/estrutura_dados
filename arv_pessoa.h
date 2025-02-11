#ifndef ARV_PESSOA_H
#define ARV_PESSOA_H

#include "pessoa.h"

struct arv_pessoa {
    struct pessoa *pessoa;
    struct arv_pessoa *dir;
    struct arv_pessoa *esq;
};

#endif
