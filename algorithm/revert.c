#include <stdio.h>
#include <string.h>
/* 输入的字符串在原串的基础上倒序后输出 */

char* revert(char* str)
{
	char *s = str;
	int len,i;
	len = strlen(str);
	char *p = str+len-1;
	i = 0;
	
	while (i < len/2)
	{
		char c = *s;
		*s++ = *p;
		*p-- = c;

		i++;
	}
	return str;
}


int main()
{
	char s[] = "123456";
	printf("%s\n",revert(s));
	return 0;
}
