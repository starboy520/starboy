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
    quicksort(a,0,7);
    int i;
    for( i=0 ;i<=7;i++)
         printf("%d ",a[i]);
    printf("\n");
    
    system("pause");
    return 0;
} 
