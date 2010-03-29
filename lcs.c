#include <stdio.h>
#define MAX 100
int l[20][20] ={0};
int r[20][20] = {0};
int c[20] = {0};
int d = 0;
int lcs2(int m, int n, char *a, char *b)
{ //改进的算法，使得空间复杂度为 O(min(m,n))
	//这里假设 m<n 
	
	int i,j;
	for(i=1; i<=n; i++)
	{	 
		for(j=1; j<=m; j++)
			{	
				int h = c[j];
				if( a[j] == b[i])
				{
					if( j ==1)
						c[j] = c[j-1]+1;   //这里特别要小心，j=1 时，如果还是  c[j]=d+1 就错误了！
					else
						c[j] = d+1;         //这里不可以用c[j]=c[j-1]+1 因为 c[j-1]可能已经改变了，应该用一个变量来存放上一次c[j]
					}
				else
				{
					if( c[j] < c[j-1])
						c[j] = c[j-1];
					
				}
				d = h;
			}
	}
	
	int k=0;
	for(j=1; j<=m; j++)
	{
		if(c[j]>k)
			k=c[j];
	}
	return k;
}
					
void lcs1(int m,int n,char *a,char *b)
{
	int i,j;
	for(i=1;i<=m;i++)
		l[i][0] = 0;
	for(j=1;j<=n;j++)
		l[0][j] = 0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if( a[i] == b[j])
			{
				l[i][j] = l[i-1][j-1] +1 ;
				r[i][j] = 1;
			}
			else
			{
				if(l[i][j-1] > l[i-1][j])
				{
					l[i][j] = l[i][j-1];
					r[i][j] = 2;
				}
				else
				{
					l[i][j] = l[i-1][j];
					r[i][j] = 3;
				}
			}
		}
	}
}

void print_LCS(int i,int j,char *x)
{
	if(i ==0 || j==0)return ;
	if(r[i][j] == 1)
	{
		print_LCS(i-1,j-1,x);
		printf("%c\n",x[i]);
	}
	else if( r[i][j] == 2)
		print_LCS(i, j-1,x);
	else if( r[i][j] == 3)
		print_LCS(i-1,j,x);
}

int main()
{
	char a[] ={'0','x','y','x','x','z','x','y','z','x','y'};
	char b[] = {'0','z','x','z','y','y','z','x','x','y','x','x','z'};
	lcs1(10, 12, a, b);
	
	printf("%d\n", lcs2(10,12,a,b));
	print_LCS(10, 12, a);

	return 0;
}
