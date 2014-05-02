#include <iostream>
#include <string>
#include <sstream>

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int totalLength = 0;
    int lastLength = 0;
    int length = 0;
    int i=0;
    while( *s ) {
      // std::cout << "s["<<i<<"] = " << *s << std::endl;
      if( *s == ' ' ) {
	if( length != 0 ) {
	  lastLength = length;
	  length = 0;
	}
      }
      else ++length;
      ++totalLength;
      ++i;
      ++s;
    }
    if( totalLength == 0 ) return 0;
    else if( length == 0 && lastLength != 0 ) return lastLength;
    return length;
  }
};

int main()
{
  char s[] = " ";

  Solution a;
  std::cout << "length = " << a.lengthOfLastWord(s) << std::endl;

}
