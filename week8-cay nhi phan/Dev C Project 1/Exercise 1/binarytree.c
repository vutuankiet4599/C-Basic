#include "binarytree.h"
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

TN *root = NULL;

//tao ra cay moi co goc la data
TN *makeTree(char data)
{
	TN *pNew = (TN*)malloc(sizeof(TN));
	pNew->data=data;
	pNew->left=NULL;
	pNew->right=NULL;
	pNew->parent=NULL;
	return pNew;
}
//them nut moi vao cay khac rong va nut moi them va vi tri da xac dinh truoc lan luot theo muc
//va tu trai qua phai
//neu isleftChild=1 la con trai nguoc la la con phai
void addNode(char data, TN *parent, int isleftChild)
{
	TN *pNew = (TN*)malloc(sizeof(TN));
	pNew->left=NULL;
	pNew->right=NULL;
	pNew->parent=parent;
	pNew->data=data;
	if(isleftChild==1)parent->left=pNew;
	else parent->right=pNew;
}
//thu tu truoc
void preOrderTraversal(const TN *root)
{
	if (NULL==root)return;
	printf("%c ",root->data);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
//thu tu giua
void inOrderTraversal(const TN *root)
{
	if (NULL==root)return;
	inOrderTraversal(root->left);
	printf("%c ",root->data);
	inOrderTraversal(root->right);
}
//thu tu sau
void posOrderTraversal(const TN *root)
{
	if (NULL==root)return;
	posOrderTraversal(root->left);
	posOrderTraversal(root->right);
	printf("%c ",root->data);
}
int MAX(int a, int b)
{
	return a>b?a:b;
}
int height(const TN *root)
{
	if (NULL==root)return -1;
	if (NULL==root->left && NULL==root->right)return 0;
	return 1+MAX(height(root->left),height(root->right));
}
int countNodes(const TN *root)
{
	if (NULL==root)return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}
int countLeaves(const TN *root)
{
	if (NULL==root)return 0;
	if (NULL==root->left && NULL==root->right)return 1;
	return countLeaves(root->left)+countLeaves(root->right);
}
int countIntenalNodes(const TN *root)
{
	if (NULL==root)return 0;
	if (NULL==root->left&&NULL==root->right)return 0;
	return 1 + countIntenalNodes(root->left) + countIntenalNodes(root->right);
}
void levelOrderTraversal(const TN *root)
{
	initQueue();
	enqueue(root);
	while(!isEmpty())
	{
		TN *node = dequeue();
		printf("%c ",node->data);
		if(NULL!=node->left)enqueue(node->left);
		if(NULL!=node->right)enqueue(node->right);
	}
}
TN* depestLeaf(const TN *root)
{
	initQueue();
	enqueue(root);
	//TN *lastLeaf = NULL;
	TN *node;
	while(!isEmpty())
	{
		node = dequeue();
		//if(node->left==NULL&&node->right==NULL) lastLeaf = node;
		if(NULL!=node->left)enqueue(node->left);
		if(NULL!=node->right)enqueue(node->right);
	}
	return node;
}
TN *shallowestLeaf(const TN *root)
{
	initQueue();
	enqueue(root);
	TN *node;
	if (isEmpty())return;
	else
	{
		node = dequeue();
		return node;
	}
}
