#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * This is a follow up to WordBreak and we reuse most of the solution which is based on dynamic programming
 * techniques. The difference is that in this case we need to return all possible combinations as a vector
 * of strings containing space separated words. To save space we do not store the strings for the subcombinations,
 * but only the index where the string is split. We finally build only the strings for the solution.
 */

class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    subSol_.clear();
    int sLength = s.length();
    if (sLength == 0) return vector<string>(1 ,s);
    if (sLength == 1) {
      if (dict.find(s) != dict.end()) return vector<string>(1, s);
      else return vector<string>();
    }
    if (dict.find(s.substr(0, 1)) != dict.end()) subSol_[0].push_back(1);

    for (int l=1; l<=sLength; ++l) {
      if (dict.find(s.substr(0, l)) != dict.end()) {
	subSol_[l].push_back(l);
      }
      for (int j=1; j<l; ++j) {
	if (dict.find(s.substr(j, l-j)) != dict.end() && subSol_[j].size() != 0) {
	  std::cout << "j = " << j << std::endl;
	  subSol_[l].push_back(j);
	}
      }
    }

    // Done, now build the solution
    return buildSolutions(s, sLength);
  }

  vector<string> buildSolutions(const string & s, int l)
  {
    // std::cout << "l = " << l << std::endl;
    vector<string> tempSol;
    for (auto & position : subSol_[l]) {
      // std::cout << "position = " << position << std::endl;
      if (position == l) tempSol.push_back(s.substr(0, l));
      else {
	vector<string> temp(buildSolutions(s, position));
	for (auto & ts : temp) {
	  tempSol.push_back(ts + " " + s.substr(position, l-position));
	}
      }
    }
    return tempSol;
  }

  unordered_map<int, vector<int> > subSol_;
};

int main()
{
  unordered_set<string> dict;

  // string s("leetcode");
  // dict.insert("leet");
  // dict.insert("code");

  // string s("aaaaaaa");
  // dict.insert("aaaa");
  // dict.insert("aa");

  // string s("ab");
  // dict.insert("a");
  // dict.insert("b");

  // string s("catsanddog");
  // dict.insert("cat");
  // dict.insert("cats");
  // dict.insert("and");
  // dict.insert("sand");
  // dict.insert("dog");

  string s("abcd");
  dict.insert("a");
  dict.insert("abc");
  dict.insert("b");
  dict.insert("cd");

  Solution a;

  vector<string> sol(a.wordBreak(s, dict));
  for (auto s : sol) {
    std::cout << s << std::endl;
  }

  return 0;
}
