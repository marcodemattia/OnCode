#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    std::vector<int> v;
    std::vector<int>::const_reverse_iterator it = digits.rbegin();
    int extra = (*it+1)/10;
    v.push_back((*it+1)%10);
    std::cout << "*it"<<"+1 = " << (*it+1) << std::endl; 
    ++it;

    for( ; it != digits.rend(); ++it ) {
      std::cout << "extra = " << extra << " *it"<<"+1 = " << (*it+1) << std::endl; 
      if( extra > 0 ) {
	extra = (*it+1)/10;
	v.push_back((*it+1)%10);
      }
      else {
	extra = 0;
	v.push_back(*it);
      }
    }
    if( extra > 0 ) v.push_back(1);
    std::reverse(v.begin(), v.end());
    return v;
  }
};


int main()
{
  std::vector<int> digits;
  digits.push_back(0);
  // digits.push_back(2);
  // digits.push_back(3);
  // digits.push_back(4);
  for( int i=0; i<digits.size(); ++i ) std::cout << "digits["<<i<<"] = " << digits[i] << std::endl;

  Solution a;
  std::vector<int> v(a.plusOne(digits));

  for( int i=0; i<v.size(); ++i ) std::cout << "v["<<i<<"] = " << v[i] << std::endl;

  return 0;
}
