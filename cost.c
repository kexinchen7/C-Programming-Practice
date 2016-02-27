#include <stdio.h>
#include <string.h>

int GetMinExpenses(char* A, char* B);

int d[2001 + 2][2001 + 2];

int GetMinExpenses(char* A,char* B)
{
	int len_a = strlen(A), len_b = strlen(B);
	if (len_a > 2000 || len_b > 2000)
		return -1;

	int del_opt, ins_opt;
	int i, j, k;
	
	// 初始化DP数组
	d[0][0] = 0;
	for(i = 1; i <= len_a; i++)
		d[i][0] = 2;
	for(j = 1; j <= len_b; j++)
		d[0][j] = j + 2;

	// 动态规划 + 递归
	for(i = 1;i <= len_a;i++)
		for(j = 1;j <= len_b;j++) {
			if (A[i-1] == B[j-1]) {
				d[i][j] = d[i-1][j-1];
				continue;
			}
			// 删除操作，0 ~ i-1
			del_opt = d[i-1][j];
			for (k = 0; k < i-1; k++) {
				del_opt = del_opt < d[k][j] ? del_opt : d[k][j];
			}
			// 插入操作，0 ~ j-1
			ins_opt = d[i][j-1] + 1;
			for (k = 0; k < j-1; k++) {
				ins_opt = ins_opt < d[i][k] + j - k ? ins_opt : d[i][k] + j - k;
			}

			d[i][j] = del_opt < ins_opt ? del_opt : ins_opt;
			d[i][j] += 2; // 减轻运算量
		}    

	return d[len_a][len_b];
}

int main()
{
	int n;
	scanf("%d", &n);
	int i = 0;

	char str[n*2][100];
	int result[n];

	for(i= 0; i<n; i++)
	{
		scanf("%s", &str[2*i][0]);
		scanf("%s", &str[2*i+1][0]);
	}

	for(i = 0; i<n; i++)
	{
		result[i] = GetMinExpenses(&str[2*i][0], &str[2*i+1][0]);
		printf("%d\n", result[i]);
	}

	return 0;
}