#include <stdio.h>
int main()
{
	union check
	{
		int i;
		char ch;
	}c;
	c.i = 1 ;
	if (c.ch==1)
		printf("little endian\n");
	else
		printf("big endian\n");
}

