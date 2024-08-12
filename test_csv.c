#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct string{
	bool valid;
	char str[256];
};
typedef struct string String;

void check_valid(char *str, String *valid){
	char str2[256];
	memcpy(str2, str, 256);
	char *pt = strtok(str, "\"");
	int index = atoi(pt);
	valid[index].valid = 1;
	memcpy(valid[index].str, str2, 256);
}

String *create_matrix(void){
       	String *valid = (String*)malloc(100000000 * sizeof(String));
	int i = 0;
	while(i < 100000000){
		valid[i].valid = false;
		i++;
	}
	return valid;
}

int main(){
	FILE *csv = fopen("./Empresas0.csv", "r");

	printf("Criando matriz...\n");
       	String *valid = create_matrix();
	int i = 0;
	int search;

	char str[256];
	printf("Carregando arquivo...\n");
	while(fgets(str, 256, csv)){
		check_valid(str, valid);
	}
	printf("Arquivo carregado.\n");
	
	printf("Buscar CNPJ: ");
	scanf("%d", &search);

	if(valid[search].valid) printf("%s", valid[search].str);
	else printf("CNPJ nao encontrado.\n");

	fclose(csv);
	free(valid);
	printf("Encerrando...\n");

	return 0;
}
