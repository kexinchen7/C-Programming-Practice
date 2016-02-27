#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    // initializer list: when some member is class type, 
    // and no assignmen operator defined for this class type
    TreeNode(int x):val(x), left(NULL), right(NULL){} 
};

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in 
   increasing sorted order.*/
void inOrder(TreeNode* node) 
{
  if (node == NULL) 
    return;
  
  inOrder(node->left);
  cout << node->val << endl;

  inOrder(node->right);
}

TreeNode* mirror_tree(TreeNode* root) {
    if(root == NULL) {
        return NULL;
    }
    TreeNode *temp = new TreeNode(root->val);
    temp->left = mirror_tree(root->right);
    temp->right = mirror_tree(root->left);
    return temp;
}

/* Driver program to test mirror() */
int main()
{
  TreeNode *root    = new TreeNode(4);
  root->left        = new TreeNode(2);
  root->right       = new TreeNode(5);
  root->left->left  = new TreeNode(1);
  root->left->right = new TreeNode(3); 
  
  /* Print inorder traversal of the input tree */
  cout << "Inorder traversal of the constructed tree is" << endl;
  inOrder(root);
  
  /* Convert tree to its mirror */
  TreeNode *mirror = mirror_tree(root);
  
  /* Print inorder traversal of the mirror tree */
  cout << "Inorder traversal of the mirror tree is" << endl;  
  inOrder(mirror);
  return 0;  
}




