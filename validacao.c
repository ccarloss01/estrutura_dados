#include "validacao.h"

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "comando.h"
int validar_instrucao(struct comando *comando) {

    if(validar_comando(comando) == 0) {
        return 0;
    }

    if(strstr(comando->instrucao, "pessoa")) {
        strcpy(comando->fila, "pessoa");
    } else if(strstr(comando->instrucao, "tipo_pet")) {
        strcpy(comando->fila, "tipo_pet");
    } else if(strstr(comando->instrucao, "pet")) {
        strcpy(comando->fila, "pet");
    }

    return 1;

}

int validar_insert(struct comando *cmd) {
    if(strstr(cmd->instrucao, "values(")) {
        char campos[5][255];
        char valores[5][255];

        inicializar_tabela(campos, 5);
        inicializar_tabela(valores, 5);

        extrair_campos_insert(cmd, campos);
        extrair_valores_insert(cmd, valores);


        if (strstr(cmd->instrucao, "tipo_pet(")) {

            int codigo = 0;
            int descricao = 0;

            for(int i = 0; i < 2; i++) {
                if(strcmp(campos[i], "codigo") == 0) {
                    codigo = 1;
                    if(strcmp(valores[i], "") == 0) {
                        return 0;
                    }
                } else if(strcmp(campos[i], "descricao") == 0) {
                    descricao = 1;
                    if(strcmp(valores[i], "") == 0) {
                        return 0;
                    }
                }
            }

            if(!codigo || !descricao) {
                return 0;
            }

            return 1;
        }
        if (strstr(cmd->instrucao, "pet(")) {

            int codigo = 0;
            int nome = 0;
            int codigo_pes = 0;
            int codigo_tipo = 0;

            for(int i = 0; i < 4; i++) {
                if(strcmp(campos[i], "codigo") == 0) {
                    codigo = 1;
                    if(strcmp(valores[i], "") == 0) {
                        return 0;
                    }
                } else if(strcmp(campos[i], "nome") == 0) {
                    nome = 1;
                    if(strcmp(valores[i], "") == 0) {
                        return 0;
                    }
                } else if(strcmp(campos[i], "codigo_cli") == 0) {
                    codigo_pes = 1;
                    if(strcmp(valores[i], "") == 0) {
                        return 0;
                    }
                } else if(strcmp(campos[i], "codigo_tipo") == 0) {
                    codigo_tipo = 1;
                    if(strcmp(valores[i], "") == 0) {
                        return 0;
                    }
                }
            }

            if(!codigo || !nome || !codigo_pes || !codigo_tipo) {
                return 0;
            }

            return 1;
        }
        if (strstr(cmd->instrucao, "pessoa(")) {

            int codigo = 0;
            int nome = 0;
            int data_nascimento = 0;

            for(int i = 0; i < 5; i++) {
                if(strcmp(campos[i], "codigo") == 0) {
                    codigo = 1;
                    if(strcmp(valores[i], "") == 0) {
                        return 0;
                    }
                } else if(strcmp(campos[i], "nome") == 0) {
                    nome = 1;
                    if(strcmp(valores[i], "") == 0) {
                        return 0;
                    }
                } else if(strcmp(campos[i], "data_nascimento") == 0) {
                    data_nascimento = 1;
                    if(strcmp(valores[i], "") == 0) {
                        return 0;
                    }
                }
            }

            if(!codigo || !nome || !data_nascimento) {
                return 0;
            }

            return 1;
        }
    }
    return 0;
}

int validar_select(struct comando *cmd) {
    char campos[4][255];

    inicializar_tabela(campos, 4);

    extrair_select(cmd, campos);

    if(strcmp(campos[0], "pessoa") == 0 || strcmp(campos[0], "pet") == 0) {

        if(strcmp(campos[1], "w") == 0 && strcmp(campos[2], "codigo") == 0 && strcmp(campos[3], "") != 0) {
            return 1;
        } else if(strcmp(campos[1], "o") == 0 &&
            (strcmp(campos[2], "codigo") == 0 || strcmp(campos[2], "nome") == 0)) {
            return 1;
        }

    } else if(strcmp(campos[0], "tipo_pet") == 0) {
        if(strcmp(campos[1], "w") == 0 && strcmp(campos[2], "codigo") == 0 && strcmp(campos[3], "") != 0) {
            return 1;
        } else if(strcmp(campos[1], "o") == 0 &&
            (strcmp(campos[2], "codigo") == 0 || strcmp(campos[2], "descricao") == 0)) {
            return 1;
        }
    }

    return 0;
}

