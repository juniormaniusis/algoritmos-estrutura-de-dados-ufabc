#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
11013216 Victor Lourenço Borges
11081816 Carlos Alberto Maniusis Junior


*/

typedef struct LinkedNode LinkedNode;

struct LinkedNode{
    int item;
    char *nome;
    int nota;
    LinkedNode * next;
};

LinkedNode *criaNo(int item,  char * nome,int nota){
    LinkedNode *tmp = (LinkedNode *) malloc(sizeof(LinkedNode));
    tmp->item = item;
    tmp->next = NULL;
    tmp->nota = nota;
    char *nome2 = malloc(50*sizeof(char));
    strcpy(nome2, nome);
    tmp->nome = nome2;
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
        printf("[%d %s %d]\n", tmp->item, tmp->nome, tmp->nota);
        tmp = tmp->next;
    }
}
int searchList(int item, LinkedNode* first) {
   int cont = 0;
   LinkedNode* curr = first; //ponteiro que percorre lista

    while (curr != NULL) {
      if (curr->item == item) 
        return cont; //retorna contador, que indica a posiçao
      ++cont;
      curr = curr->next;
    }
    return -1; //retorna erro, se nao foi encontrado
}

void freeList(LinkedNode* first) {
  LinkedNode* curr = first;
  LinkedNode* aux;
  while (curr!=NULL) {
    aux = curr;
    curr = curr->next;
    free(aux);
  }
}


int selectionSort(LinkedNode *ini, int modo){
    int comp = 0;
    LinkedNode * curr = ini;
    LinkedNode *menor = NULL;
    LinkedNode *aux = NULL;
    LinkedNode tmp;
    

    while(curr->next != NULL){
        menor = curr;
        aux = curr->next;
        if (modo == 1){
            while(aux != NULL){//achando sucessor
                if (menor->item > aux->item){
                    menor = aux;
                }
                comp++;
                aux = aux->next;
            }
            //trocar aux e ini
            tmp.item = menor->item;
            tmp.nome = menor->nome;
            tmp.nota = menor->nota;
            menor->item = curr->item;
            menor->nome = curr->nome;
            menor->nota = curr->nota;

            curr->item = tmp.item;
            curr->nome = tmp.nome;
            curr->nota = tmp.nota;
            curr = curr->next;
        }
        if (modo == 2){
            while(aux != NULL){//achando sucessor
                if (strcmp(menor->nome, aux->nome) > 0){
                    menor = aux;
                }
                comp++;
                aux = aux->next;
            }
            //trocar aux e ini
            tmp.item = menor->item;
            tmp.nome = menor->nome;
            tmp.nota = menor->nota;
            menor->item = curr->item;
            menor->nome = curr->nome;
            menor->nota = curr->nota;

            curr->item = tmp.item;
            curr->nome = tmp.nome;
            curr->nota = tmp.nota;
            
            curr = curr->next;
        } 

    }
    return comp;
}
int insertionSort(LinkedNode* first, int modo) {
    LinkedNode* key = malloc(sizeof(LinkedNode));
    LinkedNode* curr = first->next;
    int i = 1;
    int j;
    int compara = 0;
    LinkedNode* back;

    while(curr!=NULL) {
        int k = i-1;
        int mud = 0;
        key->item = curr->item;
        key->nota = curr->nota;
        key->nome = curr->nome;
        back = first;

        while (k >= 0) {
            back = first;
            for (j=0; j<k; ++j) {
                back = back->next;     
            }
            ++compara;
            if (modo==1) {
                if (key->item < back-> item) {
                    mud = 1;
                    back->next->item = back->item;
                    back->next->nota = back->nota;
                    back->next->nome = back->nome;
                } else {
                    break;
                } 
            } 
            if (modo==2) {
                int v = strcmp (key->nome, back->nome);
                if (v < 0) {
                    mud = 1;
                    back->next->item = back->item;
                    back->next->nota = back->nota;
                    back->next->nome = back->nome;
                } else {
                    break;
                } 
            }
            k--; 
        }

        if (k==-1&& mud==1) {
            back->item = key->item;
            back->nota = key->nota;
            back->nome = key->nome;
        } 
        else if(k!=-1 && mud==1) { 
            back->next->item = key->item;
            back->next->nota = key->nota;
            back->next->nome = key->nome;
        } 
        ++i;
        curr = curr->next;
    }
    return compara;
}

int main(){
    LinkedNode *inicio = NULL;
  char *nome, operador;
  int ra, nota;
  int tipoBusca, algBusca;
  scanf("\n%c", &operador);
  while(operador != 'P'){
    switch(operador){
        case 'I':
            scanf("\n%d", &ra);
            scanf("\n%s", nome);
            scanf("\n%d", &nota);
            adicionaFinalLista(&inicio, criaNo(ra, nome, nota));
            break;
        case 'O':
            scanf("\n%d", &algBusca);
            scanf("\n%d", &tipoBusca);
            if (algBusca == 1)
                printf("Comparacoes=%d\n",selectionSort(inicio, tipoBusca));
            if (algBusca == 2)
                printf("Comparacoes=%d\n",insertionSort(inicio, tipoBusca));
            break;
        case 'B':
            scanf("\n%d", &ra);
            printf("Pos=%d\n",  searchList(ra, inicio));
            break;
        case 'M':
            imprimeLista(inicio);
            break;
        case 'P':
            freeList(inicio);
            break;


    }
    scanf("\n%c", &operador);
  }
 

    return 0;
}
