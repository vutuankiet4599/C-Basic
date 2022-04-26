#include "BST.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	BST *root = makeTree('A',7);
	addNode('B',5,root,1);
	addNode('G',10,root,0);
	addNode('E',4,root->left,1);
	addNode('F',6,root->left,0);
	addNode('H',9,root->right,1);
	addNode('I',1,root->right,0);
	/*
	int result = checkBST(root,INT_MIN,INT_MAX);
	if (result == 0)printf("Day ko la bst.\n");
	else printf("La bst.\n");
	*/
	BST *illegalNODE=NULL;
	int result = checkBST2(root,INT_MIN,INT_MAX,&illegalNODE);
	if(result == 0)
	{
		printf("ko la bst.\n");
		printf("sai o nut %c %d\n",illegalNODE->data,illegalNODE->key);
	}
	return 0;
}
