#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

/*
  This could be done by recursively dividing by 10 and
  saving the results in a vector that is inverted in the end.
  However, it is much simpler to use a string.
*/

class Solution {
public:
  int reverse(int x) {

    std::string s(std::to_string(x));
    if( x < 0 ) s = std::to_string(-x);
    std::reverse(s.begin(), s.end());
    if( x < 0 ) s = "-"+s;
    // std::cout << s << std::endl;
    int num;
    std::istringstream(s) >> num;
    return num;
  }
};

int main()
{
  int x = -123;
  Solution a;
  int b = a.reverse(x);

  std::cout << "input x = " << x << " reversed = " << b << std::endl;
}
