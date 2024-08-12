#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "empresa.h"
#include "hash.h"

int main(){
	FILE *csv = fopen("./Empresas0.csv", "r");

	printf("Criando matriz...\n");
       	Hash *hash = criar_tabela();
	int search;

	Empresa *emp;

	char str[256];
	printf("Carregando arquivo...\n");
	while(fgets(str, 256, csv)){
		emp = criar_empresa(str);
		inserir_tab(emp, hash);
	}
	printf("Arquivo carregado.\n");
	
	printf("Buscar CNPJ: ");
	scanf("%d", &search);

	if(hash[search].emp != NULL) mostrar_empresa(hash[search].emp);
	else printf("CNPJ nao encontrado.\n");

	fclose(csv);
	free(hash);
	printf("Encerrando...\n");

	return 0;
}
