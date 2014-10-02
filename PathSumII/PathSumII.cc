#include <iostream>
#include <vector>

using namespace std;

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
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    sol_.clear();
    if( root == 0 ) return sol_;
    traverse(root, 0, sum);
    return sol_;
  }

private:
  void traverse(TreeNode *node, int partialSum, int sum) {
    v_.push_back(node->val);
    partialSum += node->val;
    // std::cout << "partialSum = " << partialSum << std::endl;
    if (node->left == 0 && node->right == 0 && partialSum == sum) {
      // Fill the solution
      sol_.push_back(v_);
    }
    if (node->left != 0) traverse(node->left, partialSum, sum);
    if (node->right != 0) traverse(node->right, partialSum, sum);
    v_.pop_back();
  }
  
  vector<int> v_;
  vector<vector<int> > sol_;
};

int main()
{
  TreeNode * t0 = new TreeNode(5);
  TreeNode * t1 = new TreeNode(4);
  TreeNode * t2 = new TreeNode(8);
  t0->left = t1;
  t0->right = t2;
  TreeNode * t3 = new TreeNode(11);
  t1->left = t3;
  TreeNode * t4 = new TreeNode(7);
  TreeNode * t5 = new TreeNode(2);
  t3->left = t4;
  t3->right = t5;
  TreeNode * t6 = new TreeNode(13);
  TreeNode * t7 = new TreeNode(4);
  t2->left = t6;
  t2->right = t7;
  TreeNode * t8 = new TreeNode(5);
  TreeNode * t9 = new TreeNode(1);
  t7->left = t8;
  t7->right = t9;
  

  Solution a;

  vector<vector<int> > sol(a.pathSum(t0, 22));
  
  for (auto v : sol) {
    for (int num : v) {
      std::cout << num << ", ";
    }
    std::cout << std::endl;
  }
}
