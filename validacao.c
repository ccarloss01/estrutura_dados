#include "validacao.h"

#include <stdio.h>
#include <string.h>

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

int validar_insert(struct comando *cmd) {
    if(strstr(cmd->instrucao, "values(")) {
        if (strstr(cmd->instrucao, "tipo_pet(")) {
            return 1;
        }
        if (strstr(cmd->instrucao, "pet(")) {
            return 1;
        }
        if (strstr(cmd->instrucao, "pessoa(")) {
            return 1;
        }
    }
    return 0;
}

int validar_select(struct comando *cmd) {
    if (strstr(cmd->instrucao, "from")) {
        return 1;
    }
    return 0;
}

int validar_delete(struct comando *cmd) {
    
    if (strstr(cmd->instrucao, "where")) {
        return 1;
    }
    return 0;
}

int validar_update(struct comando *cmd) {

    if (strstr(cmd->instrucao, "set")) {
        return 1;
    }
    return 0;
}

int validar_comando(struct comando *cmd) {

    if (strstr(cmd->instrucao, ");")){
        return 0;
    }

    if (strncmp(cmd->instrucao, "insert into ", 11) == 0) {
        return validar_insert(cmd);
    }
    else if (strncmp(cmd->instrucao, "select * from ", 13) == 0) {
        return 1;
    }
    else if (strncmp(cmd->instrucao, "delete from ", 11) == 0) {
        return validar_delete(cmd);
    }
    else if (strncmp(cmd->instrucao, "update ", 11) == 0) {
        return validar_update(cmd);
    }
    return 0;
}

int validar_campo(const char *tabela, const char *campo) {
    if (strcmp(tabela, "pessoa") == 0) {
        if (strcmp(campo, "nome") == 0 ||
            strcmp(campo, "fone") == 0 ||
            strcmp(campo, "endereco") == 0 ||
            strcmp(campo, "data_nascimento") == 0)
            return 1;
    } else if (strcmp(tabela, "pet") == 0) {
        if (strcmp(campo, "nome") == 0 ||
            strcmp(campo, "codigo_cli") == 0 ||
            strcmp(campo, "codigo_tipo") == 0)
            return 1;
    } else if (strcmp(tabela, "tipo_pet") == 0) {
        if (strcmp(campo, "descricao") == 0)
            return 1;
    }
    return 0;
}

int extrair_campos(struct comando *cmd, char tabela[][255]) {
    const char *inst = cmd->instrucao;
    int len = strlen(inst);
    int i, j = 0, k = 0;
    int copiando = 0;

    for (i = 0; i < len; i++) {
        if (inst[i] == '(' && !copiando) {
            // Encontrou o '(' -> começa a copiar
            copiando = 1;
            continue;
        }
        if (copiando) {
            // Ao encontrar vírgula, finaliza o campo atual e passa para o próximo
            if (inst[i] == ',') {
                tabela[k][j] = '\0';
                k++;
                j = 0;
                continue;
            }
            // Ao encontrar ')', finaliza o último campo e sai
            else if (inst[i] == ')') {
                tabela[k][j] = '\0';
                break;
            }
            // Copia caractere para o campo atual
            else {
                tabela[k][j] = inst[i];
                j++;
            }
        }
    }
    // Retorna a quantidade de campos extraídos (k + 1, se k começou em 0)
    return k + 1;
}