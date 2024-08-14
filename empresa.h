#ifndef _empresa_h_
#define _empresa_h_

struct empresa{
	int cnpj;
	char nome[180];
	short natjur;
	short qual;
	float cap;
	short porte;
	short fed;
};
typedef struct empresa Empresa;

void completar_cnpj(int cnpj, char *cnpjstr);

Empresa *criar_empresa(char *str);

void mostrar_empresa(Empresa *emp);

#endif
