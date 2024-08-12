#ifndef _hash_h_
#define _hash_h_

#include "empresa.h"

struct hash{
	Empresa *emp;
};
typedef struct hash Hash;

Hash *criar_tabela();

void inserir_tab(Empresa *emp, Hash *hash);

#endif
