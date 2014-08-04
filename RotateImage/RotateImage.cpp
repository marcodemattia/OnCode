#include <iostream>
#include <vector>

/**
 * When rotating the matrix by 90 degrees clockwise the index transformation is:
 * [i,j] -> [j,n-i-1], where the indeces i and j start from 0 and n is the length
 * of each row or column of the 2D n x n matrix.
 * We do the rotation in place. We start from the external shell of the matrix
 * and we recursively go inside to rotate smaller squares until every element
 * has been rotated.
 */

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    if (matrix.size() == 0) {
      return;
    }
    else lineLength = matrix.size();

    rotate(0, matrix);
  }

  void rotate(int i, vector<vector<int> > &matrix)
  {
    if (i >= lineLength/2) {
      return;
    }
    for (int j = i; j<lineLength-i-1; ++j) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[lineLength-j-1][i];
      matrix[lineLength-j-1][i] = matrix[lineLength-i-1][lineLength-j-1];
      matrix[lineLength-i-1][lineLength-j-1] = matrix[j][lineLength-i-1];
      matrix[j][lineLength-i-1] = temp;
    }
    rotate(i+1, matrix);
  }

  int lineLength;
};

int main()
{
  Solution a;
  
  std::vector<std::vector<int> > matrix;
  matrix.push_back(std::vector<int>({1,2,3}));
  matrix.push_back(std::vector<int>({4,5,6}));
  matrix.push_back(std::vector<int>({7,8,9}));
  
  std::cout << std::endl;
  std::cout << "Before rotation:" << std::endl;
  std::cout << std::endl;

  for (auto line : matrix) {
    std::cout << "| ";
    for (auto value : line) {
      std::cout << value << " | ";
    }
    std::cout << std::endl;
  }

  
  a.rotate(matrix);

  std::cout << std::endl;
  std::cout << "After rotation:" << std::endl;
  std::cout << std::endl;
  
  for (auto line : matrix) {
    std::cout << "| ";
    for (auto value : line) {
      std::cout << value << " | ";
    }
    std::cout << std::endl;
  }

  
  return 0;
}