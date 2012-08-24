#include <stdio.h>
#include <malloc.h>
int binomial(int n, int k)
{
//	int **a;
//	a = (int *)malloc(n*sizeof(int));   ºËĞÄË¼Ïë c(n,k) = c(n-1,k-1)+c(n-1,k)
	int a[n][n];
	int i ,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			a[i][j]=0;
	for(i=0; i<=n; i++)
	{
		a[i][0] = a[i][i] = 1;
	}
	for(i=2; i<=n;i++)
	{
		for(j =1; j<i; j++)
		{
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	return a[n][k];
}

int main()
{
	printf("%d,%d,%d\n",binomial(5,0),binomial(5,5),binomial(20,10));
	return 0;
}
