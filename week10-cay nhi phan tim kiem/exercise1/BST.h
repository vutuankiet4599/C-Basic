#ifndef BINARYSEARCHTREE_HEADER
#define BINARYSEARCHTREE_HEADER
typedef struct BSTNODE
{
	char data;
	int key;//khoa tim kiem
	struct BSTNODE *left,*right,*parent;
}BST;
BST *makeTree(char data,int key);
void addNode(char data,int key, BST *parent, int isleftChild);

int checkBST(BST *root,int LB,int RB);
//check bn co phai bst hay khong. neu khong tra ve nut dau tien
int checkBST2(BST *root,int LB,int RB,BST **illegalNODE);
int checkBST3(BST *root,int LB,int RB,BST **illegalNODE);
#endif
