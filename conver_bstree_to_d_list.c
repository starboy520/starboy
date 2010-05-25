/***************************
problem: input a binary search tree and convert it into a sorted double-linked list.
         and not to construct any new nodes

***************************/


/* Recursive method
*/

#include <stdio.h>
typedef struct BSTNode
{
        int data;
        BSTNode *left;
        BSTNode *right;
}BTree;

/**********************************************
Convert a sub binary-search-tree to a sorted double-linked list
Input: root                the head of the sub tree
       pLastNodeinList:    the tail of the doubel list
**********************************************/
void ConvertNode(BTree *root, BTree *pLastNodeinList)
{
    if(root == NULL)
        ;
    BTree *current=root;

    if(current->left != NULL)
        ConvertNode(current->left,pLastNodeinList);

    current->left = pLastNodeinList;
    if(pLastNodeinList != NULL)
        pLastNodeinList->right = current;

    pLastNodeinList = current;

    if(current->right != NULL)
        ConvertNode(current->right, pLastNodeinList);
}


/*******************************
convert a binary tree into a sorted double-linked list
input: root: the root of the tree
output: the head of the double-linked list
************************************/

BSTree* Convert(BSTree *root)
{
    BSTree *PLastNode = NULL;
    ConvertNode(root,PLastNode);

    BSTree* pHead = pLastNode;
    while(pHead && pHead->left)
        pHead = pHead->left;

    return pHead;
}
