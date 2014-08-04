#include <climits>
#include <iostream>
#include <algorithm>

/**
 * Go recursively down the tree. At each point check the sum of the left optimal and right optimal
 * subtrees. Check them against the best single node value (others could be negative) and against
 * the node + left + right (single block). The code is made more complicated by the checks for the
 * cases of an empty node and this part could probably be simplified.
 */

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
  int maxPathSum(TreeNode *root) {

    maxNode = INT_MIN;
    maxNodeBlock = INT_MIN;
    if( root == 0 ) return 0;
    // if( root->left == 0 && root->right == 0 ) return root->val;
    int maxTreeSum = findMax(root);
    std::cout << "max = " << std::max(maxTreeSum, std::max(maxNode, maxNodeBlock)) << std::endl;
    return std::max(maxTreeSum, std::max(maxNode, maxNodeBlock));
  }

  int findMax(TreeNode * node)
  {
    if( node == 0 ) return 0;

    int left = findMax(node->left);
    int right = findMax(node->right);

    std::cout << "left = " << left << ", right = " << right << std::endl;

    // Check the best single node
    if( node->val > maxNode ) maxNode = node->val;
    if( maxNodeBlock < node->val + left + right ) maxNodeBlock = node->val + left + right;

    if( node->left != 0 && maxNodeBlock < left ) maxNodeBlock = left;
    if( node->right != 0 && maxNodeBlock < right ) maxNodeBlock = right;

    int returnValue = 0;
    if( node->left == 0 && node->right == 0 ) returnValue = node->val;
    else if( node->left != 0 && node->right != 0 )
      returnValue = (left > right ? node->val+left : node->val+right);
    else if( node->left != 0 ) returnValue = node->val+left;
    else returnValue = node->val+right;
    return std::max(returnValue, node->val);
  }

  int maxNode;
  int maxNodeBlock;
};


int main()
{
  // TreeNode a1(1);
  // TreeNode a2(2);
  // TreeNode a3(3);
  // a1.left = &a2;
  // a1.right = &a3;


  // // {5,4,8,11,#,13,4,7,2,#,#,#,1}
  // TreeNode a1(5);
  // TreeNode a2(4);
  // TreeNode a3(8);
  // a1.left = &a2;
  // a1.right = &a3;
  // TreeNode a4(11);
  // a2.left = &a4;
  // TreeNode a6(13);
  // TreeNode a7(4);
  // a3.left = &a6;
  // a3.right = &a7;
  // TreeNode a8(7);
  // TreeNode a9(2);
  // a4.left = &a8;
  // a4.right = &a9;
  // TreeNode a13(1);
  // a6.right = &a13;


  // // {-1,#,9,-6,3,#,#,#,-2}
  // TreeNode a1(-1);
  // TreeNode a3(9);
  // a1.right = &a3;
  // TreeNode a4(-6);
  // TreeNode a5(3);
  // a3.left = &a4;
  // a3.right = &a5;
  // TreeNode a9(-2);
  // a5.right = &a9;


  // {-3}
  // TreeNode a1(-3);


  // {-2,-1}
  // TreeNode a1(-2);
  // TreeNode a2(-1);
  // a1.left = &a2;


  // {-1,5,#,4,#,#,2,-4}
  // TreeNode a1(-1);
  // TreeNode a2(5);
  // a1.left = &a2;
  // TreeNode a4(4);
  // a2.left = &a4;
  // TreeNode a7(2);
  // a4.right = &a7;
  // TreeNode a8(-4);
  // a7.left = &a8;


  // {1,2,#,3,#,4,#,5}
  TreeNode a1(1);
  TreeNode a2(2);
  a1.left = &a2;
  TreeNode a4(3);
  a2.left = &a4;
  TreeNode a6(4);
  a4.left = &a6;
  TreeNode a8(5);
  a6.left = &a8;

  Solution a;
  std::cout << a.maxPathSum(&a1) << std::endl;
  return 0;
}
