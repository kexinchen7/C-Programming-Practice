#include <stdio.h>
/*
unsigned int rotate_int(unsigned int a, unsigned int k) {
	return (a >> k | a << (32-k));
}


int main() {
	unsigned int a = 123;

	printf(" <%u>, <%u>\n", a, rotate_int(a, 1));

	return 0;
}
*/

int left_rotate(int a, unsigned int k) {
	return (a >> (32-k) | a << k);
}

int right_rotate(int a, unsigned k) {
	return (a >> k | a << (32-k)); 
}

int main() {
	int a = 123;

	printf("Before rotate: <%x>, left_rotate: <%x>, right_rotate: <%x> \n", a, left_rotate(a, 4), right_rotate(a, 4));

	return 0;
}