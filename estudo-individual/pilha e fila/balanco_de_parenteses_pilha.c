#include <stdlib.h>
#include <stdio.h>

typedef struct s_LinkedNode LinkedNode;
typedef struct s_pilha Pilha;
struct s_LinkedNode 
{
	char item;
	LinkedNode *prox;
};
struct s_pilha{
	LinkedNode *topo;
	int qtd;
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
	Pilha pilhaA;
	pilhaA.topo = NULL;
	pilhaA.qtd = 0;

	Pilha pilhaF;
	pilhaF.topo = NULL;
	pilhaF.qtd = 0;
	char c=5;

		while(scanf("%c", &c)>0 && c!='\0'){
			if (c == ')'){
				empilhar(&pilhaF, c); pilhaF.qtd++;
			}else if(c == '('){
				empilhar(&pilhaA, c); pilhaA.qtd++;
			}
			if (pilhaF.qtd > pilhaA.qtd){
				printf("incorrect\n");
				exit(5);
			}
		}
		imprimePilha(&pilhaA);imprimePilha(&pilhaF);
		while(desempilhar(&pilhaA) && desempilhar(&pilhaF)){
			pilhaF.qtd--;
			pilhaA.qtd--;
		}
			
			if(pilhaA.qtd != pilhaF.qtd){
				printf("incorrect\n");
			}else{
				printf("correct\n");
			}
	}
	//imprimePilha(&pilhaA);imprimePilha(&pilhaF);

