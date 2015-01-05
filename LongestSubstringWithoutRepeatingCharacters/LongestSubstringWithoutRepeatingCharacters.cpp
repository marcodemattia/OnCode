#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    letters.clear();
    int maxCount = 0;
    int subStringStart = 0;
    for (int i=0; i<s.length(); ++i) {
      char c = s[i];
      if (letters.count(c) != 0 && letters[c] >= subStringStart) {
	maxCount = std::max(maxCount, i - subStringStart);
	subStringStart = letters[c]+1;
      }
      letters[c] = i;
    }
    return std::max(maxCount, int(s.length())-subStringStart);
  }

  std::unordered_map<char, int> letters;
};

int main()
{
  Solution a;
  // string s("abcabcbb");
  // string s("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac");
  // string s("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
  string s("qopubjguxhxdipfzwswybgfylqvjzhar");
  // string s("");
  std::cout << "length = " << a.lengthOfLongestSubstring(s) << std::endl;
}
