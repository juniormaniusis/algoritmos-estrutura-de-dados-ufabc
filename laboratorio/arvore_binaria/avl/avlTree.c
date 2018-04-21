#include <stdlib.h> 
#include <stdio.h> 

typedef struct TreeNode TreeNode; 

struct TreeNode{ 

  int ra; 

  int nota; 

  TreeNode *pLeft, *pRight; 

  int Fb; 
}; 

int alturaArvore(TreeNode *t, int altura);
TreeNode * criaTreeNode(int ra, int nota);
void removeTreeNode(TreeNode **t, int ra);
void atualizaBalanceamento(TreeNode **raiz);
void inOrder(TreeNode **t);
int buscarTreeNode(TreeNode *t, int ra, int comparacoes, int* nota);
void rotateLeft(TreeNode **raiz);
void rotateRight(TreeNode **raiz);
void adicionaTreeNode(TreeNode **raiz, TreeNode *node);


int alturaArvore(TreeNode *t, int altura){
  if (t == NULL) return altura; 
  altura++; 
  int left = alturaArvore(t->pLeft, altura); 
  int right = alturaArvore(t->pRight, altura); 
  if (left > right){ 
    return left; 
  }else{ 
    return right; 
  } 
}; 

TreeNode * criaTreeNode(int ra, int nota){ 
  TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode)); 
  if (tmp == NULL) return NULL; 
    tmp->pLeft = NULL; 
    tmp->pRight = NULL; 
    tmp->ra = ra; 
    tmp->nota = nota; 
    tmp->Fb = 0; 
    return tmp; 
}; 
void removeTreeNode(TreeNode **t, int ra){
  /*
  #BUSCAR O NÓ QUE QUERO DELETAR
  */
  if (t == NULL) return; //ALGUM ERRO
  if (*t == NULL) return;
  if ((*t)->ra > ra){
    removeTreeNode(&((*t)->pLeft), ra);
  }else if ((*t)->ra < ra){
    removeTreeNode(&((*t)->pRight), ra);
  }else{
    //sao iguais
    TreeNode *filhoEsq, *filhoDir;
    filhoDir = (*t)->pRight;
    filhoEsq = (*t)->pLeft;
    //PRIMEIRO CASO, OS DOIS FILHOS SAO NULOS
    if (filhoEsq == NULL && filhoDir == NULL){
      free(*t);
      *t = NULL;
      return;
    }
    //fim do primeiro caso
    //SEGUNDO CASO, UM DOS FILHOS É NULO.
    if ((filhoDir == NULL && filhoEsq != NULL)){
      TreeNode *tmp = *t;
      *t = filhoEsq;
      free(tmp);
      return;
    }else if (filhoDir != NULL && filhoEsq == NULL){
      TreeNode *tmp = *t;
      *t = filhoDir;
      free(tmp);
      return;   
    //fim do segundo caso
    }else if ((filhoDir != NULL && filhoEsq != NULL)){
      //caso 3 (caso dificil)
      //aqui nós encontramos o nó que eu quero remover
      //devemos buscar o sucessor
      TreeNode *sucessor = filhoDir;
      while(sucessor->pLeft != NULL){
        sucessor = sucessor->pLeft;
      }
      int ra = sucessor->ra;
      int nota = sucessor->nota;
      removeTreeNode(t,sucessor->ra);
      (*t)->ra = ra;
      (*t)->nota = nota;
      return;
    }
    //caso nao removeu
    if ((*t)->Fb == 2){
      if (filhoEsq->Fb < 0){
        printf("r left\n");
        rotateLeft(&((*t)->pLeft));
        printf("r right\n");
        rotateRight(t);
      }
    }
  }
}
void atualizaBalanceamento(TreeNode **raiz){
  (*raiz)->Fb = alturaArvore((*raiz)->pLeft,-1) - alturaArvore((*raiz)->pRight,-1);
  return;
}
void inOrder(TreeNode **t){ 
  if(t == NULL) return; 
  if (*t == NULL){
    printf("-");
    return;
  } 
   atualizaBalanceamento(t);
    inOrder((&(*t)->pLeft)); 
    printf("%d(%d)", ((*t)->ra), ((*t)->Fb)); 
    inOrder((&(*t)->pRight)); 
}; 
int buscarTreeNode(TreeNode *t, int ra, int comparacoes, int* nota){ 
  if (t == NULL){ 
    *nota = -1; 
    return comparacoes-1; 

  } 
  if (t->ra == ra){ 
    *nota = t->nota; 
    return comparacoes; 
  } 
  comparacoes++; 
  if (t->ra > ra){ 
    return buscarTreeNode(t->pLeft, ra, comparacoes, nota); 
  } 
  if (t->ra < ra){ 
    return buscarTreeNode(t->pRight, ra, comparacoes, nota); 
  } 
}; 

