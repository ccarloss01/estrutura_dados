#include "validacao.h"

#include <stdio.h>

#include "comando.h"

int validar_instrucao(struct comando *comando, char tipo[]) {

    char *inst = comando->instrucao;

    int offset = strlen(tipo);

    if (strncmp(inst, tipo, offset)) {
        return 0;
    }

    inst += offset + 1;

    char tabela[10];
    strcpy(tabela, validar_tabela(inst));

    if (!strcmp(tabela, "")) {
        return 0;
    }

    strcpy(comando->fila, tabela);



    return 1;

}

char *validar_tabela(char *inst) {

    if (!strncmp(inst, "pessoa", 6)) {
        return "pessoa";
    } else if (!strncmp(inst, "tipo_pet", 8)) {
        return "tipo_pet";
    } else if (!strncmp(inst, "pet", 3)) {
        return "pet";
    }

    return "";
}