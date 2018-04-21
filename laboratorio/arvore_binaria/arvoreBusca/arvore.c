#include <stdlib.h>
#include <stdio.h>
//defrinição das estruturas
typedef struct TreeNode TreeNode;
struct TreeNode{
	int ra;
	TreeNode *pLeft, *pRight;
};
typedef struct LinkedNode LinkedNode;
struct LinkedNode{
	int ra;
	LinkedNode * next;
};

LinkedNode *criaNo(int ra){
	LinkedNode *tmp = (LinkedNode *) malloc(sizeof(LinkedNode));
	tmp->ra = ra;
	tmp->next = NULL;
	return tmp;
};
void imprimeLista(LinkedNode *inicio){
	LinkedNode *tmp = inicio;
	while(tmp != NULL){
		printf("%d ", tmp->ra);
		tmp = tmp->next;
	}
	printf("\n");
}

TreeNode * criaTreeNode(int ra){
	TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode));
	if (tmp == NULL) return NULL;
	tmp->pLeft = NULL;
	tmp->pRight = NULL;
	tmp->ra = ra;
	return tmp;
}

void adicionaTreeNodeR(TreeNode *t, TreeNode *no){
	if (t == NULL){
		t = no;
		return;
	}
	if (t->ra < no->ra){
		adicionaTreeNodeR(t->pRight, no);
	}else{
		adicionaTreeNodeR(t->pLeft, no);
	}
};
//imprime a arvore
void inOrder(TreeNode *t){
	if(t == NULL) return;
	inOrder(t->pLeft);
	printf("%d ", t->ra);
	inOrder(t->pRight);
}
int buscarTreeNode(TreeNode *t, int ra, int cont){
	if (t == NULL){
		return cont;
	}
	if (t->ra == ra){
		return ++cont;
	}
	if (ra > t->ra){
		cont++;
		return buscarTreeNode(t->pRight, ra, cont);
	}
	if (ra < t->ra){
		cont++;
		return buscarTreeNode(t->pLeft, ra, cont);
	}

}
LinkedNode *noFinal(LinkedNode *inicio){
	LinkedNode *curr = inicio;
	if (curr == NULL) return NULL;
	while(curr->next != NULL)
		curr = curr->next;
	return curr;	
}
void adicionaLinkedNodeOrdenado(LinkedNode **inicio, LinkedNode *no){
	if (*inicio == NULL){
		*inicio = no;
		return;
	}
	LinkedNode *tmp = *inicio, *anterior = NULL;;

	if (no->ra < tmp->ra){
		no->next = *inicio;
		*inicio = no;
		return;
	}
	while(tmp->next != NULL){
		if (no->ra == tmp->ra) return;
		if (no->ra < tmp->next->ra){
			no->next = tmp->next;
			tmp->next = no;
			return;
		}
		tmp = tmp->next;
	}
	no->next = tmp->next;
	tmp->next = no;
	return;
};

void adicionaTreeNode(TreeNode **raiz, TreeNode *node){
	//se a arvore estiver vazia, então o node será a raiz da arvore.
	if (*raiz == NULL){
		*raiz = node;
		return;
	}
	TreeNode *curr = *raiz;
	
	while(curr != NULL){
		//caso o valor que quero adicionar seja maior que o valor que estou olhando agora.
		if (node->ra == curr->ra) return;
		if(node->ra > curr->ra){
			if (curr->pRight == NULL){
				curr->pRight = node;
				return;
			}
			curr = curr->pRight;
		}
		//caso o valor que quero adicionar seja menor que o valor que estou olhando agora.
		if(node->ra < curr->ra){
			if (curr->pLeft == NULL){
				curr->pLeft = node;
				return;
			}
			curr = curr->pLeft;
		}
	}
	return;
};

int buscaLista(LinkedNode *inicio, int ra){
	LinkedNode *tmp = inicio;
	int comp = 0;
	while(tmp != NULL){

		if (tmp->ra == ra){
			comp++;
			return comp;
		}
		if (ra < tmp->ra){
			comp++;
			return comp;
		}
			comp++;
		tmp = tmp->next;
	}

	return comp;
}
int main(){
	char operador;
	int ra;
	TreeNode *raiz = NULL;
	LinkedNode *inicio = NULL;
	scanf("\n%c %d", &operador, &ra);
	while(operador != 'P' && ra != 0){
		if (operador == 'I'){
			adicionaTreeNode(&raiz, criaTreeNode(ra));
			adicionaLinkedNodeOrdenado(&inicio, criaNo(ra));	
		}else if (operador == 'B'){
			//printf("B %d\n", ra);
			printf("L=%d A=%d\n", buscaLista(inicio, ra),buscarTreeNode(raiz, ra, 0));
		}
		if (operador == 'Z')
		{
			imprimeLista(inicio);
		}
		scanf("\n%c %d", &operador, &ra);
	}

	return 0;
}