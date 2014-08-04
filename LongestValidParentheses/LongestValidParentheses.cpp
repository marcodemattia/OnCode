#include <iostream>
#include <string>
#include <algorithm>

/**
 * We do a first pass and find the longest sequence. We count +1 for '(' and -1 for ')'.
 * If the last sequence ends with a positive count its length is ambiguous and we do a
 * second pass backwards to find its correct length. This second pass could probably be
 * optimized by stopping after the first non-null sequence.
 */

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
    // No need to do the second loop in this case.
    if (counter == 0) return std::max(length, tempTempLength);
    
    length = std::max(length, tempTempLength);

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
  int length = a.longestValidParentheses(")(((((()())()()))()(()))(");
  // int length = a.longestValidParentheses(")(");
  // int length = a.longestValidParentheses(")()(((())))(");
  // int length = a.longestValidParentheses("(()))())(");
  // int length = a.longestValidParentheses("(())()(()((");
  // int length = a.longestValidParentheses("(()");

  std::cout << "length = " << length << std::endl;
  
  return 0;
}