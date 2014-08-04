#include <iostream>
#include <vector>

/**
 * Pascal's triangle shows the coefficient of the polynomials (a+b)^n. For n = 1 the coefficient is 1.
 * For element i in row k the value is computed as the sum of the values of i and i+1 from row k-1.
 * The first row has only one term of value 1.
 */

using namespace std;

class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > sol;
    if (numRows == 0) return sol;
    
    sol.push_back(vector<int>({1}));

    for (int row=1; row < numRows; ++row) {
      int previousSize = sol[row-1].size();
      vector<int> nextRow({1});
      for (int i=0; i<previousSize-1; ++i) {
        nextRow.push_back(sol[row-1][i]+sol[row-1][i+1]);
      }
      nextRow.push_back(1);
      sol.push_back(nextRow);
    }
    
    return sol;
  }
};

int main()
{
  Solution a;
  
  std::vector<std::vector<int> > sol(a.generate(20));
  
  for (auto row : sol) {
    for (auto value : row) {
      std::cout << value << ", ";
    }
    std::cout << std::endl;
  }
  
  return 0;
}