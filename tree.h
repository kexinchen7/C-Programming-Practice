/*
 common struct and functions for binary search tree
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// struct TreeNode in C
struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

// create a new TreeNode using malloc
struct TreeNode* newNode(int val) {
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	return node;	          
}
/*
void inOrder_recursive(struct TreeNode *root);
void preOrder_recursive(struct TreeNode *root);
void postOrder_recursive(struct TreeNode *root);
*/
// in-order traversal l-c-r
void inOrder_recursive(struct TreeNode *root) {
	if(root == NULL) {
		return;
	}

	if(root->left != NULL) {
		inOrder_recursive(root->left);
	}

	printf("%d\n", root->data);

	if(root->right != NULL) {
		inOrder_recursive(root->right);
	}
}


// pre-order traversal c-l-r
void preOrder_recursive(struct TreeNode *root) {
	if(root == NULL) {
		return;
	}

	printf("%d\n", root->data);

	if(root->left != NULL) {
		preOrder_recursive(root->left);
	}

	if(root->right != NULL) {
		preOrder_recursive(root->right);
	}
}

// post-order traversal l-r-c
void postOrder_recursive(struct TreeNode *root) {
	if(root == NULL) {
		return;
	}

	if(root->left != NULL) {
		postOrder_recursive(root->left);
	}

	if(root->right != NULL) {
		postOrder_recursive(root->right);
	}

	printf("%d\n", root->data);
}
