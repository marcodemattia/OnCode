#include <iostream>
#include <algorithm>

using namespace std;

/**
 * What matters is being able to jump over a 0. Loop and store the biggest reacheable index.
 * When a 0 is found check if the biggest reacheable index exceeds the index of the 0. If not
 * return false, if yes move to that index. If that new index is again a 0 backtrack until the
 * previous 0 to find if there is a way to jump over. However, a simpler version that looks at
 * all the numbers is to start from after that 0. If the next element is again a 0 move to the
 * next until you either find a non-null value or exceed the biggest reacheable index. We will
 * implement this simpler version. It will loop on most of the numbers in the sequence, the only
 * possible cutoff is when the maximum reacheable index exceed the sequence length, in which
 * case it returns true and skips the rest of the sequence. Corner case is when there is only
 * one element (or zero elements) in which case the result is automatically true.
 */

class Solution {
public:
  bool canJump(int A[], int n) {
    if (n<=1) return true;
    int maxJumpIndex = 0;
    for (int i=0; i<n; ++i) {
      // std::cout << "A["<<i<<"] = " << A[i] << std::endl;
      // std::cout << "maxJumpIndex = " << maxJumpIndex << std::endl;
      if (A[i] == 0) {
        if (maxJumpIndex > i) continue;
        else return false;
      }
      else if (i+A[i] >= n-1) return true;
      maxJumpIndex = max(i+A[i], maxJumpIndex);
    }
    return true;
  }
};

int main()
{
  // int A[5] = {2,3,1,1,4};
  int A[5] = {3,2,1,0,4};
  
  Solution a;
  if (a.canJump(A, 5)) std::cout << "true" << std::endl;
  else std::cout << "false" << std::endl;
  
  return 0;
}