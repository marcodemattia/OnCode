#include <iostream>
#include <vector>
#include <string>

/**
 * Same as NQueens except the need to return the solutions in string format. Only the number
 * of distinct solutions is required, which makes the code simpler.
 */

using namespace std;

class Solution {
public:
  int totalNQueens(int n) {
    numSol = 0;
    
    column = new bool[n];
    diagonal = new bool[2*n-1];
    antidiagonal = new bool[2*n-1];
    for (int i=0; i<n; ++i) {
      column[i] = false;
    }
    for (int i=0; i<2*n-1; ++i) {
      diagonal[i] = false;
      antidiagonal[i] = false;
    }
    N = n;
    
    processRow(0);
    
    delete[] column;
    delete[] diagonal;
    delete[] antidiagonal;
    
    return numSol;
  }
  
  void processRow(unsigned int i) {
    if (i >= N) {
      ++numSol;
      return;
    }
    
    for (int j=0; j<N; ++j) {
      int dd = i-j+N-1;
      int ad = i+j;
      if (!column[j] && !diagonal[dd] && !antidiagonal[ad]) {
        column[j] = true;
        diagonal[dd] = true;
        antidiagonal[ad] = true;
        processRow(i+1);
        column[j] = false;
        diagonal[dd] = false;
        antidiagonal[ad] = false;
      }
    }
  }
  
  unsigned int N;
  bool * column;
  bool * diagonal;
  bool * antidiagonal;
  unsigned int numSol;
};

int main()
{
  Solution a;
  
  int n = 6;
  // auto sol = a.solveNQueens(n);

  std::cout << "number of distinct solution for " << n << " queens = " << a.solveNQueens(n) << std::endl;

  // for (auto & vv : sol) {
  //   int i=0;
  //   for (auto & v : vv) {
  //     std::cout << v << std::endl;
  //   }
  //   std::cout << std::endl;
  // }

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
