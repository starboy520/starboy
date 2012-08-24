#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000000
char s[MAX_SIZE];
int main()
{
	int n;
//	char s[MAX_SIZE];
	while( EOF != scanf("%d %s", &n, s))
	{
		int i = 0, k;
		int len = strlen(s);
		for( k = (len-n)%len; i!=len;i++,k = (k+1)%len )
			putchar(s[k]);
		printf("\n");
	}
	return 0;
}

		
