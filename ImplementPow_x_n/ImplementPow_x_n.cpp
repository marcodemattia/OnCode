#include <iostream>

/**
 * The pow function is implemented iteratively. If the exponent is negative we take the products of 1/x.
 * We check explicitly for the x = 0, 1 and -1 cases where the result can be given without further calculations.
 * We also add a cutoff to stop computing the products when the number becomes 0.
 */

class Solution {
public:
  double pow(double x, int n) {
    double result = 1;
    if (x == 0 || x == 1) return x;
    else if( x == -1 ) {
      if (n%2 == 0) return 1;
      else return x;
    }
    double value = x;
    int num = n;
    if (n<0) {
      value = 1/x;
      num = -n;
    }
    int i = 0;
    while (i<num) {
      result *= value;
      ++i;
      if (result == 0) return result;
    }
    return result;
  }
};

int main()
{
  Solution a;
  std::cout << "pow = " << a.pow(34.00515, -3) << std::endl;
  return 0;
}