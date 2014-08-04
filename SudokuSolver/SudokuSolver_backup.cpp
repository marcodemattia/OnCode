#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solveSudoku(vector<vector<char> > &board) {
    std::cout << "solving" << std::endl;
    char c[9][9];
    
    
  }
};

int main() {
  
  std::vector<std::vector<char> > v;
  for (int i=0; i<9; ++i) {
    v.push_back(std::vector<char>());
    for (int j=0; j<9; ++j) {
      v.back().push_back('.');
    }
  }
  v[0][0] = '5';
  v[0][1] = '3';
  v[0][4] = '7';
  v[1][0] = '6';
  v[1][3] = '1';
  v[1][4] = '9';
  v[1][5] = '5';
  v[2][1] = '9';
  v[2][2] = '8';
  v[2][7] = '6';
  v[3][0] = '8';
  v[3][4] = '6';
  v[3][8] = '3';
  v[4][0] = '4';
  v[4][3] = '8';
  v[4][5] = '3';
  v[4][8] = '1';
  v[5][0] = '7';
  v[5][4] = '2';
  v[5][8] = '6';
  v[6][1] = '6';
  v[6][6] = '2';
  v[6][7] = '8';
  v[7][3] = '4';
  v[7][4] = '1';
  v[7][5] = '9';
  v[7][8] = '5';
  v[8][4] = '8';
  v[8][7] = '7';
  v[8][8] = '9';
  
  for (int i=0; i<9; ++i) {
    for (int j=0; j<9; ++j) {
      std::cout << v[i][j];
    }
    std::cout << std::endl;
  }
  
  Solution a;
  a.solveSudoku(v);
  return 0;
}
