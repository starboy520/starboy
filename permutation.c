#include <stdio.h>

/* 实现全排列的算法。采用递归。
   假定已经可以生成n-1 个数的所有排列。那么就可以扩展生成这n个数的排列。生成2，3，4，。。。n的所有排列，那么在最前加上1，就可以。
   接下来生成1，3，4，，，，n的所以排列，在每个排列前加上2，重复这样的过程，最后得到结果。
   注意：在递归调用时进行了交换，递归调用后要换回来。 */

void permutation1(int a[],int low ,int high)
{
	int i ,temp;
	
	if(low>high)
	{
		for(i =0;i<=high;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	for( i = low ;i <= high ; i++)
	{
		temp=a[low];
		a[low] = a[i];
		a[i] =  temp;

		permutation1( a ,low+1,high);

		a[i] = a[low];
		a[low] = temp;
	}
}

int main()
{
	int a[] = {1,2,3,4,5};
	permutation1(a,0,4);
	printf("\n");
	return 0;
}
