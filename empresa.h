#ifndef _empresa_h_
#define _empresa_h_

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

Empresa *criar_empresa(char *str);

void mostrar_empresa(Empresa *emp);

#endif
