#ifndef VALIDACAO_H
#define VALIDACAO_H

#include "comando.h"

int validar_instrucao(struct comando *comando);

int validar_insert(struct comando *cmd);

int validar_select(struct comando *cmd);

int validar_delete(struct comando *cmd);

int validar_update(struct comando *cmd);

int validar_comando(struct comando *cmd);

int validar_campo(const char *tabela, const char *campo);

int extrair_campos_insert(struct comando *cmd, char tabela[][255]);

int extrair_valores_insert(struct comando *cmd, char tabela[][255]);

void inicializar_tabela(char tabela[][255], int tam);

void extrair_delete(struct comando *cmd, char tabela[][255]);

void extrair_select(struct comando *cmd, char tabela[][255]);

void extrair_update(struct comando *cmd, char tabela[], char campos[][255], char valores[][255]);

#endif