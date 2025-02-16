#ifndef VALIDACAO_H
#define VALIDACAO_H

int validar_instrucao(struct comando *comando, char tipo[]);

char *validar_tabela(char *inst);

int validar_insert(struct comando *cmd);

int validar_select(struct comando *cmd);

int validar_delete(struct comando *cmd);

int validar_update(struct comando *cmd);

int validar_comando(struct comando *cmd);

int validar_campo(const char *tabela, const char *campo);

int extrair_campos(struct comando *cmd, char tabela[][255]);

int extrair_valores(struct comando *cmd, char tabela[][255]);

#endif
