#ifndef _nome_h_
#define _nome_h_

#include "empresa.h"

struct nome{
	Empresa *emp;
}
typedef struct nome Nome;

Nome *criar_tabnomes();
int inserir_nome(Empresa *emp, Nome *nomes, int tam);
void ordena_nomes(Nome *nomes, int tam);

#endif
