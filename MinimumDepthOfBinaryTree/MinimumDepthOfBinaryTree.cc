#include <iostream>

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  Solution() :
    minDepth_(-1)
  {}

  int minDepth(TreeNode *root) {
    if( root == 0 ) return 0;
    traverse(root, 0);
    return minDepth_;
  }

  void traverse(TreeNode *node, int level) {
    ++level;
    // std::cout << "level = " << level << std::endl;
    if( minDepth_ != -1 && level > minDepth_ ) return;
    if( node->left == 0 && node->right == 0 ) minDepth_ = level;
    if( node->left != 0 ) traverse(node->left, level);
    if( node->right != 0 ) traverse(node->right, level);
  }

  int minDepth_;
};

int main()
{
  TreeNode * t0 = new TreeNode(0);
  TreeNode * t1 = new TreeNode(-1);
  TreeNode * t2 = new TreeNode(2);
  TreeNode * t3 = new TreeNode(3);
  t0->left = t1;
  t0->right = t2;
  // t1->right = t3;

  Solution a;
  std::cout << "minDepth = " << a.minDepth(t0) << std::endl;
}
