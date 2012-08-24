#include <stdio.h>
int legal(int *a, int n);
int three_color(int *a, int (*b)[3], int n);
/* three_color problem
 * Backtracking
 */
 
int main()
{
	int b[3][3] = {0,1,1,
				   1,0,1,
				   1,1,0};
	int a[3] = {0};
	if(three_color(a, b, 3) == 1)
	{
		int i;
		for( i = 0; i < 3; i++)
		{
			printf("%d\n", a[i]);
		}
	}
	else
		printf("no solution\n");
		
	return 0;
}

/* check if the current is legal 
if legal return 1
else return 0
*/
int legal(int *a, int n)
{
	int i;
	int flag = 1;
	for(i = 0; i < n; i++)
	{
		if( 0 == a[i])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

/*check if the current coloring is part_solution
Adjacent vetex has different color
if part_solution return 1
else return 0
*/
int part_solution(int *a, int (*b)[3], int k,int n)
{
	int i;
	int flag = 1;
	for(i = 0; i < n; i++)
	{
		if( i != k)
		{
			if( b[i][k] != 0 && a[i] != 0 && a[i]==a[k])
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

int three_color(int *a, int (*b)[3], int n)
{
	int i;
	int flag = 0;
	int k = 1;
	for(i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	
	while( k >= 1)
	{
		int flag2 = 1;
		while(a[k] <= 2)
		{
			a[k] += 1;
			if( 1 == legal(a, n) )
			{
				flag = 1;
				flag2 = 1;
				break;
			}
			else if(legal(a, n) == 0 && 1 == part_solution(a, b, k, n) )
			{
				k += 1;
			}
		}
		if( flag2 == 1)
			break;
		a[k] = 0;
		k -= 1;  //backtrace
	}
	return flag;
}
		
			


