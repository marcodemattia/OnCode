#include <iostream>
#include <limits>

    class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        bool signal = false;
        bool overflow = false;
        if(dividend < 0) {
            signal = !signal;
            if(dividend == INT_MIN) { overflow = true; dividend++; }
            dividend *= -1;
        } 
        if(divisor < 0) {
            signal = !signal;
            if(divisor == INT_MIN) {
                if(overflow) return 1;
                else return 0;
            }
            divisor *= -1;
        }
        int result = 0;
        while(dividend >= divisor) {
            int x(divisor);
            int r(1);
            while(dividend-x >= x) {
                x += x;
                r += r;
            }
            dividend -= x;
            result += r;
        }
        if(overflow && dividend +1 == divisor) result++;
        return signal ? (-result) : result;
    }
};

int main()
{
  Solution a;
  int dividend = 2147483647;
  int divisor = 1;
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

  for (int i=0; i<1000000; ++i) {
    a.divide(dividend, divisor);
  }

  std::cout << dividend << "/" << divisor << " = " << a.divide(dividend, divisor) << std::endl;
}
