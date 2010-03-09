#include <stdio.h>
#define DIGIT 4
#define NUM 12

/*
radix sort ：

temp[10][NUM]用来暂时存放，其中某次循环若数a 的比特为 lsd ，存在 temp[lsd][m］中  
tp[lsd] 来数字 为 lsd  的个数，使得在temp［lsd］［m］中依次存储
依次扫描后要把数重新存储回a，并且把temp重置tp[]也要重置

*/
void radix_sort(int a[] , int n)
{
	int m=1,i,j,bit=1,lsd;
	int temp[10][NUM] = {0};
	int tp[10] = {0};
	while(bit <= DIGIT)
	{
		for(i=0; i<n;i++)
		{
			lsd = (a[i]/m)%10;
			temp[lsd][tp[lsd]] = a[i];
			tp[lsd]++;
		}
		int p=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<n;j++)
			{
				if(temp[i][j]!= 0 && p<n)
				{
					a[p] = temp[i][j];
					p++;
					temp[i][j] = 0;
				}
			}
		}
		
		bit++;
		m*=10;
		for(i=0;i<10;i++)
			tp[i] = 0;
	}
}

int main()
{
	int a[9]={1234,2345,2132,3452,3423,2137,4341,1112,3231};
	radix_sort(a,9);
	int i;
	for(i=0;i<9;i++)
		printf("%d\n",a[i]);
	return 0;
}
	
				
		
			
	

