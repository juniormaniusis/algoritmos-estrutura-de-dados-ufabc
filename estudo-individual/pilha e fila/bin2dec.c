#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct sPilha Pilha;
typedef struct sNode LinkedNode;
struct sPilha{
	LinkedNode * topo;
	int qtd;
};
struct sNode{
	int item;
	LinkedNode *prox;
};
void empilhar(Pilha *pilha, char item){
	LinkedNode *tmp = (LinkedNode *) malloc(sizeof(LinkedNode));
	if (!tmp) return; // deu erro ao alocar memória
	tmp->item = item;
	tmp->prox = pilha->topo;
	pilha->topo = tmp;
	return;
}
LinkedNode *desempilhar(Pilha *pilha){
	if (pilha->topo == NULL) return NULL; //não existe nada pra desempilhar
	LinkedNode *tmp = pilha->topo;
	pilha->topo = pilha->topo->prox;
	return tmp; // poderia dar um free(tmp) e retornar NULL, depende do que quer fazer.

}
void imprimePilha(Pilha *pilha){
	if (!pilha) return;
	LinkedNode *tmp = pilha->topo;
	while(tmp != NULL){
		printf("%c", tmp->item);
		tmp = tmp->prox;
	}printf("\n");
	return;
}
int main(){
	printf("pow %f\n",pow(2,3) );
	Pilha pilha;
	pilha.topo = NULL;
	pilha.qtd = 0;
	char c;
	char eZero;
	scanf("%c", &c);
	eZero = c;
	while(c != 'b'){
		if (c != '0'){
			eZero = 0;
		}
		if (!eZero){
			empilhar(&pilha, c);
			pilha.qtd++;
		}
		scanf("%c", &c);

	}
	double num = 0;
	int temp = 0;
	int cont = 0;
	imprimePilha(&pilha);
	while (cont < pilha.qtd){
		temp = (int) (desempilhar(&pilha)->item) - '0';
		printf("desempilhado: %d num=%f", temp, num);
		num += temp*pow( 2, cont++);
		imprimePilha(&pilha);
	}
	printf("%f\n", num);
	imprimePilha(&pilha);
	return 0;
}