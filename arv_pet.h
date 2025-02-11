#ifndef ARV_PET_H
#define ARV_PET_H

struct arv_pet {
    struct pet *pet;
    struct arv_pet *dir;
    struct arv_pet *esq;
};

#endif