void rotateLeft(TreeNode **raiz){
  TreeNode *tmp = (*raiz)->pRight;
  (*raiz)->pRight = tmp->pLeft;
  tmp->pLeft = *raiz;
  atualizaBalanceamento(raiz);
  *raiz = tmp;
  atualizaBalanceamento(raiz);
  return;
}
void rotateRight(TreeNode **raiz){
  TreeNode *tmp = (*raiz)->pLeft;
  (*raiz)->pLeft = tmp->pRight;
  tmp->pRight = (*raiz);
  atualizaBalanceamento(raiz);
  (*raiz) = tmp;
  atualizaBalanceamento(raiz);
  return;
}
void adicionaTreeNode(TreeNode **raiz, TreeNode *node){
  //recursiva
  //caso base
  if (raiz == NULL){//neste caso, ocorreu algum erro.
    fprintf(stderr, "ERRO\n");
    return;
  }
  if (*raiz == NULL){
    //adicionar elemento
    *raiz = node;
    atualizaBalanceamento(raiz);
    return;
  }
  if ((*raiz)->ra > node->ra){
    adicionaTreeNode(&((*raiz)->pLeft), node);

  }else if (((*raiz)->ra < node->ra)){
    adicionaTreeNode(&((*raiz)->pRight), node);
  }
  atualizaBalanceamento(raiz);
  //deve chegar se está desbalanceado
  if ((*raiz)->Fb == 2){
    printf("Rr\n");
    rotateRight(raiz);
  }
  if ((*raiz)->Fb == -2){
    printf("Rl\n");
    rotateLeft(raiz);
  }
  atualizaBalanceamento(raiz);
};

int main(){ 
  TreeNode *raiz = NULL; 
  char operador; 
  int ra, nota; 
  /*scanf("\n%c", &operador); 
  while(operador != 'P'){ 
    if (operador == 'I'){ 
      scanf("%d%d", &ra, &nota); 
      adicionaTreeNode(&raiz, criaTreeNode(ra, nota)); 
    }else if (operador == 'R' || operador == 'B'){ 
      scanf("%d", &ra); 
      if (operador == 'B'){ 
        printf("C=%d",buscarTreeNode(raiz, ra, 1,&nota)); 
        printf("Nota=%d\n", nota); 
      } 
      if (operador == 'R'){ 
        removeTreeNode(&raiz, ra);
      } 
    }else if (operador == 'A'){ 
      printf("A=%d\n", alturaArvore(raiz, -1)); 
      inOrder(&raiz);printf("\n" ); 
    } 

    ////////////////////////// 
    scanf("\n%c", &operador); 
  } */
  adicionaTreeNode(&raiz, criaTreeNode(5, nota));
  adicionaTreeNode(&raiz, criaTreeNode(4, nota));
  adicionaTreeNode(&raiz, criaTreeNode(3, nota));
  adicionaTreeNode(&raiz, criaTreeNode(2, nota));
  adicionaTreeNode(&raiz, criaTreeNode(8, nota));
  adicionaTreeNode(&raiz, criaTreeNode(9, nota));
  adicionaTreeNode(&raiz, criaTreeNode(10, nota));
  inOrder(&raiz);
  return 0; 
} 