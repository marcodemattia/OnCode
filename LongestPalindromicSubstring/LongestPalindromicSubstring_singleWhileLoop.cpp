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
    int length = s.length();
    for (int i=0; i<length-1; ++i) {

      bool odd = true;
      int oddLength = 1;
      int oddStart = 0;

      bool even = true;
      int evenLength = 0;
      int evenStart = 0;

      int j = 0;
      while (i-j >= 0 && i+j+1 < length) {
	if (i+j < length) {
	  if (odd) {
	    if (s[i-j-1]==s[i+j+1]) {
	      oddStart = i-j-1;
	      oddLength += 2;
	    }
	    else odd = false;
	  }
	}
	if (even) {
	  if (s[i-j]==s[i+j+1]) {
	    evenStart = i-j;
	    evenLength += 2;
	  }
	  else even = false;
	}
	++j;
	if(!odd && !even) break;
      }

      if (oddLength > maxLength) {
	maxStart = oddStart;
	maxLength = oddLength;
      }
      if (evenLength > maxLength) {
	maxStart = evenStart;
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
  // string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  // string s("abb");
  // string s("aaaa");
  string s("ccc");

  std::cout << a.longestPalindrome(s) << std::endl;
}
