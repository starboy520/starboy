#include <stdio.h>

/* 实现全排列的算法。采用递归。
   假定已经可以生成n-1 个数的所有排列。那么就可以扩展生成这n个数的排列。生成2，3，4，。。。n的所有排列，那么在最前加上1，就可以。
   接下来生成1，3，4，，，，n的所以排列，在每个排列前加上2，重复这样的过程，最后得到结果。
   注意：在递归调用时进行了交换，递归调用后要换回来。 
  */
static int all = 0;
void permutation1(int a[],int low ,int high)
{
	int i ,temp;
	
	if (low == high) {
        all++;
		for(i =0;i<=high;i++)
			printf("%d ",a[i]);
		printf("\n");
	} else {
        for (i=low ; i<=high; i++) {
		    temp=a[low];
		    a[low] = a[i];
		    a[i] =  temp;

		    permutation1(a ,low+1,high);

		    a[i] = a[low];   /*要交换回来  */
		    a[low] = temp;
	    }
    }
}

/*第二种算法
   设有 1，2，3。。n 个位置，在其中第 k为位置放置一个数字， 则对于其余的n-1 个位置递归排列

*/
int m;
void permutation2(int a[],int m,int n)  //每次排列对把 m放置于第 i 个位置中
{
     if(m == 0)
     {
             int j;
             for(j=1;j<=n;j++)
                              printf("%d",a[j]);
             printf("\n");
     }
     int i;
     for(i=1;i<=n;i++)
     {
             if(a[i]==0)
             {
                        a[i]=m;
                        permutation2(a,m-1,n);
                        a[i]=0;   //a[i]置零
             }
     }
              
} 



int main()
{
	int a[] = {1,2,3, 5, 6};
	int b[4] = {0};
	int n=3;
	m=3;
	permutation1(a,0,4);
	permutation2(b,3,3);
    printf("all : %d\n", all); 
	return 0;
}
