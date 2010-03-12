#include <stdio.h>
#define MIN -1000

int candidate(int a [] ,int n)
{
    int count = 1 ;
    int i;
    int c = a[0];
    for(i=2;i<n;i++)
    {
                    if (count == 0)
                       c = a[i];
                    else
                    {
                        if(c=a[i])
                                  count++;
                        else
                                  count--;
                    }
    }
    if(count >0)
             return c;
    else
             return MIN;
    
}

int main()
{
    int a[] = {1,2,1,3,2,1,2,1,4,1,1};
    int c;
    c = candidate(a,11);
    int i;
    int count = 0;
    for(i=0;i<11;i++)
    {
                     if(c==a[i])
                                count++;
    }
    if(count> 11/2)
              printf("%d\n",c);
    else
              printf("NONE\n");
    system("pause");
}
                     
                       
