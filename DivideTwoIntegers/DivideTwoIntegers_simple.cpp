#include <iostream>

// We cannot use /, *, and mod. We could use additions of the divisor until we reach the dividend, but that
// is not the most efficient. We will instead use bitshifts to get close to the result first and the addition
// to fine tune. The bitshifts are equivalent to divide or multiply by 2 and are very fast.

class Solution {
public:
    int divide(int dividend, int divisor) {
      int result = 0;
      int sum = 0;
      int absDividend = abs(dividend);
      int absDivisor = abs(divisor);
      if (divisor == 1 || divisor == -1) result = dividend;
      else {
	while (sum < absDividend) {
	  ++result;
	  sum += absDivisor;
	}
      }
      if ((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0)) return (result-1);
      return -(result-1);
    }
};

int main()
{
  Solution a;
  int dividend = 101;
  int divisor = 5;

  std::cout << dividend << "/" << divisor << " = " << a.divide(dividend, divisor) << std::endl;
}
