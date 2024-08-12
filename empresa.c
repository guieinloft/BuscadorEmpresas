#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"

Empresa *criar_empresa(char *str){
	Empresa *emp = (Empresa*)malloc(sizeof(Empresa));
	char *pt = strtok(str, "\";\n");
	emp->cnpj = atoi(pt);
	pt = strtok(NULL, "\";\n");
	strcpy(emp->nome, pt);
	pt = strtok(NULL, "\";\n");
	emp->natjur = atoi(pt);
	pt = strtok(NULL, "\";\n");
	emp->qual = atoi(pt);
	pt = strtok(NULL, "\";\n");
	emp->cap = atof(pt);
	pt = strtok(NULL, "\";\n");
	emp->porte = atoi(pt);
	pt = strtok(NULL, "\";\n");
	if(pt != NULL) emp->fed = atoi(pt);
	else emp->fed = 0;
	return emp;
}

void mostrar_empresa(Empresa *emp){
	printf("CNPJ (8d): %d\nNome: %s\nNat. juridica: %d\nQual. do responsavel: %d\nCapital social: %f\nPorte: %d\nEnte fed.:%d\n", emp->cnpj, emp->nome, emp->natjur, emp->qual, emp->cap, emp->porte, emp->fed);
}
