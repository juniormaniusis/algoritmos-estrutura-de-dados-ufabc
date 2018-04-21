	#include <stdio.h>
	#include <stdlib.h>
	/*
		printf("%f\n", aplicaOperador(1, 1, 1, '+'));
		printf("%f\n", aplicaOperador(1, 1, 1, '-'));
		printf("%f\n", aplicaOperador(1, 1, 1, 'h'));
		printf("%f\n", aplicaOperador(1, 1, 1, 'f'));
		printf("%f\n", aplicaOperador(1, 1, 1, 'g'));

	*/
	typedef struct LinkedNode LinkedNode;
	struct LinkedNode {
		double item;
		LinkedNode *next;
	};	
	typedef struct Pilha Pilha;
	struct Pilha {
		LinkedNode* topo;
	};
	double aplicaOperador(double n1, double n2, double n3, char op){
		//operador h
		//[n1]h -> n1 x 3 

		//f [n1][n2][n3]f -> (n1 x n1) - ((n2) / 2) + n3

		//g [n1][n2][n3]g (n1 x n2) + n3 
		switch(op){
			case 'h':
				return (n1*3);
				break;
			case '+':
				return (n1+n2);
				break;
			case '-':
				return (n1-n2);
				break;
			case 'f':
				return ((n1 * n1) - ((n2) / 2) + n3);
				break;
			case 'g':
				return ((n1 * n2) + n3 );
				break;

		}
	}
	int eOperador(char c){
		if (c == '+' || c == '-' || c == 'f' || c == 'g' || c == 'h'){
			return 1;
		}
		return 0;
	}
	void printErro(){
		printf("ERRO\n");
	}
	void empilhar(Pilha *p, LinkedNode *no){
		if (p == NULL) return;
		if (p->topo == NULL){
			p->topo = no;
			return;
		}
		no->next = p->topo;
		p->topo = no;
	}
	double desempilhar(Pilha *p){
		double tmp2;
		if (p == NULL || p->topo == NULL) {
			printErro();
			exit(0);
			return -1;
		}

		LinkedNode *tmp = (p->topo);
		tmp2 = tmp->item;
		p->topo = p->topo->next;
		
		free(tmp);

		return tmp2;
	}
	void imprimePilha(Pilha p){
		LinkedNode *tmp = p.topo;
		while(tmp != NULL){
			printf("%.2lf\n", tmp->item);
			tmp = tmp->next;
		}
	}
	LinkedNode * criaNo(double item){
		LinkedNode *n = malloc(sizeof(LinkedNode));
		n->item = item;
		return n;
	}

	int numArgumentos(char op){
		switch(op){
				case 'h':
				return 1;
				break;
			case '+':
				return 2;
				break;
			case '-':
				return 2;
				break;
			case 'f':
				return 3;
				break;
			case 'g':
				return 3;
				break;
		}
	}
	int main(void){
		Pilha *pilha = malloc(sizeof(Pilha));
		char *sentenca = malloc(sizeof(char)*100);
		scanf("%s", sentenca);
		//printf("%s\n", sentenca);
		int cont_num_lidos;
		int scanner = 0;
		char operador;
		double *resultado, aux, aux2;
		double *num = (double *) malloc(3*sizeof(double));
		while(sentenca[scanner] != '\0'){
			cont_num_lidos = 0;
			while(!eOperador(sentenca[scanner])){
				num[cont_num_lidos] =  sentenca[scanner] - '0';
				if (cont_num_lidos > 3) {
						printErro();
						exit(0);
				}
				cont_num_lidos++;
				scanner++;
			}
				operador = sentenca[scanner];



				if (numArgumentos(operador)>cont_num_lidos){
					//argumentos necessários = numArg - num_lidos
					
					switch(numArgumentos(operador)-cont_num_lidos){
						case 1: 
							aux = num[0];
							aux2 = num[1];
							num[0] = desempilhar(pilha);
							num[1] = aux;
							num[2] = aux2;

							break;
						case 2: 
							aux = num[0];
							num[1] = desempilhar(pilha);
							num[0] = desempilhar(pilha);
							num[2] = aux;
							break;
						case 3:
							aux = num[0];
							num[0] = desempilhar(pilha);
							num[1] = desempilhar(pilha);
							num[2] = desempilhar(pilha);
							 break;

					}
		

					empilhar(pilha, criaNo(aplicaOperador(num[0], num[1], num[2], sentenca[scanner])));

				}else{

					empilhar(pilha, criaNo(aplicaOperador(num[0], num[1], num[2], sentenca[scanner])));
				}
				//printf("SCANNER = %d N1= %.2f N2= %.2f N3= %.2f \n",scanner, num[0], num[1], num[2] );
				//printf("operação: %c lidos: %d res:%f\n",operador, cont_num_lidos, aplicaOperador(num[0], num[1], num[2], sentenca[scanner]) );
				//adiciona resultado na pilha
				//tem argumentos suficientes?
				//se nao tiver resgatar da pilha
				//printf("empilhou\n");
				//imprimePilha(*pilha);
				
				scanner++;
		}
		if (scanner == 0){
			printErro();
			exit(0);
		}
		if(pilha->topo == NULL){
			printErro();
			exit(0);		
		}
		if(pilha->topo->next != NULL){
			printErro();
			exit(0);		
		}

		imprimePilha(*pilha);

		return 0;
	}	