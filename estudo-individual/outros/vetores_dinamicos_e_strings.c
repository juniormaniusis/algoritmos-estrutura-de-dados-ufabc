#include <stdio.h>
#include <stdlib.h>
//1.Inverter um vetor (sem criar um novo).
void inverteVetor(int vetor[], int n){
	int aux;
	int i = 0;
	while(i<n/2){
		aux = vetor[n - i-1];
		vetor[n - 1-i] = vetor[i];
		vetor[i] = aux;
		i++;
	}
	return;
}
void imprimeVetor(int v[], int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", v[i]);
	}printf("\n");
}
/*2.Inserir um elemento na posição i do arranjo. Caso o valor dei exceda o número de
elementos do vetor (porém não o tamanho) insira na posiçãoi, preencha com zero os
elementos intermediários e atualize o número de elementos. Caso o valor dei exceda o
tamanho do vetor, crie (se possível) um novo vetor com tamanho apropriado e insira
como explicado anteriormente.*/

void separaParImpar(int v[], int num){
	int contPar = 0;
	int contImpar = 0;

	for (int i = 0; i < num; ++i)
	{
		if (*(v + i) != 0){
			if (*(v + i)%2 == 0){
				contPar++;
			}else{
				contImpar++;
			}
		}
	}
	int pares[contPar];
	int impares[contImpar];
	int a = 0, b = 0;
	for (int i = 0; i < num; ++i){
		if (*(v + i) != 0 ){
			(*(v + i))%2 == 0 ? (pares[a++] = *(v + i)) : (impares[b++] = *(v + i));
		}
	}
	imprimeVetor(pares, contPar);
	imprimeVetor(impares, contImpar);
}


//concatenar duas strings
char * concatenar(char *s1,int n1, char *s2, int n2){
	char *s = malloc((n1+n2)*sizeof(char));
	int i = 0;
	int j = 0;
	for (int i = 0; i < (n1+n2); ++i)
	{
		if (i < n1){
			s[i] = s1[i];
		}else{
			s[i] = s2[j++];
		}
	}
	return s;
}
char * concatenar2(char *s1, char *s2){
	int cont = 0;
	int i = 0;
	char * tmp = s2;
	while (*(tmp)){
		cont++;
		tmp++;
	}
	tmp = s1;
	while (*(s1++)){
		cont++;
	}
	
	printf("%d\n", cont);
	char *s = malloc(cont*sizeof(char));
	while (*(s1++)){

		s[i] = s1[i];
		i++;
	}
	int j  = 0;
	while (*(s2++)){
		s[i] = s2[j++];
		i++;
	}
	return s;
}

int main(){
	printf("%s\n", concatenar2("1\0","a\0"));
	
	return 0;
}
