#include <stdio.h>

int main(){
	int x, y, z, *p, **pp;
	y = 0;
	p = &y;
	pp = &p;
	x = *p;
	x += 4;
	(*p)++;
	--x;
	(*p) += x;
	p--;
	(*p) += x;
	p++;
	(**pp) += 3*x;
	printf("x = %d &x = %p\n", x, &x);
	printf("y = %d &y = %p\n", y, &y);
	printf("z = %d &z = %p\n", z, &z);
	printf("p = %p &p = %p\n", p, &p);
	printf("pp = %p &pp = %p\n", pp, &pp);
}