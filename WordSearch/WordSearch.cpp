#include <iostream>
#include <vector>
#include <string>

/**
 * The problem only states 2D board, but it does not specify if it is a rectangle or not.
 * For simplicity we will assume it is a rectangle. For each position in the board where
 * the character matches the first character in the word we navigate in search of the
 * following characters in adiacent cells. As soon as we find a match we stop and return
 * true. We keep track of the visited cells in each recursion using a separate board.
 */

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char> > &board, string word) {
    board_ = &board;
    wordLength_ = word.length();
    if (wordLength_ == 0) return true;
    word_ = &word;
    sizeX_ = board.size();
    if (sizeX_ == 0) return false;
    sizeY_ = board[0].size();
    
    for (unsigned int i=0; i<sizeX_; ++i) {
      visited_.push_back(vector<bool>(sizeY_, false));
    }

    // For convenience of comparison with the indeces
    --wordLength_;
    --sizeX_;
    --sizeY_;

    for (unsigned int j=0; j<=sizeY_; ++j) {
      for (unsigned int i=0; i<=sizeX_; ++i) {
	// std::cout << "i = " << i << ", j = " << j << std::endl;
	if (navigate(i, j, 0)) return true;
      }
    }

    return false;
  }

  bool navigate(const int i, const int j, const int k)
  {
    if (visited_[i][j]) return false;
    else visited_[i][j] = true;
    // std::cout << "i, j, k = " << i << ", " << j << ", " << k << ", wordLength = " << wordLength_ << std::endl;
    // if (k == wordLength_) return true;
    // for (auto & a : (*board_)[i]) std::cout << a << std::endl;
    if ((*board_)[i][j] == (*word_)[k]) {
      // std::cout << k << ", "<< (*board_)[i][j] << std::endl;
      if (k == wordLength_) return true;
      if (i < sizeX_ && navigate(i+1, j, k+1)) return true;
      if (i > 0 && navigate(i-1, j, k+1)) return true;
      if (j < sizeY_ && navigate(i, j+1, k+1)) return true;
      if (j > 0 && navigate(i, j-1, k+1)) return true;
    }
    visited_[i][j] = false;
    return false;
  }

  unsigned int sizeX_;
  unsigned int sizeY_;
  int wordLength_;
  string * word_;
  vector<vector<char> > * board_;
  vector<vector<bool> > visited_;

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
  v3.push_back('A');
  v3.push_back('D');
  v3.push_back('E');
  v3.push_back('E');
  board.push_back(v3);

  for (auto & a : board) {
    for (auto & b : a) std::cout << b;
    std::cout << std::endl;
  }

  // string word("ABCCED");
  string word("ABCCED");

  Solution a;
  if (a.exist(board, word)) std::cout << "true" << std::endl;
  else std::cout << "false" << std::endl;

  return 0;
}
