#include <iostream>
#include <vector>
#include <string>

/**
 * Solve with DSF (depth search first) and constraints. Once a queen is placed in a square we
 * write its position in the array of row, column and the two diagonals. Each of them will be
 * cleaned when backtracking. The row and column arrays contain, obviously, n elements, while
 * the diagonals have 2n-1. We also use a matrix to store the positions of the queens (the
 * contraints are not enough to infer them). All these arrays and the matrix are dynamically
 * allocated in each function call. If we reach the last row we use the matrix to write the
 * vector of strings with the solution.
 */

using namespace std;

class Solution {
public:
  vector<vector<string> > solveNQueens(int n) {
    sol.clear();

    column = new bool[n];
    diagonal = new bool[2*n-1];
    antidiagonal = new bool[2*n-1];
    matrix = new bool*[n];
    for (int i=0; i<n; ++i) {
      matrix[i] = new bool[n];
      for (int j=0; j<n; ++j) {
        matrix[i][j] = false;
      }
    }
    N = n;
    
    processRow(0);
    
    delete[] column;
    delete[] diagonal;
    delete[] antidiagonal;
    for (int i=0; i<n; ++i) {
      delete[] matrix[i];
    }
    delete[] matrix;
  
    return sol;
  }
  
  void processRow(unsigned int i) {
    if (i >= N) {
      // Fill the solution
      sol.push_back(vector<string>());
      for (int i=0; i<N; ++i) {
        string s(N, '.');
        for (int j=0; j<N; ++j) {
          if (matrix[i][j]) s[j] = 'Q';
        }
        sol.back().push_back(s);
      }
      return;
    }

    for (int j=0; j<N; ++j) {
      int dd = i-j+N-1;
      int ad = i+j;
      if (!column[j] && !diagonal[dd] && !antidiagonal[ad]) {
        column[j] = true;
        diagonal[dd] = true;
        antidiagonal[ad] = true;
        matrix[i][j] = true;
        processRow(i+1);
        column[j] = false;
        diagonal[dd] = false;
        antidiagonal[ad] = false;
        matrix[i][j] = false;
      }
    }
  }

  unsigned int N;
  bool * column;
  bool * diagonal;
  bool * antidiagonal;
  bool ** matrix;
  vector<vector<string> > sol;
};

int main()
{
  Solution a;
  
  int n = 4;
  auto sol = a.solveNQueens(n);

  for (auto & vv : sol) {
    int i=0;
    for (auto & v : vv) {
      std::cout << v << std::endl;
    }
    std::cout << std::endl;
  }

//  sol = a.solveNQueens(n-1);
//
//  for (auto & vv : sol) {
//    int i=0;
//    for (auto & v : vv) {
//      std::cout << v << std::endl;
//    }
//    std::cout << std::endl;
//  }
}