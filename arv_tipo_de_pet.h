#ifndef ARV_TIPO_DE_PET_H
#define ARV_TIPO_DE_PET_H

#include "tipo_de_pet.h"

struct arv_tipo_de_pet {
    struct tipo_de_pet *tipo_de_pet;
    struct arv_tipo_de_pet *dir;
    struct arv_tipo_de_pet *esq;
};

#endif
