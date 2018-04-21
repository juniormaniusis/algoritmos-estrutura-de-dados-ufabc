#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;
struct TreeNode{
	int value;
	TreeNode *pLeft, *pRight;
};

TreeNode * criaTreeNode(int value){
	TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode));
	if (tmp == NULL) return NULL;
	tmp->pLeft = NULL;
	tmp->pRight = NULL;
	tmp->value = value;
	return tmp;
}

void adicionaTreeNode(TreeNode **raiz, TreeNode *node){
	//se a arvore estiver vazia, então o node será a raiz da arvore.
	if (*raiz == NULL){
		*raiz = node;
		return;
	}
	TreeNode *curr = *raiz;
	
	while(curr != NULL){
		//caso o valor que quero adicionar seja maior que o valor que estou olhando agora.
		if(node->value > curr->value){
			if (curr->pRight == NULL){
				curr->pRight = node;
				return;
			}
			curr = curr->pRight;
		}
		//caso o valor que quero adicionar seja menor que o valor que estou olhando agora.
		if(node->value < curr->value){
			if (curr->pLeft == NULL){
				curr->pLeft = node;
				return;
			}
			curr = curr->pLeft;
		}
	}
	return;
};
void adicionaTreeNodeR(TreeNode **t, TreeNode *no){
	//casos base
	if (t == NULL) return;
	if (*t == NULL) {
		*t = no; 
		return;
	}

	///////////////
	if (no->value > (*t)->value){
		if ((*t)->pRight == NULL){
			(*t)->pRight = no;
			return;
		}
		adicionaTreeNodeR(&((*t)->pRight), no);
		return;
	}else{
		if ((*t)->pLeft == NULL){
			(*t)->pLeft = no;
			return;
		}
		adicionaTreeNodeR(&((*t)->pLeft), no);
		return;
	}
	return;
}		
	


TreeNode *insert(TreeNode *t, int value){
	if (t == NULL){
		return criaTreeNode(value);
	}
	if (value < t->value){
		t->pLeft = insert(t->pLeft, value);
	}else if (value > t->value){
		t->pRight = insert(t->pRight, value);
	}else{
		t->value = value;
	}
	return t;
};
void inOrder(TreeNode *t){
	if(t == NULL) return;
	inOrder(t->pLeft);
	printf("%d ", t->value);
	inOrder(t->pRight);

}
int max(TreeNode *t){
	if (t == NULL) return -1;
	int max = t->value;
	TreeNode *tmp = t;
	while(tmp->pRight != NULL)
		tmp = tmp->pRight;
	max = tmp->value;
}
int min(TreeNode *t){
	if (t == NULL) return -1;
	int min = t->value;
	TreeNode *tmp = t;
	while(tmp->pLeft != NULL)
		tmp = tmp->pLeft;
	min = tmp->value;
}
/* funções para o cálculo do sucessor e antecessor dum elemento. As suas funções devem
retornarNULLcaso o elemento não estiver na árvore ou não existir sucessor (caso do
máximo) o antecessor (caso do mínimo).*/
int sucessor(TreeNode *t, int item){
	TreeNode *tmp = t;
	/* raietornar o menor maior valor que item*/
	int suc = 99999;
	if (t == NULL) return 0;
	while(tmp != NULL){
		if (tmp->value < suc && tmp->value > item){
			suc = tmp->value;
		}
		if (tmp->value == item){
			tmp = tmp->pRight;
		}else if (tmp->value < item){
			tmp = tmp->pRight;
		}else if(tmp->value > item){
			tmp = tmp->pLeft;
		}
	}
	return suc;
}
int main(void){
	TreeNode *raiz = NULL;
	adicionaTreeNode(&raiz, criaTreeNode(-5));
	adicionaTreeNode(&raiz, criaTreeNode(5));
	adicionaTreeNode(&raiz, criaTreeNode(14));
	adicionaTreeNode(&raiz, criaTreeNode(10));
	adicionaTreeNode(&raiz, criaTreeNode(2));
	adicionaTreeNode(&raiz, criaTreeNode(7));
	adicionaTreeNode(&raiz, criaTreeNode(11));
	adicionaTreeNode(&raiz, criaTreeNode(-51));
	inOrder(raiz);
	printf("\n");
	printf("Max de t = %d\n", max(raiz));
	printf("Max de t = %d\n", min(raiz));
	printf("Sucessor = %d\n", sucessor(raiz, 1));
	return 0;
}