#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "empresa.h"

Hash *criar_tabela(){
	Hash *hash = (Hash*)malloc(100000000 * sizeof(Hash));
	int i = 0;
	while(i < 100000000){
		hash[i].emp = NULL;
		i++;
	}
	return hash;
}

void inserir_tab(Empresa *emp, Hash *hash){
	hash[emp->cnpj].emp = emp;
}