int validar_delete(struct comando *cmd) {
    
    char campos[4][255];

    inicializar_tabela(campos, 4);

    extrair_delete(cmd, campos);

    if(strcmp(campos[0], "pessoa") == 0 || strcmp(campos[0], "pet") == 0 || strcmp(campos[0], "tipo_pet") == 0) {

        if(strcmp(campos[1], "w") == 0 && strcmp(campos[2], "codigo") == 0 && strcmp(campos[3], "") != 0) {
            return 1;
        }

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
        return validar_select(cmd);
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
            strcmp(campo, "data_nascimento") == 0 ||
            strcmp(campo, "codigo") == 0)
            return 1;
    } else if (strcmp(tabela, "pet") == 0) {
        if (strcmp(campo, "nome") == 0 ||
            strcmp(campo, "codigo_cli") == 0 ||
            strcmp(campo, "codigo_tipo") == 0 ||
            strcmp(campo, "codigo") == 0)
            return 1;
    } else if (strcmp(tabela, "tipo_pet") == 0) {
        if (strcmp(campo, "descricao") == 0 ||
            strcmp(campo, "codigo") == 0)
            return 1;
    }
    return 0;
}

int extrair_campos_insert(struct comando *cmd, char tabela[][255]) {
    const char *inst = cmd->instrucao;
    int len = strlen(inst);
    int i, j = 0, k = 0;
    int copiando = 0;

    for (i = 0; i < len; i++) {
        if (inst[i] == '(' && !copiando) {
            copiando = 1;
            continue;
        }
        if (copiando) {
            if (inst[i] == ',') {
                tabela[k][j] = '\0';
                k++;
                j = 0;
                continue;
            }
            else if (inst[i] == ')') {
                tabela[k][j] = '\0';
                break;
            }
            // Se for aspas simples, pula
            if (inst[i] == '\'')
                continue;
            // Pula espaços iniciais do campo
            if (j == 0 && isspace((unsigned char)inst[i]))
                continue;
            tabela[k][j] = inst[i];
            j++;
        }
    }
    return k + 1;
}

int extrair_valores_insert(struct comando *cmd, char tabela[][255]) {
    const char *inst = cmd->instrucao;
    int len = strlen(inst);
    int i, j = 0, k = 0;
    int copiando = 0;
    int contador_par = 0;
    int in_quotes = 0;

    for (i = 0; i < len; i++) {
        if (inst[i] == '(') {
            contador_par++;
            if (contador_par == 2) {
                copiando = 1;
                continue;
            }
        }
        if (copiando) {
            if (inst[i] == '\'') {
                in_quotes = !in_quotes;
                continue; // Pula a aspa sem copiar
            }
            if (inst[i] == ',' && !in_quotes) {
                tabela[k][j] = '\0';
                k++;
                j = 0;
                continue;
            }
            else if (inst[i] == ')' && !in_quotes) {
                tabela[k][j] = '\0';
                break;
            }
            // Pula espaços iniciais do campo
            if (j == 0 && isspace((unsigned char)inst[i]))
                continue;
            tabela[k][j] = inst[i];
            j++;
        }
    }
    return k + 1;
}

void extrair_delete(struct comando *cmd, char tabela[][255]) {
    const char *inst = cmd->instrucao;
    int i;

    // Inicializa todas as linhas da tabela
    for(i = 0; i < 4; i++){
        tabela[i][0] = '\0';
    }

    // Extrair nome da tabela (após "from ")
    const char *pFrom = strstr(inst, "from ");
    if (pFrom) {
        pFrom += 5; // pula "from "
        i = 0;
        while (pFrom[i] && !isspace((unsigned char)pFrom[i]) && i < 254) {
            tabela[0][i] = pFrom[i];
            i++;
        }
        tabela[0][i] = '\0';
    }

    // Verifica se há cláusula "where"
    const char *pWhere = strstr(inst, "where");
    if (pWhere) {
        tabela[1][0] = 'w';
        tabela[1][1] = '\0';
        pWhere += 5; // pula "where"
        // Ignora espaços
        while (*pWhere && isspace((unsigned char)*pWhere))
            pWhere++;
        // Campo: extrai o nome completo do campo
        {
            int j = 0;
            while (*pWhere && !isspace((unsigned char)*pWhere) && *pWhere != '=' && j < 254) {
                tabela[2][j++] = *pWhere;
                pWhere++;
            }
            tabela[2][j] = '\0';
        }
        // Procura o '=' para extrair o valor
        const char *pEqual = strchr(pWhere, '=');
        if (pEqual) {
            pEqual++; // pula o '='
            while (*pEqual && isspace((unsigned char)*pEqual))
                pEqual++;
            int j = 0;
            while (pEqual[j] && !isspace((unsigned char)pEqual[j]) && pEqual[j] != ';' && j < 254) {
                tabela[3][j] = pEqual[j];
                j++;
            }
            tabela[3][j] = '\0';
        }
    }
}

