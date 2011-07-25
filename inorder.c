#include <stdio.h>
#define MAXSIZE 100
typedef struct BTNode
{
    int data;
    struct BTNode *left;
    struct BTNode *right;
}Btree;

Btree *stacks[MAXSIZE];
int top = 0;


void InOrder(Btree *root)
{
	if(root != NULL)
	{
		InOrder(root->left);
		printf("%d\n",root-data);
		InOrder(root->right);
	}
}

void InOrderTraverse(Btree *root)
{
    Btree *p = root;
    top++;
    while( p != NULL || top != 0)
    {
        while( p != NULL )
        {
            stacks[top] = p;
            top++;
            p = p->left;
        }

        if(top != 0)
        {
            p = stacks[top];
            top--;
            p = p->right;
        }
    }
}
