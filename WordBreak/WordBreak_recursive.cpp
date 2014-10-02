#include <iostream>
#include <string>
#include <unordered_set>
#include <limits>
#include <algorithm>

using namespace std;

/**
 * The problem asks only to return true or false. However, it is still necessary to test all
 * possible combinations until we find one that satisfies the condition.
 * The input dictionary is already provided in the form of a hash-map.
 * We first loop over the dictionary to find the minimum and maximum length of its words.
 * We then loop over the string and we sequentiall take substrings starting from the maximum
 * dictionary word length to the minimum dictionary word length. This is also limited by the
 * remaining string length. If we find a match we move forward by that amount and iterate.
 * As soon as a match is not found we return false. If the remaining string length is less than
 * the minimum word length we return false.
 */

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    sLength_ = s.length();
    minLength_ = std::numeric_limits<int>::max();
    maxLength_ = 0;
    for (auto word : dict) {
      if (word.length() < minLength_) minLength_ = word.length();
      if (word.length() > maxLength_) maxLength_ = word.length();
    }
    return checkWord(0, s, dict);
  }

  bool checkWord(int position, const string & s, const unordered_set<string> & dict)
  {
    int remainingStringLength = sLength_ - position;
    if (remainingStringLength == 0) return true;
    if (remainingStringLength < minLength_) return false;
    for (int length=min(remainingStringLength, maxLength_); length>=minLength_; --length) {
      if (dict.find(s.substr(position, length)) != dict.end()) {
	if (checkWord(position+length, s, dict)) return true;
      }
    }
    return false;
  }

  int sLength_;
  int minLength_;
  int maxLength_;
};

int main()
{
  string s("leetcode");
  unordered_set<string> dict;
  dict.insert("leet");
  dict.insert("code");

  Solution a;

  if (a.wordBreak(s, dict)) std::cout << "true" << std::endl;
  else std::cout << "false" << std::endl;

  return 0;
}
