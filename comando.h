#ifndef COMANDO_H
#define COMANDO_H

struct comando {
    int ordem_exec;
    char instrucao[255];
    char fila[9];
    struct comando *prox;
    struct comando *ant;
};

#endif
