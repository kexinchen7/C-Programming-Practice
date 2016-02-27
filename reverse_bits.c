/*
 reverse an interger bit by bit
 
 int or unsigned int ?
 only valid bits(flag = 1) or whole 32-bits(flag = 0) ?

*/

#include <stdio.h>

int reverse_bits(int a, int flag) {
	int b = 0;
	
	if(flag) {
		// only reverse valid bits
		while(a > 0) {
			b <<= 1;
			b = b | (a & 0x1);
			a >>= 1;
		}
	} else {
		// reverse all 32 bits
		int i = 0;
		for( ; i < 32; ++i) {
			b <<= 1;
			b |= (a & 0x1);
			a >>= 1;
		}
	}
	return b;
}

int main() {
	int a = 0;
 	int b = 1;
 	int c = 123;

 	printf("a <%x> is reversed to <%x>\n", a,  reverse_bits(a, 1));
 	printf("b <%x> is reversed to <%x>\n", b,  reverse_bits(b, 1));
 	printf("c <%x> is reversed to <%x>\n", c,  reverse_bits(c, 0));

 	return 0;
}