# B1
Utiliza uma hash table para a busca por CNPJ e um vetor ordenado para busca por nomes.
OBS: É mais rápida, porém ocupa mais memória.
## Compilação:
```
gcc -o b1 b1.c nome.c hash.c empresa.c
```
## Utilização:
```
./b1 <opcoes>
```
## Opções:
```
--cnpj: gera só a tabela hash;
--nomes: gera só o vetor ordenado com nomes;
```

# B2
Utiliza um vetor, que pode ser ordenado para busca por nomes e busca por cnpj.
OBS: Ocupa menos memória, porém exige ordenação na hora da escolha da busca, portanto é mais lenta.
## Compilação:
```
gcc -o b2 b2.c nome.c empresa.c
```
## Utilização:
```
./b2
```

# OBS.:
O arquivo Empresas0.csv deve estar na pasta raiz.
