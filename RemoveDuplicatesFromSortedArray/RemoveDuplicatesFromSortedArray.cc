#include <iostream>

/*
  The more straightforward way is to start from the first, move any duplicate to the end and shrink the array.
  Adapt the length of the array to the new length when moving elements to the end to avoid wasting time.
 */

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if( n == 0 ) return n;
    int newLength = n;
    // std::cout << "A[n-1] = " << A[n-1] << std::endl;
    // std::cout << "A[n-2] = " << A[n-2] << std::endl;
    if( A[n-1] == A[n-2] ) newLength--;
    for( int i=n-2; i>0; --i ) {
      if( A[i] == A[i-1] ) {
	moveToEnd(A, i, newLength);
	newLength--;
      }
    }
    return newLength;
  }

  // Move the element i at the end of the array of size n
  void moveToEnd(int A[], int i, int n)
  {
    int valueToBeMoved = A[i];
    for( int j=i; j<n-1; ++j ) {
      A[j] = A[j+1];
    }
    A[n-1] = valueToBeMoved;
  }
};

int main()
{
  Solution a;
  int A[] = {1,1,2,2,3};

  for( int i=0; i<3; ++i ) std::cout << "A["<<i<<"] = " << A[i] << std::endl;

  int length = a.removeDuplicates(A, 5);
  for( int i=0; i<length; ++i ) std::cout << "reduced A["<<i<<"] = " << A[i] << std::endl;
  return 0;
}

