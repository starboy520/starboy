#include <stdio.h>

int split(int a[], int low, int high )
{
    int i,j,x;
    i=low;
    x = a[low];
    for(j=low+1;j<=high;j++)
    {
                            if(a[j] <= x)
                            {
                                    i++;
                                    if( i != j)
                                    {
                                        int temp;
                                        temp = a[i];
                                        a[i] = a[j];
                                        a[j] = temp;
                                    }
                            }
    }
    int tp1 = a[low];
    a[low] = a[i];
    a[i] = tp1;
    
    return i;
}


int find_kth_max_number(int *a, int low ,int high, int k)
{
	int m  = split(a, low, high);
	if ( m - low + 1 == k)
		return a[m];
	else
	{
		if(m - low + 1 > k)
			find_kth_max_number(a, low, m, k);
		else
			find_kth_max_number(a, m+1, high, k-(m - low + 1) );	
	}
}

void quicksort(int a[] ,int low,int high)
{
     if(low<high)
     {
      int w = split(a,low,high);
      quicksort(a,low,w-1);
      quicksort(a,w+1,high);
      }
}

int main()
{
    int a[]= {2,6,3,5,1,10,4,9};
    int k = find_kth_max_number(a, 0, 7,8);
    printf("%d\n", k);
    quicksort(a,0,7);
    int i;
    for( i=0 ;i<=7;i++)
    	   printf("%d ",a[i]);
    
    printf("\n");
    return 0;
} 
