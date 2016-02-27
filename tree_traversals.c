
#include "tree.h"

int main() {
	struct TreeNode *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("In-Order traversal: \n");
	inOrder_recursive(root);

	printf("Pre-Order traversal: \n");
	preOrder_recursive(root);

	printf("Post-Order traversal: \n");
	postOrder_recursive(root);

	return 0;

}

/*
   1
 2   3
4 5

inOrder: 4 2 5 1 3
preOrder: 1 2 4 5 3
postOrder: 4 5 2 3 1
*/

