
#include <stdio.h>

#define set_bit(num, i, j) num = ((((num >> i) & 1) ^ j) << i) ^ num 
/*
0 0 0 0 _i^j_ 0 .. 0

xor

# # # # _i___ # .. #

=

# # # # _j___ # .. #

*/

int main() {
	int num = 0b10001111;
	set_bit(num, 6, 1);
	set_bit(num, 7, 1);

	set_bit(num, 4, 0);
	set_bit(num, 3, 0);

	printf("after set %x\n", num);
	return 0;
}