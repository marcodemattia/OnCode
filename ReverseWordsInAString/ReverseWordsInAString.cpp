#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
  // This is the better one using the istream_iterator.
  // LeetCode does not know about istream_iterator (note
  // that they ARE std).
//  void reverseWords(string &s) {
//    istringstream iss(s);
//    vector<string> tokens{istream_iterator<string>{iss},
//      istream_iterator<string>{}};
//    std::reverse(tokens.begin(), tokens.end());
//    s.clear();
//    for (auto word : tokens) {
//      s += word + ' ';
//    }
//    s = s.substr(0, s.length()-1);
//  }

  void reverseWords(string &s) {
    istringstream iss(s);
    vector<string> tokens;
    string token;
    while (iss >> token) {
      tokens.push_back(token);
    }
    std::reverse(tokens.begin(), tokens.end());
    s.clear();
    for (auto word : tokens) {
      s += word + ' ';
    }
    s = s.substr(0, s.length()-1);
  }
};

int main()
{
  
  Solution a;
  // string s("the sky is blue");
  string s("a");
  a.reverseWords(s);

  std::cout << "reversed:"<< s << "." << std::endl;
}