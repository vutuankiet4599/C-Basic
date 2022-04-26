#include "BST.h"
#include <stdlib.h>
//ham tao cay voi mot nut goc
BST *makeTree(char data, int key)
{
	BST *root=(BST*)malloc(sizeof(BST));
	root->data=data;
	root->key=key;
	root->left=NULL;
	root->parent=NULL;
	root->right=NULL;
	return root;
}
//isleftChild=1 => la con trai cua parent va nguoc lai
void addNode(char data,int key, BST *parent, int isleftChild)
{
	BST *pNew=(BST*)malloc(sizeof(BST));
	pNew->data=data;
	pNew->key=key;
	pNew->left=NULL;
	pNew->parent=NULL;
	pNew->right=NULL;
	if(isleftChild)parent->left=pNew;
	else parent->right=pNew;
}
//kiem tra cay co phai la bst khong
int checkBST(BST *root,int LB,int RB)
{
	if (root==NULL)return 1;
	if (root->key<RB&&root->key>LB)
	return checkBST(root->left,LB,root->key)&&checkBST(root->right,root->key,RB);
	else return 0;
}
int checkBST2(BST* root, int LB, int RB, BST** illegalNode)
{
	if(NULL == root) {
		*illegalNode = NULL;
		return 1;		
	}
	if(root->key<RB && root->key>LB)
	{
		// nhan trai vi pham truoc
		if (!checkBST2(root->left,LB,root->key,illegalNode))
		{
			return 0;
		}
		else if(!checkBST2(root->right,root->key,RB,illegalNode))
			return 0;
		else
		{
			*illegalNode = NULL;
			return 1;
		}		
	}	
	else
	{
		*illegalNode = root;
		return 0;
	}
}
//Phan 2 noi ro
int checkBST3(BST* root, int LB, int RB, BST** illegalNode)
{
	if(NULL == root) {
		*illegalNode = NULL;
		return 1;		
	}
	if(root->key<RB && root->key>LB)
	{
		BST* illegalleft, *illegalright;
		int lRet = checkBST3(root->left,LB,root->key,&illegalleft);
		int rRight = checkBST3(root->left,LB,root->key,&illegalright);
		
		if(lRet && rRight)	// con trai va phai OK 
		{
			*illegalNode = NULL;
			return 1;
		}
		else if(lRet==0) // con trai vi pham
		{
			*illegalNode = illegalleft;
			return 0;
		}
		else 
		{
			*illegalNode = illegalright;
			return 0;
		}
	}	
	else
	{
		*illegalNode = root;
		return 0;
	}
}
