#include <stdio.h>
void trocaMin(int *i, int *j){
	if (i < j) return;
	int *temp;
	int aux;
	temp = &aux;
	*temp = *i;
	*i = *j;
	*j = *temp;
}


int main(){
	char *a = "aaafg", *b = "aaasdf";
	int i=0;
	for (i = 0; *(a+i) == *(b+i);i++)
		printf("%d\n", i);
	if (*(a+i) < *(b+i))
		printf("%s vem antes de %s\n", a, b);
	else 
		printf("%s vem depois de %s\n", a, b);
	return 0;
}