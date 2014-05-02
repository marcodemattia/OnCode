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
  bool hasPathSum(TreeNode *root, int sum) {
    if( root == 0 ) return 0;
    return traverse(root, 0, sum);
  }

  bool traverse(TreeNode *node, int partialSum, int sum) {
    partialSum += node->val;
    // std::cout << "partialSum = " << partialSum << std::endl;
    if( node->left == 0 && node->right == 0 && partialSum == sum) return true;
    if( node->left != 0 && traverse(node->left, partialSum, sum) == true) return true;
    if( node->right != 0 && traverse(node->right, partialSum, sum) == true) return true;
    return false;
  }
};

int main()
{
  TreeNode * t0 = new TreeNode(-2);
  TreeNode * t1 = new TreeNode(1);
  TreeNode * t2 = new TreeNode(-3);
  TreeNode * t3 = new TreeNode(3);
  // t0->left = t1;
  t0->right = t2;
  // t1->right = t3;

  Solution a;

  if( a.hasPathSum(t0, -5) ) std::cout << "has path sum" << std::endl;
  else std::cout << "does NOT have path sum" << std::endl;

}
