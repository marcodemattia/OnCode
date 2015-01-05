#include <iostream>

// We cannot use /, *, and mod. We could use additions of the divisor until we reach the dividend, but that
// is not the most efficient. We will instead use bitshifts to find how many multiplications by 2 we need to
// be close to the result, and we use the addition to fine tune. The bitshifts are equivalent to divide or
// multiply by 2 and are very fast.

class Solution {
public:
    int divide(int dividend, int divisor) {
      int result = 0;
      int sum = 0;
      absDividend_ = abs(dividend);
      absDivisor_ = abs(divisor);
      if (divisor ==  1) return dividend;
      if (divisor == -1) return -dividend;
      if (divisor ==  2) return dividend >> 1;
      if (divisor == -2) return -(dividend >> 1);
      if (divisor ==  4) return dividend >> 2;
      if (divisor == -4) return -(dividend >> 2);
      if (divisor ==  8) return dividend >> 4;
      if (divisor == -8) return -(dividend >> 4);

      int tempResult = 2;
      long temp = 0;
      while (tempResult > 1) {
	tempResult = bitShift(absDividend_ - temp);
	temp += temp_;
	// std::cout << "--------------- temp = " << temp << std::endl;
	// std::cout << "--------------- tempResult = " << tempResult << std::endl;
	result += tempResult;
	// std::cout << "result = " << result << std::endl;
      }
      // std::cout << "temp = " << temp << std::endl;
      while (temp < absDividend_) {
	++result;
	temp += absDivisor_;
      }
      if ((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0)) return (result-1);
      return -(result-1);
    }

  int bitShift(int dividend) {
    temp_ = absDivisor_;
    int counter = 1;
    while ((temp_<<counter) < dividend) {
      ++counter;
    }
    temp_ = temp_ << (counter-1);
    return (1 << (counter-1));
  }

  long temp_;
  int absDividend_;
  int absDivisor_;
};

int main()
{
  Solution a;
  int dividend = 2147483647;
  int divisor = 3;
  // int dividend = 1;
  // int divisor = 2;

  std::cout << dividend << "/" << divisor << " = " << a.divide(dividend, divisor) << std::endl;
}
