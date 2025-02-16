#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "tipo_de_pet.h"
#include "pet.h"
#include "comando.h"
#include "lista_func.h"
#include "arquivos_func.h"
#include "validacao.h"
#include "arv_pessoa.h"
#include "arv_pet.h"
#include "arv_tipo_de_pet.h"
#include "arvore_func.h"

int main() {

	FILE *f_pessoa = abrir_arquivo("pessoa.bin");
	FILE *f_tipo_pet = abrir_arquivo("tipo_pet.bin");
	FILE *f_pet = abrir_arquivo("pet.bin");

	struct comando *c_geral = NULL;

	struct comando *c_pessoa = NULL;
	struct comando *c_tipo_pet = NULL;
	struct comando *c_pet = NULL;

	struct pessoa *l_pessoa = ler_dados_pessoas();
	struct tipo_de_pet *l_tipo_pet = ler_dados_tipo_pets();
	struct pet *l_pet = ler_dados_pets();

	struct arv_pessoa *a_pessoa = NULL;
	struct arv_tipo_de_pet *a_tipo_pet = NULL;
	struct arv_pet *a_pet = NULL;

	/*
	 * CÓDIGO PARA FILTRAR AS INSTRUÇÕES
	 */

	separar_comandos(&c_geral, &c_pessoa, &c_tipo_pet, &c_pet);

	/*
	 * CÓDIGO PARA EXECUTAR AS INSTRUÇÕES
	 */

	armazenar_dados(l_pessoa, f_pessoa, l_tipo_pet, f_tipo_pet, l_pet, f_pet);
	limpar_listas(&l_pessoa, &l_tipo_pet, &l_pet);

	return 0;
}