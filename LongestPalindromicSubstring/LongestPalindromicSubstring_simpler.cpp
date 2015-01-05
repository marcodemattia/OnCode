#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Loop on the string and for each character expand around it in both symmetric and asymmetric ways.
 */

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.length() <= 1) return s;
    int maxStart = 0;
    int maxLength = 1;
    int tempEnd = 0;
    int length = s.length();
    for (int i=0; i<length-1; ++i) {
      int oddLength = 1;
      int evenLength = 0;
      int j = 1;

      // Even-length palindrome
      while (i-j >= 0 && i+j < length) {
	if (s[i-j]==s[i+j]) oddLength += 2;
	else break;
	++j;
      }
      if (oddLength > maxLength) {
	maxStart = i-(j-1);
	maxLength = oddLength;
      }

      // Odd-length palindrome
      j = 0;
      while (i-j >= 0 && i+j+1 < length) {
	if (s[i-j]==s[i+j+1]) evenLength += 2;
	else break;
	++j;
      }
      if (evenLength > maxLength) {
	maxStart = i-(j-1);
	maxLength = evenLength;
      }
    }
    // We never check n-1 and n because of the way the main loop is built
    if (maxLength < 2 && s[length-1] == s[length-2]) return s.substr(length-2, 2);
    return s.substr(maxStart, maxLength);
  }
};

int main()
{
  Solution a;
  // string s("ababccbaaa");
  string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  // string s("abb");
  // string s("aaaa");

  std::cout << a.longestPalindrome(s) << std::endl;
}
