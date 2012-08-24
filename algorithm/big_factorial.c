#include <stdio.h>
#define INF 10000
void big_factorial(int *stor, int n)
{// stor[0] stor the bit
	int i, j;
	for(i=1;i<=n;i++)
	{
		int carry = 0;
		for(j=1;j<=stor[0];j++)
		{
			int k = stor[j] * i + carry;
			stor[j] = k%INF;
			carry = k/INF;
		}
		while(carry)
		{
			stor[stor[0]+1] = carry%INF;
			carry = carry/INF;
			stor[0]++;
		}
	}
}

int main()
{
	int a[1000] = {0};
	a[0] = a[1] = 1;
	big_factorial(a,100);
	int i;
	printf("%d",a[a[0]]);
	for(i=a[0]-1; i>=1; i--)
	{
			printf("%04d", a[i]);
	}
	printf("\n");
	return 0;
}
