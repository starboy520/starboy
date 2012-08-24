#include <stdio.h>
/* problem describe:
	对于与不完全为 0 的非负整数 a,b,gcd(a,b)表示 a,b 的最大公约数。那么存在整
	数 x,y 使得 gcd(a,b)=ax+by

*/
int x,y;
int num=0;

/*solution:
	求解 x,y 的方法的理解
	我们不妨设 a>b。
	1,显然当 b=0,gcd(a,b)=a。此时 x=1,y=0;
	2,ab<>0 时
	 设 ax1 +by1 =gcd(a,b);
	   bx2 +(a%b)y2 =gcd(b,a%b);
	    根据朴素欧几里德原理有 gcd(a,b)=gcd(b,a%b);
	     则:ax 1 +by1 =bx2 +(a%b)y2 ;
	      即:ax 1 +by1 =bx2 +(a-(a/b)*b)y2 =ay2 +bx2 -(a/b)*by2 ;
	       根据恒等定理得:x1 =y2 ; y1 =x2-(a/b)*y2 ;
	        这样我们就得到了求解 x1,y1 的方法:x1,y1 的值基于 x2,y2.

*/
int Extend_Eulid(int a, int b)
{
	if( b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int n = Extend_Eulid(b,a%b);
		int temp=x;
		x=y;
		y=temp-a/b*y;
		return n;
	}
}

int main()
{
	int a=12,b=10;
	int k=Extend_Eulid(a,b);
	printf("x=%d,y=%d,gcd=%d\n",x,y,k);

	return 0;
}

