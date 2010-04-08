#include <stdio.h>
#include <malloc.h>

/* 1: implement the mergesort
   2: Inverse number of algorithms (逆序数算法)
   
    what is inversion ?:   i<j but a[i]>a[j] then (i,j) is a pair of inversion
    
    we find when we do merge_sort ,  if i<j but a[i]>a[j], then we need to swap a[i],a[j], so ,once we do a swap , we find a pair of inversion.

*/

int MERGE(int a[], int begin1,int end1,int end2)
{
	 int num = 0;
	 int b1,b2,b3,i;
	 int *c;
	 c = (int *)malloc(sizeof(int)*(end2-begin1+1));
     b1 = begin1;
     b2 = end1+1;
     b3 = end2;
     int k=0;
     while(b1 <= end1 && b2 <= end2)
     {
              if(a[b1] <= a[b2])
                       c[k++] = a[b1++];
              else
              {
              		   num += end1-b1+1;
                       c[k++] = a[b2++];
              }
     }
     
     if(b1 == end1+1)
      {     
            for(i = b2; i <= end2; i++)
                 c[k++] = a[i];
      }
      else
      {
          for(i = b1; i <= end1; i++)
                c[k++] = a[i];
      }
      int e = begin1;
      for(i = 0;i < k ;i++)
            a[e++] = c[i];
      free(c);
      return num;
}

int merge_sort(int *a,int low, int high)
{
	if(low == high)
		return 0;
	else if(low<high)
	{
		
		int mid = (high+low)/2;
		int num1 = merge_sort(a,low,mid);
		int num2 = merge_sort(a,mid+1, high);
		return num1+num2+MERGE(a, low, mid, high);
	}
}
            
            
int main()
{
    int a[10] = {'a','b','c','A','B','C'};
    int k = merge_sort(a,0,5);
    printf("%d\n", k);
    
    
    return 0;
}
                    
