#include <iostream>

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if (m==0 && n==0) return 0;
    else if (m==0) {
      if (n%2 == 0) return (B[n/2-1]+B[n/2])/2.;
      else return B[n/2];
    }
    else if (n==0) {
      if (m%2 == 0) return (A[m/2-1]+A[m/2])/2.;
      else return A[m/2];
    }

    int i=0;
    int j=0;

    totalLength_ = m+n;
    count_ = 0;
    even_ = (m+n)%2==0;
    temp_ = 0;
    lastOne_ = false;
    found_ = false;
    result_ = 0.;

    while (i < m || j < n) {
      if ((A[i] < B[j] || j==n) && i<m) findMedian(A, i);
      else findMedian(B, j);
      if (found_) return result_;
      ++count_;
    }
  }

private:
  inline void findMedian(const int * A, int & i)
  {
    if (lastOne_) {
      found_ = true;
      result_ = (temp_+A[i])/2.;
    }
    if (even_ && (count_ == totalLength_/2-1)) {
      temp_ = A[i];
      lastOne_ = true;
    }
    else if (!even_ && (count_ == totalLength_/2)) {
      found_ = true;
      result_ = A[i];
    }
    ++i;
  }

  int totalLength_;
  int count_;
  bool even_;
  int temp_;
  bool lastOne_;
  bool found_;
  double result_;

  //   // Even total length
  //   if ((m+n)%2 == 0) {
  //     int temp = 0;
  //     bool lastOne = false;
  //     while (i < m || j < n) {
  // 	if ((A[i] < B[j] || j==n) && i<m) {
  // 	  if (lastOne) return (temp+A[i])/2.;
  // 	  if (count == totalLength/2-1) {
  // 	    temp = A[i];
  // 	    lastOne = true;
  // 	  }
  // 	  ++i;
  // 	}
  // 	else {
  // 	  if (lastOne) return (temp+B[j])/2.;
  // 	  if (count == totalLength/2-1) {
  // 	    temp = B[j];
  // 	    lastOne = true;
  // 	  }
  // 	  ++j;
  // 	}
  // 	++count;
  //     }
  //   }
  //   // Odd total length
  //   else {
  //     while (i < m || j < n) {
  // 	if ((A[i] < B[j] || j==n) && i<m) {
  // 	  if (count == totalLength/2) return A[i];
  // 	  ++i;
  // 	}
  // 	else {
  // 	  if (count == totalLength/2) return B[j];
  // 	  ++j;
  // 	}
  // 	++count;
  //     }
  //   }
  // }
};

int main()
{
  Solution a;

  // int A[4] = {1,2,3,4};
  // int B[3] = {1,2,3};
  // std::cout << "Median = " << a.findMedianSortedArrays(A, 4, B, 3) << std::endl;

  // int A[4] = {1,2,3,4};
  // int B[4] = {1,2,3,4};
  // std::cout << "Median = " << a.findMedianSortedArrays(A, 4, B, 4) << std::endl;

  // int A[2] = {3,4};
  // int B[0] = {};
  // std::cout << "Median = " << a.findMedianSortedArrays(A, 2, B, 0) << std::endl;

  int A[2] = {1,2};
  int B[2] = {1,2};
  std::cout << "Median = " << a.findMedianSortedArrays(A, 2, B, 2) << std::endl;

  // int A[1] = {1};
  // int B[1] = {1};
  // std::cout << "Median = " << a.findMedianSortedArrays(A, 1, B, 1) << std::endl;
}
