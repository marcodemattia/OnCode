/**
 * Could use boost::dynamic_bitset, but not tested.
 * Done with bitshifts and bitwise operators.
 * The flip(x) method will flip all the bits starting from the first one.
 * After each bit flip it will call itself recursively.
 * When bit x is flipped, go to flip all the previous bits again to cover all possible combinations.
 * Only one bit at a time is flipped so the result is a gray code.
 * The variable a is a data member to ensure that each change in the recursive calls is always retained.
*/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    v.push_back(0);
    a = 0;
    flip(n);
    return v;
  }

  void flip(int n)
  {
    // std::cout << a << ", " << x << ", " << n << std::endl;
    int x = 0;
    while( x < n ) {
      a ^= 1<<x;
      v.push_back(a);
      // std::cout << "in loop: " << a << ", " << x << ", " << n << std::endl;
      flip(x);
      ++x;
    }
  }

  vector<int> v;
  int a;
};

int main()
{
  Solution a;
  vector<int> v(a.grayCode(4));

  for(const auto& it : v) {
    std::bitset<4> bt(it);
    // std::cout << it << std::endl;
    std::cout << bt.to_string() << std::endl;
  }

  return 0;
}
