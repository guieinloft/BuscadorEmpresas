#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "empresa.h"
#include "nome.h"

int menu_cnpj(Nome *nomes, int tam){
	int cnpj;
	printf("\nDigite os 8 primeiros digitos do CNPJ\n(-1 para sair): ");
	scanf("%d", &cnpj);
	if(cnpj == -1) return -1;
	Empresa *emp_busca = busca_cnpj(cnpj, nomes, tam);
	if(emp_busca != NULL) mostrar_empresa(emp_busca);
	else printf("Empresa nao encontrada.\n");
	return 0;
}

int menu_nome(Nome *nomes, int tam){
	char nome[200];
	printf("\nDigite o nome a ser buscado\n(\"-1\" para sair): ");
	fgets(nome, 200, stdin);
	nome[strlen(nome)-1] = '\0';
	if(strcmp(nome, "-1") == 0) return -1;
	Empresa *emp_busca = busca_nome(nome, nomes, tam);
	if(emp_busca != NULL) mostrar_empresa(emp_busca);
	else printf("Empresa nao encontrada.\n");
	return 0;
}

int menu_principal(){
	int op;
	printf("\n1. Buscar por CNPJ\n2. Buscar por nome\n0. Sair\n>");
	scanf("%d", &op);
	return op;
}

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
	FILE *csv = fopen("./Empresas0.csv", "r");

	Nome *nomes;

	printf("Criando matriz...\n");
	nomes = criar_tabnomes();
	int tam = 0, op, op2, i;
	Empresa *emp;
	char str[256];
	printf("Carregando arquivo (pode demorar alguns minutos)...\n");
	while(fgets(str, 256, csv)){
		emp = criar_empresa(str);
		tam = inserir_nome(emp, nomes, tam);
	}
	
	printf("Arquivo carregado.\n");
	
	do{
		op = menu_principal();
		switch(op){
			case 1:
				ordena_cnpj(nomes, tam);
				do{
					op2 = menu_cnpj(nomes, tam);
				} while(op2 != -1);
				break;
			case 2:
				ordena_nomes(nomes, tam);
				do{
					op2 = menu_nome(nomes, tam);
				} while(op2 != -1);
				break;
			default:
				break;
		}
	}while(op != 0);

	printf("\nEncerrando...\n");
	fclose(csv);
	for(i = 0; i < tam; i++) free(nomes[i].emp);
	free(nomes);

	return 0;
}
