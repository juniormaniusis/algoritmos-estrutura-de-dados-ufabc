#include <stdio.h>
#include <stdlib.h>
typedef struct s_duvida * duvida;
struct s_duvida{
	int ra;
	int codTop;
	duvida prox;

};
duvida criaDuvida(int ra, int codTop){
	duvida tmp = malloc(sizeof(struct s_duvida));
	if (!tmp) return NULL;
	tmp->ra = ra;
	tmp->codTop = codTop;
	tmp->prox = NULL;
	return tmp;
}
void imprimeDuvidas(duvida listaDuvidas){
	duvida tmp = listaDuvidas;
	while(tmp != NULL){
		printf("%d %d\n",tmp->ra, tmp->codTop);
		tmp = tmp->prox;
	}
	return;
}
void adicionaDuvida(duvida *inicio, duvida novaDuvida){
	if (inicio == NULL) return;
	if (*inicio == NULL){
		*inicio = novaDuvida;
		return;
	}
	duvida atual = *inicio;
	//procurar onde é o ultimo ra igual adcicionado e se não ouver adicionar no fim da lista
	while(atual->prox != NULL){
		if ((atual->ra == novaDuvida->ra) && (atual->prox->ra != novaDuvida->ra)){
			novaDuvida->prox = atual->prox;
			atual->prox = novaDuvida;
			return;
		}
		atual = atual->prox;
		
	}
		novaDuvida->prox = atual->prox;
		atual->prox = novaDuvida;
		return;
	
}
int main(void){
	int ra, codTop;
	scanf("%d", &ra);
	scanf("%d", &codTop);
	duvida listaDuvidas = NULL;
	while((ra != -1) && (codTop != -1)){
		adicionaDuvida(&listaDuvidas, criaDuvida(ra, codTop));
		scanf("%d", &ra);
		scanf("%d", &codTop);
		//imprimeDuvidas(listaDuvidas);

	}
	imprimeDuvidas(listaDuvidas);
	return 0;
}
