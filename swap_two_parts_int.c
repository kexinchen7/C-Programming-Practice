/*
switch bits from index i to j with the bits from 0 to j-i


*/

void swap_part(int *p, int i, int j) {
	int low_mask = (1 << (j-i+1)) - 1;
	int high_mask = low_mask << i;
	int high_low_mask = low_mask | high_mask;

	*p = ((*p & high_mask) >> i) | ((*p & low_mask) << i) | (*p & (~high_low_mask));
}


int main() {
	int num = 0x12345;

	swap_part(&num, 8, 11);
	printf("%x\n", num);
	return 0;
}