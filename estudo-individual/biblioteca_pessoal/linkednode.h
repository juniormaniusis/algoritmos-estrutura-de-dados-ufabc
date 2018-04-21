typedef struct LinkedNode LinkedNode;
struct LinkedNode{
	int item;
	LinkedNode * next;
};
LinkedNode *criaNo(int item){
	LinkedNode *tmp = (LinkedNode *) malloc(sizeof(LinkedNode));
	tmp->item = item;
	tmp->next = NULL;
	return tmp;
};
LinkedNode *noFinal(LinkedNode *inicio){
	LinkedNode *curr = inicio;
	if (curr == NULL) return NULL;
	while(curr->next != NULL)
		curr = curr->next;
	return curr;	
}
void adicionarInicioLista( LinkedNode **inicio, LinkedNode *no){
	no->next = *inicio;
	*inicio = no;
	return;
}
void adicionaFinalLista(LinkedNode **inicio, LinkedNode *no){
	if (*inicio == 0){
		*inicio = no;
		return;
	}
	noFinal(*inicio)->next = no;
	return;
};
void imprimeLista(LinkedNode *inicio){
	LinkedNode *tmp = inicio;
	while(tmp != NULL){
		printf("%d ", tmp->item);
		tmp = tmp->next;
	}
	printf("\n");
}
LinkedNode *leSequenciaLinkedListInt(int tamanho){
	LinkedNode *inicio;
	int num;
	for (int i = 0; i < tamanho; ++i)
	{
		scanf("%d", &num);
		adicionaFinalLista(&inicio, criaNo(num));
	}
	return inicio;
}