#include <iostream>

class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    int newLength = n;
    for( int i=0; i<newLength; ++i ) {
      if(A[i] == elem) {
	for( int j=i; j<newLength-1; ++j ) {
	  A[j] = A[j+1];
	  A[j+1] = elem;
	}
	// This --i is because element i is now a new element after the swaps.
	// It still needs to be checked.
	--i;
	--newLength;
      }
    }
    return newLength;
  }
};

int main()
{
  int A[] = {3,3};
  int n = 2;
  Solution a;
  int newLength = a.removeElement(A, n, 3);

  std::cout << "new array of length = " << newLength << std::endl;
  for( int i=0; i<newLength; ++i ) std::cout << "A["<<i<<"] = " << A[i] << std::endl;

  return 0;
}
