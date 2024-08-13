#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"

void itos(int i, char *s){
	s[0] = i/10000000 + '0';
	s[1] = (i%10000000)/1000000 + '0';
	s[2] = (i%1000000)/100000 + '0';
	s[3] = (i%100000)/10000 + '0';
	s[4] = (i%10000)/1000 + '0';
	s[5] = (i%1000)/100 + '0';
	s[6] = (i%100)/10 + '0';
	s[7] = i%10 + '0';
}

void completar_cnpj(int cnpj, char *cnpjstr){
	int d1 = 0, d2 = 0, i;
	char c1[9];
	int pesos[] = {6,5,4,3,2,9,8,7,6,5,4,3,2};
	itos(cnpj, c1);
	for(i = 0; i < 8; i++){
		d1 += (c1[i] - '0') * pesos[i+1];
	}
	d1 += 2;
	d1 = 11 - (d1 % 11);
	d1 *= (d1 <= 9);
	for(i = 0; i < 8; i++){
		d2 += (c1[i] - '0') * pesos[i];
	}
	d2 += 3 + d1 * 2;
	d2 = 11 - (d2 % 11);
	d2 *= (d2 <= 9);
	sprintf(cnpjstr, "%02d.%03d.%03d/0001-%d%d", cnpj/1000000, (cnpj%1000000)/1000, cnpj%1000, d1, d2);
}

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
	char cnpjstr[19];
	completar_cnpj(emp->cnpj, cnpjstr);
	printf("CNPJ (8d): %s\nNome: %s\nNat. juridica: %d\nQual. do responsavel: %d\nCapital social: %f\nPorte: %d\nEnte fed.:%d\n", cnpjstr, emp->nome, emp->natjur, emp->qual, emp->cap, emp->porte, emp->fed);
}
