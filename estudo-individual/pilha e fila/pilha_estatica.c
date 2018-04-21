#include <stdio.h>
#include <stdlib.h>
typedef struct spilha Pilha;
struct spilha{
	int topo;
	int *itens;
	int tamanho;
};
void empilhar(Pilha *pilha, int item){
	//pilha cheia?
	if (pilha->topo == pilha->tamanho - 1){
		printf("Pilha cheia!\n");
		return;
	}
	pilha->topo++;
	pilha->itens[pilha->topo] = item;
	printf("Empilhou\n");
	return;
}
int desempilhar(Pilha * pilha){
	if (pilha->topo == -1){
		printf("Pilha já está vazia!\n");
		return -5;
	}
	int tmp = pilha->itens[pilha->topo];
	pilha->topo--;
	return tmp;
}
void imprimir(Pilha *pilha){
	for (int i = 0; i <= pilha->topo; ++i)
	{
		printf("%d ", pilha->itens[i]);
	}printf("\n");
}
int main(){
	Pilha pilha;
	pilha.topo = -1;
	pilha.itens = (int *) malloc(5*sizeof(int));
	pilha.tamanho = 5;
	empilhar(&pilha, 1);
	empilhar(&pilha, 12);
	empilhar(&pilha, 2);
	empilhar(&pilha, 58);
	empilhar(&pilha, -2);
	empilhar(&pilha, 900);
	imprimir(&pilha);
	desempilhar(&pilha);
	imprimir(&pilha);
	desempilhar(&pilha);
	desempilhar(&pilha);
	desempilhar(&pilha);
	desempilhar(&pilha);
	desempilhar(&pilha);
	imprimir(&pilha);

	return 0;
}