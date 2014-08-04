#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int length = 0;
    if (s.size() < 2) return 0;
    int tempLength = 0;
    int tempTempLength = 0;
    int counter = 0;
    for (char p : s) {
      if (p == '(') {
        ++counter;
        ++tempLength;
      }
      else {
        --counter;
        ++tempLength;
        if (counter == 0) {
          tempTempLength += tempLength;
          // std::cout << tempTempLength << std::endl;
          length = std::max(length, tempTempLength);
          tempLength = 0;
        }
        else if (counter < 0) {
          counter = 0;
          length = std::max(length, tempTempLength);
          tempTempLength = 0;
          tempLength = 0;
        }
      }
    }
    if (counter == 0) return std::max(length, tempTempLength);

    counter = 0;
    tempTempLength = 0;
    tempLength = 0;
    for (int i=s.size()-1; i>=0; --i) {
      if (s[i] == ')') {
        ++counter;
        ++tempLength;
      }
      else {
        --counter;
        ++tempLength;
        if (counter == 0) {
          tempTempLength += tempLength;
          length = std::max(length, tempTempLength);
          // std::cout << tempTempLength << std::endl;
          tempLength = 0;
        }
        else if (counter < 0) {
          counter = 0;
          // length = std::max(length, tempTempLength);
          return std::max(length, tempTempLength);
          // tempTempLength = 0;
          // tempLength = 0;
        }
      }
    }
    return length;
  }
};

int main()
{

  Solution a;
  // int length = a.longestValidParentheses("((())))))");
  // int length = a.longestValidParentheses(")()())");
  // int length = a.longestValidParentheses(")(())");
  // int length = a.longestValidParentheses(")(((())");
  // int length = a.longestValidParentheses("()(()");
  // int length = a.longestValidParentheses("()");
  // int length = a.longestValidParentheses(")(((((()())()()))()(()))(");
  // int length = a.longestValidParentheses(")(");
  // int length = a.longestValidParentheses(")()(((())))(");
  // int length = a.longestValidParentheses("(()))())(");
  int length = a.longestValidParentheses("(())()(()((");
  // int length = a.longestValidParentheses("(()");

  std::cout << "length = " << length << std::endl;
  
  return 0;
}