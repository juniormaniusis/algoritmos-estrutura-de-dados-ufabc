#include <stdio.h>
#include <stdlib.h>
/*
2 Agenda de Contatos
Escreva um programa para gerenciar uma agenda de contatos. Para cada contato deve-se
armazenarNome,Telefone e Email. Seu programa deve dar as seguintes opções ao usuário:
Inserir um contato no final da agenda,Buscar dados pelo Nome,Buscar dados pelo
Telefone,Mostrar Agenda e Sair.
*/


typedef struct s_contato *contato;
struct s_contato{
	char *nome;
	char *telefone; 
	char *email;
	contato prox;
};
//cria um novo contato (não adiciona na agenda)
contato novoContato(char nome[], char telefone[], char email[]){
	contato c = (contato) malloc(sizeof(struct s_contato));
	if (!novoContato){
		fprintf(stderr, "%s\n", "Erro ao alocar memória.");
		exit(1);
	}
	c->nome = nome;
	c->telefone = telefone;
	c->email = email;
	c->prox = NULL;
	return c;
}
void imprimeAgenda(contato inicio){
	if (inicio == NULL) return;

	contato x = inicio;
	while (x != NULL){
		printf("Nome:\t%s\nFone:\t%s\nEmail:\t%s\n\n",x->nome, x->telefone, x->email );
		x = x->prox;
	}
	return;
}
int comparaString(char s1[], char s2[]){
	int i = 0;
	while ((s1[i] != '\0')  && (s2[i] != '\0')) {
		if (s1[i] == s2[i]){
			i++;
		}else{
			return 0;
		}
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return 1;
	else
		return 0;
}
void adicionarContato(contato *agenda, contato novoContato){
	if (novoContato == NULL){
		fprintf(stderr, "%s\n", "Não pode adicionar novo contato, ERRO: novoContato = NULL");
		exit(1);
	}
	if (*agenda == NULL){
		*agenda = novoContato;
		return;
	}
	//adicionar ao final da agenda.
	contato tmp = *agenda;
	while (tmp->prox != NULL){
		tmp = tmp->prox;
	}
	tmp->prox = novoContato;

	return;
}
contato buscarContato(contato *agenda,int tipoBusca, char item[]){
	//tipoBusca
	//1 = nome
	//2 = telefone
	if (agenda == NULL || tipoBusca != 1 && tipoBusca != 2) return NULL;
	contato tmp = *agenda;
	while (tmp != NULL){
		
		if (tipoBusca == 1 && comparaString(item, tmp->nome)) {
			return tmp;
		}else if (tipoBusca == 2 && comparaString(item, tmp->telefone)){
			return tmp;
		}
	}
	return NULL;
}

void imprimeContato(contato c){
	if (!c) return;
	printf("Nome:\t%s\nTel:\t%s\nEmail:\t%s\n\n", (c)->nome, (c)->telefone, (c)->email);
	return;
}

int main(void){
	contato agenda = NULL;
	adicionarContato(&agenda, novoContato("Pedro", "123431123", "pedroso@mani.com"));
	adicionarContato(&agenda, novoContato("Bruna", "11955555555", "bruna.f@ufabc.com"));
	imprimeContato( buscarContato(&agenda, 2, "123431123"));
	return 0;

}