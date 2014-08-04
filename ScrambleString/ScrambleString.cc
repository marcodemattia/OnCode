#include <iostream>
#include <algorithm>

/**
 * This one took me a while, mainly because at first the question itself was not clear.
 * The explanation of the problem is tricky and it seems other people asked about more examples.
 * The solution itself is not too complicated and it is essentially a brute force approach.
 * We check for all possible splits, if they do not match we check for the splits of the reversed string.
 * This is done recursively. Reversed strings are checked because the inversions of the children
 * of a node can cause a reverse at any point.
 */

using namespace std;

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if( s1.size() == 1 ) {
      if( s2.size() == 1 && s1 == s2 ) return true;
      return false;
    }
    return partition(s1, s2);
  }

  bool partition(const string & s1, const string & s2)
  {
    if( s1.size() == 0 ) return true;
    else if( s1.size() == 1 ) {
      if( s1 == s2 ) return true;
      return false;
    }

    string c1(s1);
    string c2(s2);

    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    if( c1 != c2 ) return false;
    if( s1.size() == 2 ) return true;

    // partition the two strings. We need to try both ways.
    // int subStringSize = int(s1.size()/2);
    int stringSize = s1.size();
    for( int i=1; i<stringSize; ++i ) {
      if( partition(s1.substr(0, i), s2.substr(0, i)) &&
	  partition(s1.substr(i), s2.substr(i)) ) {
	return true;
      }
      else {
	string ss2(s2);
	reverse(ss2.begin(), ss2.end());
	if( partition(s1.substr(0, i), ss2.substr(0, i)) &&
	    partition(s1.substr(i), ss2.substr(i)) ) return true;
      }
    }
    return false;
  }
};

int main()
{
  std::cout << "" << std::endl;

  Solution a;
  // if( a.isScramble("abcde", "abced") ) std::cout << "is scramble" << std::endl;
  // if( a.isScramble("abcde", "acbed") ) std::cout << "is scramble" << std::endl;
  // if( a.isScramble("a", "b") ) std::cout << "is scramble" << std::endl;
  // if( a.isScramble("abab", "aabb") ) std::cout << "is scramble" << std::endl;
  if( a.isScramble("vfldiodffghyq", "vdgyhfqfdliof") ) std::cout << "is scramble" << std::endl;

  return 0;
}
