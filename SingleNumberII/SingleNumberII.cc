#include <iostream>
#include <algorithm>

class Solution {
public:
  int singleNumber(int A[], int n) {

    if( n == 0 ) return 0;
    if( n == 1 ) return A[0];

    std::sort(A, A+n);
    for( int i=0; i<n-2; i+=3 ) {
      // std::cout << "A["<<i<<"] = " << A[i] << " == A["<<i+2<<"] = " << A[i+2] << std::endl;
      if( A[i] != A[i+2] ) return A[i];
    }
    if( A[n-1] != A[n-2] ) return A[n-1];
    return 0;
  }
};

int main()
{
  Solution a;

  // int A[3] = {2,2,1};
  // std::cout << "the single number is: " << a.singleNumber(A, 3) << std::endl;
  // int B[7] = {1,1,6,6,5,20,20};
  // std::cout << "the single number is: " << a.singleNumber(B, 7) << std::endl;


  int C[30001];
  for( int i=0; i<10000; ++i ) {
    C[i] = i;
    C[i+10000] = i;
    C[i+20000] = i;
    // std::cout << "C["<<i<<"] = " << C[i] << " == C["<<i+1<<"] = " << C[i+1] << std::endl;
  }
  C[30000] = 10000;

  std::cout << "the single number is: " << a.singleNumber(C, 30001) << std::endl;

  return 0;
}
