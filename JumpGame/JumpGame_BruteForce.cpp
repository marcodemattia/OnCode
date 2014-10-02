#include <iostream>

class Solution {
public:
  bool canJump(int A[], int n) {
    if (n==0) return true;
    
    length_ = 0;
    n_ = n;
    
    return jump(A, A[0]);
  }
  
private:
  bool jump(int A[], unsigned int num)
  {
    std::cout << "num = " << num << std::endl;
    if(length_ + num >= n_) return true;
    for (unsigned int j=num; j>0; --j) {
      std::cout << "A["<<j<<"] = " << A[j] << std::endl;
      length_+=j;
      if (jump(A, A[length_])) return true;
      length_-=j;
    }
    return false;
  }

  unsigned int length_;
  unsigned int n_;
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