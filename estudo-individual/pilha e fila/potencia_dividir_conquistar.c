#include <stdio.h>

double powerDC(float base, unsigned int n){
	if (n == 0){
		printf("retornando 1\n");
		return 1;
	}else {
		printf("chamando: (%f, %d)\n",base*base, n/2 );
		return powerDC(base*base, n/2) * ((n%2) ? base : 1);
	}
}

int main(){

	printf("%f\n", powerDC(10,2));
	return 0;
}