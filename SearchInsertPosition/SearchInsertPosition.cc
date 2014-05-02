#include <iostream>

/*
  Binary search.
 */

class Solution {
public:
  Solution()
    : index(0)
  {}

  int searchInsert(int A[], int n, int target) {
    if(n==0) return 0;
    if( A[0] >= target ) return 0;
    if( A[n-1] < target ) return n;
    check(A, n, target);
    return index;
  }

  inline void check(int A[], int n, int target)
  {
    if( n == 1 ) return;
    if( A[int(n/2)-1] < target ) {
      index += int(n/2);
      return check(A+int(n/2), n-int(n/2), target);
    }
    return check(A, int(n/2), target);
  }

private:
  int index;

};

int main()
{
  int A[] = {1,3,5,6};

  Solution a;
  int index = a.searchInsert(A, 4, 7);
  std::cout << "target index = " << index << std::endl;;
}
