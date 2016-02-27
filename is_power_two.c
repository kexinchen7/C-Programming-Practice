
// q2: check if an integer is power of two
#include <stdio.h>

// method 1: divide by two recursively
int is_power_two(int num) {
	
	if(num == 1 || num == 0) {
		return 0;
	}

	if(num % 2 != 0) {
		return -1;
	} 

	return is_power_two(num/2);
}


int count_set_bits(int num) {
	int count = 0;

	while(num > 0) {
		count += num & 1;
		num >>= 1;
	}
	
	return count;
}

int subtract_by_one(int num) {
	return  num && !(num & (num-1));
}

int main() {
	int x = 1;
	printf("1. divide by two recursively: %d\n", is_power_two(x));
	printf("2. count number of set bits: %d\n", count_set_bits(x));
	printf("3. subtract by one: %d\n", subtract_by_one(x));

	return 0;
}
