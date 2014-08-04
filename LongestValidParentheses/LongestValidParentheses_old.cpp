#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if (s.size() < 2) return 0;
    int length = 0;
    int tempLength = 0;
    int counter = 0;
    for (char p : s) {
      if (p == '(') {
        ++counter;
        ++tempLength;
      }
      else {
        --counter;
        ++tempLength;
        if (counter < 0) {
          counter = 0;
          length = std::max(length, tempLength-1);
          tempLength = 0;
        }
      }
    }
    int tempTempLength = tempLength - counter;
    // To compute the correct length of the last sequence
    // in case it is not closed.
    if (tempLength > 1 && counter > 0) {
      counter = 0;
      tempLength = 0;
      for ( int i = s.size()-1; i>=0; --i) {
        if (s[i] == ')') {
          ++counter;
          ++tempLength;
        }
        else {
          --counter;
          ++tempLength;
          if (counter < 0) {
            counter = 0;
            // Only count the length of a sequence, neglect single
            // parantheses. If we are here it is because there was
            // an unbroken sequence until the end.
            if (tempLength > 1) {
              return std::max(length, tempLength-1);
            }
            else {
              tempLength = 0;
            }
          }
        }
      }
    }
    if (counter > 0) {
      tempLength = tempLength - counter;
      if (tempTempLength != 0) tempLength = std::min(tempTempLength, tempLength);
    }
    return std::max(length, tempLength);
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

  std::cout << "length = " << length << std::endl;
  
  return 0;
}