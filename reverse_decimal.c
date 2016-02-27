/*
q1: reverse an integer value by decimal bit

0 1 2 3 4

0000 0001 0010 0011 0100

-2147483648 - 2147483647

*/
#include <stdio.h>

#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)

int reverse_int(int num) {
	
	int origin = 0;
	if(num < 0) {
		origin = -num;
	} else {
		origin = num;
	}

	int result  = 0;
	while(origin > 0) {
		result = result*10 + origin%10;
		origin = origin/10;
	}

	if(num < 0) {
		result = -result;
	}

	return result;
}

int main() {

	int x = INT_MIN;
	int result = 0;

	result = reverse_int(x);

	printf("before reverse: %d, after reverse: %d\n", x, result);

	return 0;
}


// 