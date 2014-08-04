#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
  string convert(string s, int nRows) {
    if (nRows == 0 || nRows == 1) return s;
    int nRowsFrac = ceil(nRows/2);
    string c;

    int k = s.size()/ceil(ceil(nRows/2)/2+nRows/2);
    std::cout << "k = " << k << std::endl;
    int length = s.size()/nRows;

    for (int row=0; row<nRows; ++row) {
      int num = ceil(k/2);
      int j=0;
      while (j <= num) {
        int count = j*(nRows+nRowsFrac)+row;
        if (count < s.size()) {
          std::cout << "s["<<count<<"] = " << s[count] << std::endl;
          c += s[j*(nRows+nRowsFrac)+row];
        }
        if (nRows-1+count < s.size()) {
          if (row%2 != 0) {
            std::cout << "s["<<nRows-1+count<<"] = " << s[nRows-1+count] << std::endl;
            c += s[nRows-1+count];
          }
        }
        ++j;
      }
    }
    
    
    //    for (int i=0; i<nRows; ++i) {
//      for (int j=0; j<length; ++j) {
//        c += s[j+nRows+i + nRowsFrac];
//        // Skip this for even rows
//        if (j%2 != 0) c += s[j+nRows+i];
//        
//        // std::cout << "c["<<i*length+j<<"] = " << "s["<<j*nRows+i<<"] = " << s[j*nRows+i] << std::endl;
//      }
//    }
//    for (int i=0; i<s.size()%nRows; ++i) {
//      c += s[length+nRows+i + nRowsFrac];
//      if (length%2 != 0) c += s[length+nRows+i];
//      // c[i*length+nRows] = s[length*nRows+i];
//      // std::cout << "c["<<i*length+nRows<<"] = " << "s["<<length*nRows+i<<"] = " << s[length*nRows+i] << std::endl;
//    }
    return c;
  }
};

int main()
{
  Solution sol;
  // string c(sol.convert("PAYPALISHIRING", 3));
  string c(sol.convert("ABC", 2));
  
  std::cout << c << std::endl;
  
  return 0;
}