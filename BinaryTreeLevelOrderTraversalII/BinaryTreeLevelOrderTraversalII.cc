#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    traverse(root, 0);
    std::reverse(v.begin(), v.end());
    return v;
  }

  void traverse(TreeNode * node, int level)
  {
    if( node == 0 ) return;
    while( v.size() <= level ) v.push_back(vector<int>());
    v[level].push_back(node->val);
    traverse(node->left, level+1);
    traverse(node->right, level+1);
  }
  vector<vector<int> > v;
};

int main()
{
  std::cout << "" << std::endl;
  TreeNode n1(3);
  TreeNode n2(9);
  TreeNode n3(20);
  TreeNode n4(15);
  TreeNode n5(7);
  n1.left = &n2;
  n1.right = &n3;
  n3.left = &n4;
  n3.right = &n5;

  Solution a;
  vector<vector<int> > v(a.levelOrderBottom(&n1));

  for( int i=0; i<v.size(); ++i ) {
    for( int j=0; j<v[i].size(); ++j ) {
      std::cout << "v["<<i<<"]["<<j<<"] = " << v[i][j] << std::endl;
    }
  }

  return 0;
}
