#include <stdio.h>
#include<malloc.h>

void matchain(int **a, int n, int c[],int **h)  
{
    int i,j,d,k;
    for(i=1;i<=n;i++)
    {
    	a[i][i]=0;
    }
    for(d=1;d<=n-1;d++)
    {
        for(i=1;i<=n-d;i++)
        {
            j=i+d;
            a[i][j]= 10000;
            for(k=i+1;k<=j;k++)
            {
                int m = a[i][k-1]+a[k][j]+c[i]*c[k]*c[j+1];
                if(a[i][j] > m)
                {
                    a[i][j] = m;
                   	h[i][j] = k;  //record the k :M[I,J] = M[I][K-1]*M[K][J]
                }
            }
        }
    }
}

void traverse(int m,int n,int **d)     //output how the matrix muliply
{
    if(m==n)
        printf("A[%d]",m);
        
    else
    {
    	int k = d[m][n];
    	printf("(");
    	traverse(m,k-1,d);
    	//printf("%d\n",k);
    	traverse(k,n,d);
    	printf(")");
    }
}

int main()
{
    int r[] = {0,4,5,3,6,4,5};
    int **a;
    int **d;
    int i,j;
    a=(int **)malloc(6*sizeof(int));  // get *a[6]
    d=(int **)malloc(6*sizeof(int));   // *b[6]
    for( i=0;i<6;i++)
    {
    	a[i]=(int *)malloc(6*sizeof(int));
    	d[i]=(int *)malloc(6*sizeof(int));
    }
    matchain(a,5,r,d);
    printf("%d\n",a[1][5]);

 /*   for(i=1;i<6;i++)
    {
    	for(j=1;j<6;j++)
    		printf("%d\n",d[i][j]);
    }
*/
   traverse(1,5,d);
   printf("\n");
    return 0;
}

