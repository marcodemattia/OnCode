#include <iostream>
#include <cmath>

// We cannot use /, *, and mod. We could use additions of the divisor until we reach the dividend, but that
// is not the most efficient. We will instead use bitshifts to find how many multiplications by 2 we need to
// be close to the result, and we use the addition to fine tune. The bitshifts are equivalent to divide or
// multiply by 2 and are very fast.

class Solution {
public:
  int divide(int dividend, int divisor) {
    int result = 0;
    long absDividend(dividend);
    absDividend = std::abs(absDividend);
    long absDivisor(divisor);
    absDivisor = std::abs(absDivisor);
    if (divisor ==  1) return dividend;
    if (divisor == -1) return -dividend;
    if (divisor ==  2) return dividend >> 1;
    if (divisor == -2) return -(dividend >> 1);

    long rest = absDividend;
    int counter = 2;
    while (rest >= absDivisor) {
      counter = 1;
      while (long(absDivisor<<counter) < rest) {
	++counter;
      }
      rest -= absDivisor << (counter-1);
      result += (1 << (counter-1));
    }
    if ((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0)) return result;
    return -result;
  }
};

int main()
{
  Solution a;
  int dividend = 2147483647;
  int divisor = 1;
  // int divisor = 2;
  // int divisor = 3;
  // int dividend = 1004958205;
  // int divisor = -2137325331;

  // for (int i=0; i<1000000; ++i) {
  //   a.divide(dividend, divisor);
  // }
  // a.divide(dividend, divisor);

  std::cout << dividend << "/" << divisor << " = " << a.divide(dividend, divisor) << std::endl;
}
