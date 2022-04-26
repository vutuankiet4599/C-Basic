#include "bst.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	BST *root = makeTree('A',7);
	/*
	addNode('B',5,root,1);
	addNode('G',10,root,0);
	addNode('E',4,root->left,1);
	addNode('F',6,root->left,0);
	addNode('H',9,root->right,1);
	addNode('I',18,root->right,0);*/
	/*
	int result = checkBST(root,INT_MIN,INT_MAX);
	if(result ==0) 
		printf("Day KHONG phai cay nhi phan tim kiem!\n");
	else
		printf("Do chinh xac la cay nhi phan tim kiem!\n");
	
	*/
	/*
	BST * illegalNode = NULL;
	int result = checkBST2(root,INT_MIN,INT_MAX, &illegalNode);
	if(result ==0) 
	{
		printf("Day KHONG phai cay nhi phan tim kiem!\n");
		printf("Gia tri nut vi pham %c %d\n", 
			illegalNode->data, illegalNode->key);
	}		
	else
		printf("Do chinh xac la cay nhi phan tim kiem!\n");
	*/
	addNodeBST2('B',10,root);
	addNodeBST2('C',8,root);
	addNodeBST2('D',13,root);
	addNodeBST2('E',5,root);
	
	inOrderTraversal(root);
	return 0;
}
