#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unsigned int last = s.length()-1;
    int result = 0;
    unsigned int i=last;
    while (i>0) {
      // std::cout << "s["<<i<<"] = " << s[i] << ", value = " << literalToNum[s[i]] <<std::endl;
      result += literalToNum[s[i]];
      unsigned int j=i-1;
      // std::cout << "literalToNum[s["<<i<<"]] > literalToNum[s["<<j<<"]] = " << literalToNum[s[i]] <<">"<< literalToNum[s[j]] << ", evaluates to " << (literalToNum[s[i]] > literalToNum[s[j]]) << std::endl;
      // Subtract any smaller literal before the current one
      while (literalToNum[s[i]] > literalToNum[s[j]]) {
	// std::cout << "in the while" << std::endl;
	result -= literalToNum[s[j]];
	if (j==0) return result;
	--j;
      }
      // Restart from the first non-used literal
      i = j;
    }
    result += literalToNum[s[0]];
    return result;
  }

  unordered_map<char, int> literalToNum = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
};

int main()
{
  Solution a;
  std::cout << "MMXIV = " << a.romanToInt("MMXIV") << std::endl;
  std::cout << "MCMLIV = " << a.romanToInt("MCMLIV") << std::endl;
  std::cout << "MCMXC = " << a.romanToInt("MCMXC") << std::endl;
  return 0;
}
