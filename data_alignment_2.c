#include <stdio.h>

typedef struct s {
	char c[9];
	int i[10];
	double d[10]
} s_t;

int main() {
	printf("size of struct is : %d \n", sizeof(s_t));
	return 0;
}

// 9+7 + 40 + 80 = 136, but the real output is 132, very weird. hmm...

// update: since the maximum padding is on the basis of highest size of bus size and maximum member size
// For 32 Bit - Max alignment is 4 Bytes 
// For 64 Bit - Max alignment is 8 Bytes
