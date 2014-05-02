#include <iostream>

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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if( p == 0 && q == 0 ) return true;
    else if( (p == 0 && q != 0) || (p != 0 && q == 0) ) return false;

    return traverse(p, q);
  }
  bool traverse(TreeNode *p, TreeNode *q) {
    std::cout << "p->val = " << p->val << std::endl;
    std::cout << "q->val = " << q->val << std::endl;
    if( p->val != q->val ) return false;
    std::cout << "here" << std::endl;

    if( p->left != 0 && q->left != 0 ) {
      if( !traverse(p->left, q->left) ) return false;
    }
    else if (!(p->left == 0 && q->left == 0)) return false;

    if( p->right != 0 && q->right != 0 ) {
      if( !traverse(p->right, q->right) ) return false;
    }
    else if (!(p->right == 0 && q->right == 0)) return false;
    return true;
  }
};


int main()
{
  TreeNode * t0 = new TreeNode(0);
  TreeNode * t1 = new TreeNode(-1);
  TreeNode * t2 = new TreeNode(2);
  t0->left = t1;
  t0->right = t2;

  TreeNode * s0 = new TreeNode(0);
  TreeNode * s1 = new TreeNode(1);
  TreeNode * s2 = new TreeNode(2);
  s0->left = s1;
  s0->right = s2;
  
  Solution a;
  if( a.isSameTree(t0, s0) ) std::cout << "same" << std::endl;

  return 0;
}
