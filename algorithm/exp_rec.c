#include <stdio.h>
/* 计算 x 的m 次幂 。用递归的方法*/

int powers(int x , int m)
{
	if(m==0)
		return 1;
	else
	{
		if( m%2==0)
			return powers(x*x,m/2);
		else
			return x*powers(x*x,m/2);
	}
}

int main()
{
	int base,po;
	base = 3;
	po = 5;
	printf("%d\n",powers(base,po));

	return 0;
}
