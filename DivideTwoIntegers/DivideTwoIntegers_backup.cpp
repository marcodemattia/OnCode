#include <iostream>
#include <climits>

// We cannot use /, *, and mod. We could use additions of the divisor until we reach the dividend, but that
// is not the most efficient. We will instead use bitshifts to find how many multiplications by 2 we need to
// be close to the result, and we use the addition to fine tune. The bitshifts are equivalent to divide or
// multiply by 2 and are very fast.

class Solution {
public:
    int divide(int dividend, int divisor) {
      int result = 0;
      int sum = 0;
      if (divisor == INT_MIN) {
	absDivisor_ = INT_MAX;
	absDivisor_ += 1;
      }
      else absDivisor_ = abs(divisor);
      if (dividend == INT_MIN) {
    	absDividend_ = INT_MAX;
	absDividend_ += 1;
      }
      else absDividend_ = abs(dividend);

      if (divisor ==  1) return dividend;
      if (divisor == -1) return -dividend;
      if (divisor ==  2) return dividend >> 1;
      if (divisor == -2) return -(dividend >> 1);
      // if (divisor ==  4) return dividend >> 2;
      // if (divisor == -4) return -(dividend >> 2);
      // if (divisor ==  8) return dividend >> 4;
      // if (divisor == -8) return -(dividend >> 4);

      if (absDividend_ < absDivisor_) return 0;

      // std::cout << "absDividend_ = " << absDividend_ << std::endl;
      // std::cout << "absDivisor_ = " << absDivisor_ << std::endl;


      // long temp = absDivisor_;
      long rest = absDividend_;
      // int counter = 2;
      int tempResult = 3;
      while (tempResult > 2) {
	// counter = 1;
	long temp = absDivisor_;
	tempResult = 1;
	while (temp < rest) {
	  // std::cout << "pppp = " << temp << std::endl;
	  // ++counter;
	  temp <<= 1;
	  tempResult <<= 1;
	}
	std::cout << "temp = " << temp << std::endl;
	std::cout << "rest = " << rest << std::endl;
	std::cout << "tempResult = " << tempResult << std::endl;
	temp >>= 1;
	tempResult >>= 1;
	rest -= temp;
	result += tempResult;
	std::cout << "result = " << result << std::endl;
	// std::cout << "temp = " << temp << ", tempResult = " << tempResult << std::endl;
      }
      while (rest > 0) {
	// std::cout << "rest = " << rest << std::endl;
	++result;
	rest -= absDivisor_;
      }
      if ((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0)) return (result-1);
      return -(result-1);
    }

  long absDividend_;
  long absDivisor_;
};

int main()
{
  Solution a;
  int dividend = 2147483647;
  int divisor = 3;
  // int dividend = 1;
  // int divisor = 2;
  // int dividend = 1004958205;
  // int divisor = -2137325331;

  // int dividend = -102626058;
  // int divisor = -2147483648;

  // int dividend = 1817210516;
  // int divisor = 1433032197;

  // int dividend = -1010369383;
  // int divisor = -2147483648;

  // for (int i=0; i<1000000; ++i) {
  //   a.divide(dividend, divisor);
  // }

  std::cout << dividend << "/" << divisor << " = " << a.divide(dividend, divisor) << std::endl;
}
