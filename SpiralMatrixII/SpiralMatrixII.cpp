#include <iostream>
#include <vector>

/**
 * A simple variation of Spiral Matrix. The same method is used for the spiral loop.
 */

using namespace std;

class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    int lastRow = n-1;
    int lastColumn = n-1;
    int totalNum = n*n;
    
    int num = 0;
    int row = 0;
    int column = 0;
    while (num < totalNum) {
      
      // First row
      for (int j=column; j<=lastColumn; ++j) {
        ++num;
        matrix[row][j] = num;
      }
      ++row;
      
      if (num == totalNum) break;
      
      // Last column
      for (int i=row; i<=lastRow; ++i) {
        ++num;
        matrix[i][lastColumn] = num;
      }
      --lastColumn;
      
      if (num == totalNum) break;
      
      // Last row
      for (int j=lastColumn; j>=column; --j) {
        ++num;
        matrix[lastRow][j] = num;
      }
      --lastRow;
      
      if (num == totalNum) break;
      
      // First column
      for (int i=lastRow; i>=row; --i) {
        ++num;
        matrix[i][column] = num;
      }
      ++column;
      
      if (num == totalNum) break;
    }
    return matrix;
  }
};

int main()
{
  Solution a;
  vector<vector<int> > matrix(a.generateMatrix(4));

  for (auto v : matrix) {
    std::cout << "v.size() = " << v.size() << std::endl;
    for (auto i : v) std::cout << i << ", ";
    std::cout << std::endl;
  }
}