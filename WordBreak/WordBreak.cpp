#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

/**
 * The problem asks only to return true or false. However, it is still necessary to test all
 * possible combinations until we find one that satisfies the condition.
 * The problem shows substructure and memoization can help. We use a DP approach.
 */

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    int sLength = s.length();
    if (sLength == 0) return true;
    if (sLength == 1) return (dict.find(s) != dict.end());
    if (dict.find(s) != dict.end()) return true;

    if (dict.find(s.substr(0, 1)) != dict.end()) subSol_[0] = true;

    subSol_.clear();
    for (int l=1; l<=sLength; ++l) {
      // std::cout << "checking l = " << l << std::endl;
      if (dict.find(s.substr(0, l)) != dict.end()) {
	subSol_[l] = true;
      }
      for (int j=1; j<l; ++j) {
	// std::cout << "substr("<<j<<", "<<l-j<<") = " << s.substr(j, l-j) << std::endl;
	// if (dict.find(s.substr(j, i-j+1)) != dict.end()) std::cout << "found" << std::endl;
	if (dict.find(s.substr(j, l-j)) != dict.end() && subSol_[j] == true) {
	  // std::cout << "found" << std::endl;
	  subSol_[l] = true;
	  break;
	}
      }
    }
    return (subSol_.find(sLength) != subSol_.end());
  }
  // Is the string from start to position (the given int)
  // breakable with the input dictionary?
  unordered_map<int, bool> subSol_;
};

int main()
{
  unordered_set<string> dict;

  // string s("leetcode");
  // dict.insert("leet");
  // dict.insert("code");

  string s("aaaaaaa");
  dict.insert("aaaa");
  dict.insert("aa");

  // string s("ab");
  // dict.insert("a");
  // dict.insert("b");

  Solution a;

  if (a.wordBreak(s, dict)) std::cout << "true" << std::endl;
  else std::cout << "false" << std::endl;

  return 0;
}
