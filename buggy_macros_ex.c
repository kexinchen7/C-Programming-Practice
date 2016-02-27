#include <stdio.h>

#define DOUBLE(X) X*X


#define ADD_TWO(x,y) x += 2; y +=2


int main() {

	int y = 3;

	// text replacement cause potential bugs
	int x = DOUBLE(++y);

	printf("x is %d\n", x);

	ADD_TWO(x,y);

	printf("x is %d, y is %d\n", x, y);

	// binding:
	
	if(1)
		ADD_TWO(x, y);


	printf("x is %d, y is %d\n", x, y);
	return 0;
}

