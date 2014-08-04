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
    int counter = 0;
    int firstLength = 0;
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
          if (firstLength == 0) firstLength = length;
          tempLength = 0;
        }
      }
    }
    // No ambiguity, return the result.
    if (counter == 0) return std::max(length, tempLength);
    
    int lastLength = length - counter;
    
    std::cout << "counter = " << counter << std::endl;
    counter = 0;
    tempLength = 0;
    int firstLengthReverse = 0;
    for (int i = s.size()-1; i>=0; --i) {
      if (s[i] == ')') {
        ++counter;
        ++tempLength;
      }
      else {
        --counter;
        ++tempLength;
        if (counter < 0) {
          counter = 0;
          length = std::max(length, tempLength-1);
          if (firstLengthReverse == 0) firstLengthReverse = length;
          tempLength = 0;
        }
      }
    }
    if (tempLength > 0) length = std::min(firstLength, tempLength - counter);
    if (lastLength > 0) length = std::min(lastLength, firstLengthReverse);
    
    if (counter == 0) return std::max(length, tempLength);
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
  int length = a.longestValidParentheses(")()(((())))(");
  // int length = a.longestValidParentheses("(()))())(");
  // int length = a.longestValidParentheses("(())()(()((");

  std::cout << "length = " << length << std::endl;
  
  return 0;
}