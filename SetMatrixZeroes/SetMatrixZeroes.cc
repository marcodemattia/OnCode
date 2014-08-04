#include <iostream>
#include <vector>

/**
 * Clear the row as soon as it is found. Save the index of the columns.
 * After the main loop on the matrix loop on the marked columns only and set all their elements to zero.
 * This solution requires extra O(m) space.
 */

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int> > &matrix) {

    for( int i=0; i<matrix.size(); ++i ) {
      bool foundZero = false;
      for( int j=0; j<matrix[i].size(); ++j ) {
	if( matrix[i][j] == 0 ) {
	  foundZero = true;
	  columns.push_back(j);
	}
      }
      if( foundZero ) matrix[i] = vector<int>(matrix[i].size(), 0);
    }

    for( int j=0; j<columns.size(); ++j ) {
      for( int i=0; i<matrix.size(); ++i ) {
	matrix[i][columns[j]] = 0;
      }
    }
  }

  vector<int> columns;
};

int main()
{
  vector<vector<int> > matrix;
  for( int i=1; i<=10; ++i ) {
    matrix.push_back(vector<int>());
    for( int j=1; j<=5; ++j ) {
      matrix.back().push_back(j);
    }
  }
  matrix[6][3] = 0;

  Solution a;
  a.setZeroes(matrix);
  for( int i=0; i<matrix.size(); ++i ) {
    for( int j=0; j<matrix[i].size(); ++j ) {
      std::cout << "matrix["<<i<<"]["<<j<<"] = " << matrix[i][j] << std::endl;
    }
  }
}
