#ifndef BINARYTREE_HEADER
#define BINARYTREE_HEADER
typedef struct TREENODE
{
	char data;
	struct TREENODE *left, *right, *parent;
}TN;
TN *makeTree(char data);
void addNode(char data, TN *parent, int isleftChild);
//duyet cay theo chieu sau
void preOrderTraversal(const TN *root);
void posOrderTraversal(const TN *root);
void inOrderTraversal(const TN *root);
//duyet cay theo muc
void levelOrderTraversal(const TN *root);
//tinh chieu cao cua cay
int height(const TN *root);
//dem so nut
int countNodes(const TN *root);
int countLeaves(const TN *root);
int countIntenalNodes(const TN *root);
//Tim nut sau nhat
TN* depestLeaf(const TN *root);
//Tim nut la nong nhat
TN *shallowestLeaf(const TN *root);
#endif
