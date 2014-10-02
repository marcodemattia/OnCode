#include <iostream>
#include <vector>
#include <string>

/**
 * The problem only states 2D board, but it does not specify if it is square or not.
 * For simplicity we will assume it is a square.
 */

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char> > &board, string word) {
    size_ = board.size();
    // Compute size of the board in x and y in the assumption that it is a square.
    
    

    return false;
  }
  navigate()

  unsigned int size_;

};

int main()
{
  vector<vector<char> > board;
  vector<char> v;
  v.push_back('A');
  v.push_back('B');
  v.push_back('C');
  v.push_back('E');
  board.push_back(v);
  vector<char> v2;
  v2.push_back('S');
  v2.push_back('F');
  v2.push_back('C');
  v2.push_back('S');
  board.push_back(v2);
  vector<char> v3;
  v2.push_back('A');
  v2.push_back('D');
  v2.push_back('E');
  v2.push_back('E');
  board.push_back(v3);

  string word("ABCCED");

  Solution a;
  if (a.exist(board, word)) std::cout << "true" << std::endl;
  else std::cout << "false" << std::endl;

  return 0;
}
