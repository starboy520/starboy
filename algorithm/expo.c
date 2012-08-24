#include <stdio.h>
#include <ctype.h>


int multi(int a[],int point)
{
	int tmp[100]={0};
	int i,j;
	int c;
	for(i=1;i<a[0];i++)
	{
		int c=i;
		for(j=1;j<a[0];j++)
		{
			int m=a[i]*a[j];
			tmp[c] +=m%10;
			tmp[c+1] =tmp[c]+m/10;
		}
		while(tmp[c]>=10)
		{
			int k
						
int main()
{
	char in[6],int n;
	while(scanf("%s %d",in,&n) != EOF)
	{
		int c = 0,i;
		int point;
		int a[100]={0};
		for(i=5; i>=0; i++)
		{
			if(isdigit(in[i]))
				{
					a[1+c] = in[i]-'0';
					c++;
				}
			else
				point = c;
		}
		a[0] = 5;
		
				
				
		
	
