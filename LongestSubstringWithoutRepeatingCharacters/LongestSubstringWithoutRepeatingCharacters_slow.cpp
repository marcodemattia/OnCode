#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int counter = 0;
    int maxCount = 0;

    for (int pos=0; pos<s.length(); ++pos) {
      char c = s[pos];
      if (letters.count(c) == 0) {
	++counter;
	letters[c] = pos;
      }
      else {
	if (counter > maxCount) maxCount = counter;
	counter = 0;
	pos = letters[c];
	letters.clear();
      }
    }
    if (counter > maxCount) return counter;
    return maxCount;
  }

  std::unordered_map<char, int> letters;
};

int main()
{
  Solution a;
  // string s("abcabcbb");
  string s("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac");
  // string s("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
  // string s("");
  std::cout << "length = " << a.lengthOfLongestSubstring(s) << std::endl;
}
