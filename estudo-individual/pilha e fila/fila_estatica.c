#include <stdlib.h>
#include <stdio.h>
typedef struct s_fila Fila;
struct s_fila
{
	int* itens;
	int tamanho;
	int inicio, fim;
};
void enfileirar(Fila *fila, int item){
	if (fila->fim == fila->tamanho -1){
		printf("Fila cheia!\n");
		return;
	}
	fila->itens[fila->fim] = item;
	fila->fim++;

	return;
}
int desenfileirar(Fila *fila){
	if (fila->fim == fila->inicio){
		printf("The queue is empty\n");
		fila->fim = 0;
		fila->inicio = 0;
		return -1;
	}
	int tmp = fila->itens[fila->inicio];
	fila->inicio++;
	return tmp;
}
void imprimir(Fila *fila){
	for (int i = fila->inicio; i < fila->fim; ++i){
		printf("%d ", fila->itens[i]);
	}printf("\n");
}
int main(){
	Fila fila;
	fila.tamanho = 5;
	fila.inicio = 0;
	fila.fim = 0;
	fila.itens = (int *) malloc(fila.tamanho*sizeof(int));
	enfileirar(&fila, 1);
	enfileirar(&fila, 2);
	enfileirar(&fila, 2);
	enfileirar(&fila, 45);
	enfileirar(&fila, 23);
	desenfileirar(&fila);
	imprimir(&fila);
	desenfileirar(&fila);
	imprimir(&fila);
	desenfileirar(&fila);
	imprimir(&fila);

	return 0;
}