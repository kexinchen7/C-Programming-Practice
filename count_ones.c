#include <stdio.h>

int count_ones(int a) {

	int mask = 0x1;
	int count = 0;

	while(a != 0) {
		if(mask & a != 0) {
			count ++;
		}
		a = a >> 1;
	}
	printf("count of one is: %d\n", count);

}

// only loop number of set bits times
int countSetBits(unsigned int n)
{
  unsigned int c; // the total bits set in n
  for (c = 0; n; n = n & (n-1))
  {
    c++;
  }
  return c;
}

 
int main(void)
{
  unsigned int n;
  printf("Enter a positive integer: ");
  scanf("%u", &n);
  printf("%d\n", countSetBits(n));
}




int main() {
	int a = 3;
	return count_ones(a);
}