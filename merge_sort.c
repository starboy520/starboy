#include<stdio.h>

void merge_sort(int a[], int begin1,int end1,int end2)
{
     int c[20] = {0};
     int b1,b2,b3,i;
     b1 = begin1;
     b2 = end1+1;
     b3 = end2;
     int k=0;
     while(b1 <= end1 && b2 <= end2)
     {
              if(a[b1] <= a[b2])
                       c[k++] = a[b1++];
              else
                       c[k++] = a[b2++];
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
}

void buttomsort(int a,int n)
{
     
     
            
            
int main()
{
    int a[10] = {1,3,4,5,6,2,3,4,5,6};
    merge_sort(a,0,4,9);
    int t;
    for(t = 0 ;t <= 9; t++)
          printf("%d ",a[t]);
    printf("\n");
    
    system("pause");
    
    return 0;
}
                    
