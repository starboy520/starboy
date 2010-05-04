#include <string.h>
#include <ctype.h>
#include <stdio.h>

/****************************************************************************************************/
size_t strlen(const char *str)
{
	const char *cp = str;
	while(*cp++ != '\0')
		;
	return cp-str-1;
}

/*************************************************************************************************/
char *strcat(char *dest, const char *src)
{
	char *s1=dest;
	const char *s2 = src;
	while(*s1++ != '\0') // you may have a test, when the first loop , I don't recommod the way 
		;
	s1--;

	while( *s1++ = *s2++);
	
	return dest;
}

/************************************************************************************************/
char *strcpy(char *dest , const char *src)
{
	if((dest == NULL) || (src == NULL))
		return NULL;
	char *address = dest;
	while( (*dest++ = *src++) !='\0')
		;
	return address;
}

/********************************************************************************************/
int strcmp(const char *p1, const char *p2)
{
	const unsigned char *s1 = (const unsigned char *) p1;
	const unsigned char *s2 = (const unsigned char *) p2;
	unsigned char c1,c2;
	do
	{
		c1 = (unsigned char )*s1++;
		c2 = (unsigned char )*s2++;
		if (c1 == '\0')
			return c1-c2;
	}
	while(c1 == c2);

	return c1-c2;
}


/*******************************************************************************************/
long atol(const char *nptr)
{
	int c;
	long total;
	int sign;
	while( isspace((int)(unsigned char)*nptr) )
		nptr++;
	c = (int)(unsigned char )*nptr++;
	sign = c;

	if ( c == '-' || c == '+')
		c = (int)(unsigned char)*nptr++;
	total = 0;

	while( isdigit(c) )
	{
		total = 10 * total + (c - '0');
		c = (int)(unsigned char)*nptr++;
	}
	if (sign == '-')
		return -total;
	else
		return total;
}

int atoi(const char *ptr)
{
	return (int)atol(ptr);
}


/***********************************************************************************/

void *memcpy(void *dst, const void *src, size_t count)
{
	assert (NULL != dst && NULL != src);
	void *ret = dst;
	/* copy from lower address to higher address */
	while( 0 != count--)
	{
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}
	
	return ret
}

void *memmove(void *dst, const void *src, size_t count)
{
	void *ret = dst;
	assert(NULL != dst && NULL != src)
	if( dst <= src || (char *)dst >= (char *src) + count )
	{
		while(count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else
	{
		dst = (char *)dst + count - 1;
		src = (char *)src + count - 1;
		while(count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	
	}
	return ret;
}
	

