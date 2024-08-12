#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"
#include "nome.h"

Nome *criar_tabnomes(){
	return (Nome*)malloc(100000000 * sizeof(Nome));
}

int inserir_nome(Empresa *emp, Nome *nomes, int tam){
	nomes[tam].emp = emp;
	return ++tam;
}

int compara_nomes(const void *a, const void *b){
	return strcmp(((Nome*)a)->emp->nome, ((Nome*)b)->emp->nome);
}

void ordena_nomes(Nome *nomes, int tam){
	qsort(nomes, tam, sizeof(Nome), compara_nomes);
}
