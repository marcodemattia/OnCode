#include <iostream>
#include <vector>

/**
 * Start from the first row and continue clockwise. After finishing a row or column increase the
 * corresponding index to shrink the part of matrix to be explored.
 */

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> sol;
    if (matrix.size() == 0) return sol;
    int lastRow = matrix.size()-1;
    int lastColumn = matrix[0].size()-1;
    int totalNum = (lastRow+1)*(lastColumn+1);
    sol.reserve(totalNum);

    int num = 0;
    int row = 0;
    int column = 0;
    while (num < totalNum) {

      // First row
      for (int j=column; j<=lastColumn; ++j) {
        sol.push_back(matrix[row][j]);
        ++num;
      }
      ++row;
      
      if (num == totalNum) break;

      // Last column
      for (int i=row; i<=lastRow; ++i) {
        sol.push_back(matrix[i][lastColumn]);
        ++num;
      }
      --lastColumn;
      
      if (num == totalNum) break;

      // Last row
      for (int j=lastColumn; j>=column; --j) {
        sol.push_back(matrix[lastRow][j]);
        ++num;
      }
      --lastRow;
      
      if (num == totalNum) break;

      // First column
      for (int i=lastRow; i>=row; --i) {
        sol.push_back(matrix[i][column]);
        ++num;
      }
      ++column;
      
      if (num == totalNum) break;
    }
    return sol;
  }
};

int main()
{
  vector<vector<int> > matrix;
//  matrix.push_back(vector<int>(3, 0));
//  matrix.push_back(vector<int>(3, 1));
//  matrix.push_back(vector<int>(3, 2));
  vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  matrix.push_back(v1);
  vector<int> v2;
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(6);
  matrix.push_back(v2);
  vector<int> v3;
  v3.push_back(7);
  v3.push_back(8);
  v3.push_back(9);
  matrix.push_back(v3);
  
  for (auto v : matrix) {
    for (auto i : v) std::cout << i << ", ";
    std::cout << std::endl;
  }
  
  Solution a;
  vector<int> sol(a.spiralOrder(matrix));

  for (auto i : sol) {
    std::cout << i << std::endl;
  }
}