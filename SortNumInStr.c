#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void *a,const void *b){
	return *(int *)a - *(int *)b;
}


int main()
{
	char str[100];

	printf("Enter a string: \n");
	scanf("%s", str);

	int n = strlen(str);

	printf("n is %d\n", n);
	printf("Entered string: %s\n", str);

	int num[n];
	int i = 0;
	int j = 0;

	for(i = 0; i < n; i++)
	{
		int res = 0;
		if(str[i] >= '0' && str[i] <= '9')
		{
			res = res + (str[i] - '0');
			num[j] = res;
			printf("num [%d] is %d\n",j, num[j]);
			j++;
		}
		
	}


	qsort(num, j, sizeof(int), cmpfunc);

	for(i = 0; i < j;i++)
		printf("%d\n", num[i]);


	return 0;
}