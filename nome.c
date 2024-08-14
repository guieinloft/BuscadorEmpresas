#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"
#include "nome.h"

int substrcmp(const char *s1, const char *s2){
	int i = 0;
	while(s1[i+1] != 0 && s2[i+1] != 0 && s1[i] == s2[i])i++;
	return s1[i] - s2[i];
}

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

int compara_cnpj(const void *a, const void *b){
	return ((Nome*)b)->emp->cnpj - ((Nome*)a)->emp->cnpj;
}

void ordena_cnpj(Nome *nomes, int tam){
	qsort(nomes, tam, sizeof(Nome), compara_cnpj);
}

Empresa *busca_nome(char *str, Nome *nomes, int tam){
	str = strupr(str);
	int h = tam-1;
	int l = 0;
	int m;
	int cmp;
	while(l <= h){
		m = l + (h-l)/2;
		cmp = substrcmp(str, nomes[m].emp->nome);
		if(cmp == 0) return nomes[m].emp;
		else if(cmp > 0) l = m+1;
		else if(cmp < 0) h = m-1;
	}
	return NULL;
}

Empresa *busca_cnpj(int cnpjs, Nome *nomes, int tam){
	int h = tam-1;
	int l = 0;
	int m;
	int cmp;
	while(l <= h){
		m = l + (h-l)/2;
		cmp = nomes[m].emp->cnpj - cnpjs;
		if(cmp == 0) return nomes[m].emp;
		else if(cmp > 0) l = m+1;
		else if(cmp < 0) h = m-1;
	}
	return NULL;
}
