#include <stdio.h>

void main() {
	int a = 2;
	int b = -3;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("after swap: a = %d, b = %d \n", a, b);

}