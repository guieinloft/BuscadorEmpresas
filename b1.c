#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "empresa.h"
#include "hash.h"
#include "nome.h"

int menu_cnpj(Hash *hash){
	int cnpj;
	printf("\nDigite os 8 primeiros digitos do CNPJ\n(-1 para sair): ");
	scanf("%d", &cnpj);
	if(cnpj == -1) return -1;
	if(hash[cnpj].emp != NULL) mostrar_empresa(hash[cnpj].emp);
	else printf("CNPJ nao encontrado.\n");
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
	bool bnome = true;
	bool bcnpj = true;

	Hash *hash;
	Nome *nomes;

	if(argc > 1 && strcmp(argv[1], "--nomes") == 0) bcnpj = false;
	if(argc > 1 && strcmp(argv[1], "--cnpj") == 0) bnome = false;

	printf("Criando matriz...\n");
       	if(bcnpj) hash = criar_tabela();
	if(bnome) nomes = criar_tabnomes();
	int tam = 0, op, op2, i;
	Empresa *emp;
	char str[256];
	printf("Carregando arquivo (pode demorar alguns minutos)...\n");
	while(fgets(str, 256, csv)){
		emp = criar_empresa(str);
		if(bcnpj) inserir_tab(emp, hash);
		if(bnome) tam = inserir_nome(emp, nomes, tam);
	}
	ordena_nomes(nomes, tam);
	
	printf("Arquivo carregado.\n");
	
	do{
		op = menu_principal();
		switch(op){
			case 1:
				if(bcnpj){
					do{
						op2 = menu_cnpj(hash);
					} while(op2 != -1);
				} else printf("Essa opcao nao esta disponivel\n");
				break;
			case 2:
				if(bnome){
					do{
						op2 = menu_nome(nomes, tam);
					} while(op2 != -1);
				} else printf("Essa opcao nao esta disponivel\n");
				break;
			default:
				break;
		}
	}while(op != 0);

	printf("\nEncerrando...\n");
	fclose(csv);
	if(bcnpj){
		for(i = 0; i < 100000000; i++){
			if(hash[i].emp != NULL) free(hash[i].emp);
		}
		free(hash);
		if(bnome) free(nomes);
	} else if(bnome){
		for(i = 0; i < tam; i++) free(nomes[i].emp);
		free(nomes);
	}

	return 0;
}
