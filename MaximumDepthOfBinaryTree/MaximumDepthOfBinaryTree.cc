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
  int maxDepth(TreeNode *root) {
    if( root == 0 ) return 0;
    return traverse(root, 0);
  }

  int traverse(TreeNode *p, int level) {
    ++level;
    int leftLevel = level;
    int rightLevel = level;
    if( p->left != 0 ) leftLevel = traverse(p->left, level);
    if( p->right != 0 ) rightLevel = traverse(p->right, level);
    return std::max(leftLevel, rightLevel);
  }
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
  std::cout << "maxLevel = " << a.maxDepth(t0) << std::endl;

  return 0;
}
