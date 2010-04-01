#include <stdio.h>
#include <math.h>
#include <malloc.h>
/* It is similar to the matrix chain . It's to find a optimal method to part the node( v0,v1,v2,v3,v4,v5,v6,v7,.....vn) 
*/
#define INF 10000
struct Point 
{
	double x;
	double y;
};
double a[5][5];
//compute the distance between two points
double distance(struct Point p1, struct Point p2)  
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double optimal_triangulation(struct Point p[], int n)
{
	int i,j,k,d;
	for(i=1;i<n;i++)
		a[i][i+1] = 0;
	for(d=1;d<n-1; d++)
	{
		for(i=1;i<n-d;i++)
		{
			j = i+d+1;
			a[i][j] = INF;
			for(k=i+1;k < j; k++)
			{
				double min = a[i][k]+a[k][j];
				if ( k-i >1)
					min += distance(p[i],p[k]);
				if( j-k>1)
					min += distance(p[k],p[j]);
				if(min < a[i][j])
					a[i][j] = min;
			}
		}
	}
	return a[1][n];
}
	
	
int main()
{
//	double **a;
	int n,i;
/*	printf("please input the number n of the Polygon:");
	scanf("%d",&n);
	struct Point p[n+1];
	a = (double**)malloc(sizeof(double)*(n+1));
	for(i=0;i<=n;i++)
	{
		a[i] = (double *)malloc(sizeof(double)*(n+1));
	}
	for(i=1;i<=n;i++)
	{
		printf("print p[%d]'s x and y coordinate:",i);
		scanf("%lf %lf",&p[i].x,&p[i].y);
	}
*/
	struct Point p[5];
	p[1].x=p[1].y=0.0;
	p[2].x=0.0;
	p[2].y=1.0;
	p[3].x=1.0;
	p[3].y=1.0;
	p[4].x=1.0;
	p[4].y=0.0;
	printf("%lf\n",optimal_triangulation(p, 4));
	printf("%lf\n",a[1][4]);
	return 0;
}
	
