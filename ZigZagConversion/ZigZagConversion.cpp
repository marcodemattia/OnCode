#include <iostream>
#include <string>
#include <math.h>

/**
 * We append the characters in the new string by computing the position and taking them directly
 * from the input string. We loop on the rows, if it is the first or the last row each position
 * starts from the row index and moves forward by 2*(nRows-1). If it is one of the middle rows
 * (of which there are nRows - 2) we also append a character from the diagonal, which has an
 * index given by the current index + 2*(nRows - 2 - row). It is the current row number plus
 * as many rows as it is needed to go to the last row and come to the current row along the
 * diagonal.
 */

using namespace std;

class Solution {
public:
  string convert(string s, int nRows) {
    std::string c;
    if (nRows == 0 || nRows == 1) return s;
    int length = s.size();
    c.reserve(length);
    
    int nRowsIndex = nRows - 1;
    for (int row=0; row<nRows; ++row) {
      int k = row;
      while(k < length) {
        c += s[k];
        int diagonalIndex = k + 2*(nRowsIndex - row);
        if (diagonalIndex < length) {
          if (row != 0 && row != nRowsIndex) {
            c += s[diagonalIndex];
          }
        }
        k += 2*nRowsIndex;
      }
    }
    return c;
  }
};

int main()
{
  Solution sol;
  string c(sol.convert("PAYPALISHIRING", 3));
  // string c(sol.convert("ABC", 2));
  
  std::cout << c << std::endl;
  
  return 0;
}