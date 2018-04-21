#include <stdlib.h>
#include <stdio.h>
typedef struct TreeNode TreeNode;
struct TreeNode{
  int ra;
  int nota;
  TreeNode *pLeft, *pRight;
};
TreeNode * criaTreeNode(int ra, int nota){
  TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode));
  if (tmp == NULL) return NULL;
    tmp->pLeft = NULL;
    tmp->pRight = NULL;
    tmp->ra = ra;
    tmp->nota = nota;
    return tmp;
};
void inOrder(TreeNode *t){
  if(t == NULL) return;

    inOrder(t->pLeft);
    printf("%d ", t->ra);
    inOrder(t->pRight);
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
    }
    //fim do segundo caso

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
      if (node->ra == curr->ra){
        (curr)->nota = node->nota;
        return;
      } 

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

int main(){
  TreeNode *raiz = NULL;
  char operador;
  int ra, nota;
  scanf("\n%c", &operador);
  while(operador != 'P'){
    if (operador == 'I'){
      scanf("%d%d", &ra, &nota);
      adicionaTreeNode(&raiz, criaTreeNode(ra, nota));
    }else if (operador == 'R' || operador == 'B'){
      scanf("%d", &ra);
      if (operador == 'B'){
        printf("C=%d ",buscarTreeNode(raiz, ra, 1,&nota));
        printf("Nota=%d\n", nota);
      }
      if (operador == 'R'){
       // printf("raiz = %d\n", raiz->ra);
        removeTreeNode(&raiz, ra);
        //printf("raiz = %d\n", raiz->ra);
      }
    }else if (operador == 'A'){
      printf("A=%d\n", alturaArvore(raiz, -1));
     // inOrder(raiz);printf("\n");
    }

    //////////////////////////
    scanf("\n%c", &operador);
  }
  printf("\n");
  return 0;
}