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
	duvida tmp = *inicio;
	while(tmp->prox != NULL)
		tmp = tmp->prox;
	tmp->prox = novaDuvida;
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
	}
	imprimeDuvidas(listaDuvidas);
	return 0;
}
