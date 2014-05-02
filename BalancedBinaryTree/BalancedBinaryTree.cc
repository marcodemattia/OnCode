#include <iostream>
#include <algorithm>

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if(root == 0) return true;
    if( traverse(root, 0) == -1 ) return false;
    return true;
  }

  int traverse(TreeNode *node, int level) {
    if( node == 0 ) return level;
    // if( node->left == 0 && node->right == 0 ) return level+1;
    // if( (node->left == 0 && node->right != 0) || (node->left != 0 && node->right) == 0 ) return level+1;

    // std::cout << "level = " << level << std::endl;

    int leftDepth = traverse(node->left, level+1);
    int rightDepth = traverse(node->right, level+1);
    // std::cout << "leftDepth = " << leftDepth << std::endl;
    // std::cout << "rightDepth = " << rightDepth << std::endl;
    if( leftDepth == -1 ) return -1;
    if( rightDepth == -1 ) return -1;
    if(abs(leftDepth - rightDepth) > 1) return -1;

    // std::cout << "max = " << std::max(leftDepth, rightDepth) << std::endl;
    return std::max(leftDepth, rightDepth);

    // if( node->left == 0 && node->right == 0 ) return true;
    // if( node->left == 0 && node->right != 0 ) {
    //   if( node->right->left !=0 || node->right->right != 0 ) return false;
    // }
    // if( node->left != 0 && node->right == 0 ) {
    //   if( node->left->left !=0 || node->left->right != 0 ) return false;
    // }
    // if( node->left != 0 && node->right != 0 ) {
    //   if( !traverse(node->left) ) return false;
    //   if( !traverse(node->right) ) return false;
    // }
    // return true;
  }
};

int main()
{
  TreeNode * t0 = new TreeNode(0);
  TreeNode * t1 = new TreeNode(-1);
  TreeNode * t2 = new TreeNode(2);
  TreeNode * t3 = new TreeNode(3);
  t0->left = t1;
  // t0->right = t2;
  t1->right = t3;

  Solution a;
  if( a.isBalanced(t0) ) std::cout << "balanced" << std::endl;

  return 0;
}
