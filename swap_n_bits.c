

#include <stdio.h>

int swap_n_bits(int num, unsigned int n, unsigned int x, unsigned int y) {
	int mask = 0x1;

	mask = (mask << n) - 1;

	int mask_x = mask << x;
	int mask_y = mask << y;
	int mask_x_y = ~(mask_x | mask_y);

	return ((num & mask_x) << (y-x)) | ((num & mask_y) >> (y-x)) | (mask_x_y & num);  

}

void main() {
	int x = 0x12345;

	printf("%x\n", swap_n_bits(x, 4, 4, 8));

}