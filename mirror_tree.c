/* Change a tree so that the roles of the  left and 
    right pointers are swapped at every node.

 So the tree...
       4
      / \
     2   5
    / \
   1   3

 is changed to...
       4
      / \
     5   2
        / \
       3   1
*/

#include "tree.h"

// in-place
void mirror_inplace(struct TreeNode* node) 
{
  if (node==NULL) {
    return;  
  }
  else 
  {
    struct TreeNode* temp;
    
    /* do the subtrees */
    mirror_inplace(node->left);
    mirror_inplace(node->right);

    /* swap the pointers in this node */
    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }
} 

// create a mirror tree 
struct TreeNode* create_mirror(struct TreeNode* node) {
  if (node == NULL) {
    return NULL;
  } else {
    struct TreeNode *mirror_head = newNode(node->data);
    
    mirror_head->left  = create_mirror(node->right);
    mirror_head->right = create_mirror(node->left);
    
    return mirror_head;
  }
}

int main()
{
  struct TreeNode *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
  
  /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder_recursive(root);
  
  /* Convert tree to its mirror */
  mirror_inplace(root); 
  
  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n");  
  inOrder_recursive(root);
  
  printf("\n Creating a mirror tree: \n");
  inOrder_recursive(create_mirror(root));

  return 0;  
}