#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * Using the C++11x features this is even simpler than it would be with the older standard.
 * The constant push_back and pop_back of the string is not very nice, but it minimizes the
 * memory at the cost of these continues calls.
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
  Solution()
    : sol(0)
  {}

  int sumNumbers(TreeNode *root) {
    traverse(root);
    return sol;
  }

  void traverse(TreeNode * node)
  {
    if( node == 0 ) return;
    // Assume there is always a number from 0 to 9 in val
    s.push_back(to_string(node->val)[0]);
    if( node->left == 0 && node->right == 0 ) {
      sol += stoi(s);
    }
    traverse(node->left);
    traverse(node->right);
    s.pop_back();
  }

  string s;
  int sol;
};

int main()
{
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3);
  n1.left = &n2;
  n1.right = &n3;

  Solution a;
  int sol = a.sumNumbers(&n1);

  std::cout << "sol = " << sol << std::endl;
}
