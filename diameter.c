#include <stdio.h>
#include "convexhull.c"

double area(Point p1, Point p2, Point p3)
{
	return abs(0.5*((p2.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p2.y-p1.y)));
}

double dimaerter(Point stack[], int top)
{
	double len[MAX_SIZE];
	int k = 2;
	while(area(stack[top], stack[1],stack[k+1]) > area(stack[top], stack[1], stack[k]))
		k++;
	int i = 1, j = k;
	int num = 0;
	while( i <= k && j <= top )
	{
		len[num++] = dis(stack[i], stack[j]);
		while( area(stack[i], stack[i+1], stack[j+1]) >= area(stack[i], stack[i+1], stack[j]) && j<top)
		{
			len[num++] = dis(stack[i], stack[j]);
			j++;
		}
		i++;
	}
	double max = 0;
	for(i = 0; i < num; i++)
	{
		if(max < len[i])
			max = len[i];
	}
	return max;
}
