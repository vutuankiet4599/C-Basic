#include <stdio.h>
#include "binarytree.h"


int main()
{
	TN *root = NULL;
	root=makeTree('A');
	addNode('B',root,1);
	addNode('D',root,0);
	addNode('C',root->right,1);
	addNode('E',root->right,0);
	addNode('H',root->right->left,1);
	addNode('G',root->right->left,0);
	addNode('F',root->right->right,1);
	addNode('I',root->right->left->right,1);
	printf("Thu tu truoc:\n");
	preOrderTraversal(root);
	printf("\n");
	printf("Thu tu giua:\n");
	inOrderTraversal(root);
	printf("\n");
	printf("Thu tu sau:\n");
	posOrderTraversal(root);
	printf("\n");
	printf("Chieu cao cay: %d\n",height(root));
	printf("So nut: %d\n",countNodes(root));
	printf("So nut la: %d\n",countLeaves(root));
	printf("So nut trong la: %d\n",countIntenalNodes(root));
	printf("Duyet theo cap bac: ");
	levelOrderTraversal(root);
	printf("\n");
	
	TN *lastLeaf = depestLeaf(root);
	printf("La sau nhat la %c\n",lastLeaf->data);
	TN *firstLeaf = shallowestLeaf(root);
	printf("La nong nhat la %c\n",firstLeaf->data);
    return 0;
}
