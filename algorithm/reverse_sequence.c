#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct node
{
	char data;
	struct node *next;
}linkstack, *pl;

linkstack *initstack()
{
	linkstack *A;
	A = (linkstack *)malloc(sizeof(linkstack));
	A->next = NULL;
	return A;
}

void push(linkstack *top, char x)
{
	linkstack *tmp;
	tmp = (linkstack *)malloc(sizeof(linkstack));
	tmp->data = x;
	tmp->next = top->next;
	top->next= tmp;
	printf("%c\n", top->data);
}

void pop(linkstack *top, char *x)
{
	if(top->next != NULL)
	{
		linkstack *tmp ;
		tmp = top->next;
		top->next = tmp->next;
		*x = tmp->data;
		free(tmp);
	}
	else
		printf("null\n");
}

void judge()
{
	linkstack *a = initstack();
	char c[100],d;
	int flag = 0;
	printf("请输入一个以@为结束符的字母序列。\n");
    scanf("%s",&c);
    int i = 0;
    while(c[i]!='@')
    {
                  if(c[i] == '&')
                  {
                            flag=1;
                            i++;
                            continue;
                  }
                  else if(flag)
                  {
                  			
							pop(a, &d);
                          	if(c[i] != d)
                          		break;
                          	i++;
                  }
                  else
                  {
                  	push(a,c[i]);
                  	i++;
                  }
     }
     if(a->next==NULL && c[i]=='@')
     	printf("这属于该模式的字符序列。\n");
     else
     	printf("这不属于该模式的字符序列。\n");
}

int main()
{
	judge();
	return 0;
}
	

