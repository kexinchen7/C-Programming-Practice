/* Compile code without optimization option */
#include <stdio.h>
int main(void)
{
	const int local = 10;
	int *ptr = (int*) &local;	// it is down qualification, may have problem

	printf("Initial value of local : %d \n", *ptr);

	*ptr = 100;

	printf("Modified value of local: %d \n", *ptr);

	return 0;
}
