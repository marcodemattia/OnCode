#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * Use a sliding window that covers two strings and find the longest substring of the two.
 * Move the window forward by one and repeat.
 */

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int maxLength = -1;
    int strsSize = strs.size();
    if ( strsSize == 0 ) return "";
    if ( strsSize == 1 ) return strs[0];
    for (int i=0; i<strsSize-1; ++i) {
      int length = std::min(strs[i].size(), strs[i+1].size());
      if (maxLength != -1) length = std::min(maxLength, length);
      int subStrLength = 0;
      for (int j=0; j<length; ++j) {
        if (strs[i][j] == strs[i+1][j]) ++subStrLength;
        else break;
      }
      maxLength = subStrLength;
    }
    return strs[0].substr(0, maxLength);
  }
};

int main()
{
  Solution a;
  
  vector<string> strs;
  strs.push_back("ABCDEFGH");
  strs.push_back("ABCDEKJRT");
  strs.push_back("ABCDU*%GFT#");
  // strs.push_back("1");

  std::cout << a.longestCommonPrefix(strs) << std::endl;

  return 0;
}