void extrair_select(struct comando *cmd, char tabela[][255]) {
    const char *inst = cmd->instrucao;
    int i;

    // Inicializa todas as linhas da tabela
    for(i = 0; i < 4; i++){
        tabela[i][0] = '\0';
    }

    // Extrair nome da tabela (após "from ")
    const char *pFrom = strstr(inst, "from ");
    if (pFrom) {
        pFrom += 5; // pula "from "
        i = 0;
        while (pFrom[i] && !isspace((unsigned char)pFrom[i]) && i < 254) {
            tabela[0][i] = pFrom[i];
            i++;
        }
        tabela[0][i] = '\0';
    }

    // Verifica se há cláusula "where"
    const char *pWhere = strstr(inst, "where");
    if (pWhere) {
        tabela[1][0] = 'w';
        tabela[1][1] = '\0';
        pWhere += 5; // pula "where"
        // Ignora espaços
        while (*pWhere && isspace((unsigned char)*pWhere))
            pWhere++;
        // Captura o nome completo do campo (até espaço ou '=')
        {
            int j = 0;
            while (pWhere[j] && !isspace((unsigned char)pWhere[j]) && pWhere[j] != '=' && j < 254) {
                tabela[2][j] = pWhere[j];
                j++;
            }
            tabela[2][j] = '\0';
        }
        // Procura o '=' para extrair o valor
        const char *pEqual = strchr(pWhere, '=');
        if (pEqual) {
            pEqual++; // pula o '='
            while (*pEqual && isspace((unsigned char)*pEqual))
                pEqual++;
            int j = 0;
            while (pEqual[j] && !isspace((unsigned char)pEqual[j]) && pEqual[j] != ';' && j < 254) {
                tabela[3][j] = pEqual[j];
                j++;
            }
            tabela[3][j] = '\0';
        }
    } else {
        // Se não houver "where", verifica se há cláusula "order"
        const char *pOrder = strstr(inst, "order");
        if (pOrder) {
            tabela[1][0] = 'o';
            tabela[1][1] = '\0';
            pOrder += 5; // pula "order"
            while (*pOrder && isspace((unsigned char)*pOrder))
                pOrder++;
            // Se houver o token "by", pula-o
            if (strncmp(pOrder, "by", 2) == 0) {
                pOrder += 2;
                while (*pOrder && isspace((unsigned char)*pOrder))
                    pOrder++;
            }
            // Captura o nome completo do campo (até espaço ou outro delimitador)
            {
                int j = 0;
                while (pOrder[j] && !isspace((unsigned char)pOrder[j]) && pOrder[j] != ';' && j < 254) {
                    tabela[2][j] = pOrder[j];
                    j++;
                }
                tabela[2][j] = '\0';
            }
            // Para "order", não há valor associado, então tabela[3] permanece vazia.
        }
    }
}

// a tabela vai retornar o nome da tabela
// e o campo e valor vao estar na ordem certa, ex : campo[0] = "nome", valor[0] = "joao"
void extrair_update(struct comando *cmd, char tabela[], char campos[][255], char valores[][255]) {
    const char *inst = cmd->instrucao;
    int i = 0, j = 0, k = 0;
    int in_quotes = 0;

    // Inicializa as strings
    tabela[0] = '\0';
    for (i = 0; i < 5; i++) {
        campos[i][0] = '\0';
        valores[i][0] = '\0';
    }

    // Extrai nome da tabela após "update "
    const char *p_tabela = strstr(inst, "update ");
    if (p_tabela) {
        p_tabela += 7; // pula "update "
        i = 0;
        // Copia o nome completo da tabela (até encontrar espaço não-entre aspas)
        if (*p_tabela == '\'') {
            p_tabela++; // pula a aspa inicial se houver
            while (p_tabela[i] && p_tabela[i] != '\'' && i < 254) {
                tabela[i] = p_tabela[i];
                i++;
            }
            tabela[i] = '\0';
        } else {
            while (p_tabela[i] && !isspace((unsigned char)p_tabela[i]) && i < 254) {
                tabela[i] = p_tabela[i];
                i++;
            }
            tabela[i] = '\0';
        }
    }

    // Extrai campos e valores após "set "
    const char *p_set = strstr(inst, "set ");
    if (p_set) {
        p_set += 4; // pula "set "

        while (*p_set) {
            // Ignora espaços iniciais
            while (*p_set && isspace((unsigned char)*p_set))
                p_set++;

            // Extrai nome do campo COMPLETO (mantém os espaços internos)
            j = 0;
            while (*p_set && *p_set != '=' && j < 254) {
                campos[k][j++] = *p_set;
                p_set++;
            }
            campos[k][j] = '\0';

            if (*p_set == '=') p_set++; // Pula o '='

            // Ignora espaços iniciais antes do valor
            while (*p_set && isspace((unsigned char)*p_set))
                p_set++;

            // Extrai o valor do campo
            j = 0;
            if (*p_set == '\'') {
                in_quotes = 1;
                p_set++; // Pula a aspa inicial
            }
            while (*p_set && (in_quotes || (!isspace((unsigned char)*p_set) && *p_set != ',' && *p_set != ';'))) {
                if (*p_set == '\'') {
                    in_quotes = 0; // Fecha a string
                } else {
                    valores[k][j++] = *p_set;
                }
                p_set++;
            }
            valores[k][j] = '\0';

            k++;
            if (*p_set == ',') {
                p_set++; // Pula a vírgula e continua
            } else {
                break;
            }
        }
    }
}

void inicializar_tabela(char tabela[][255], int tam) {
    for(int i = 0; i < tam; i++) {
        strcpy(tabela[i], "");
    }
}