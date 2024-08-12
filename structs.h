#ifndef _structs_

#include <stdbool.h>

struct empresa{
	int cnpj;
	char nome[200];
	int natjur;
	int qual;
	float cap;
	int porte;
	int fed;
};
typedef struct empresa Empresa;

struct hash{
	Empresa *emp;
};
typedef struct hash Hash;

struct nome{
	char nome[200];
	Empresa *emp;
}
typedef struct nome Nome;
