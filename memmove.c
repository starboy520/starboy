#include <stdio.h>
/* copy the n contents of the pointer src pointed to dest */
void *memmove(void *dest, const void *src, size_t n)
{
	void *ptr = dest;
	if( dest <= src || dest >= src + n)//no cover
	{
		while( n--)
			*dest++ = *src++;
	}
	else  // 有内存覆盖
	{
		dest += n - 1;
		src += n - 1;
		while(n--)
			*dest-- = *src--;
	}
}
