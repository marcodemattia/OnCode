#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Double loop, from the start and from the end. For each letter in the first loop go over the letters
 * from the end and if a match is found keep going to see if it matches the rest. Memoize in a hashmap
 * the indeces of the letters such that if a letter has already been analyzed we can reduce the number
 * of checks. We also memoize the lengths of the substrings already checked.
 */

class Solution {
public:
  string longestPalindrome(string s) {

    int length = s.length();
    letterPositions.clear();
    subPalyndromeLength.clear();
    if (length <= 1) return s;
    maxLengthPalyndrome_ = 1;
    start_ = 0;
    for (int i=0; i<s.length(); ++i) {
      char letter = s[i];
      // std::cout << "letter = " << letter << std::endl;
      if (letterPositions.count(letter) == 0) {
	letterPositions[letter] = vector<int>();
	for (int j=length-1; j>i; --j) {
	  // if (j-i < maxLengthPalyndrome_) break;
	  if (j-i < maxLengthPalyndrome_) break;
	  // std::cout << "i = " << i << ", j = " << j << std::endl;
	  if (letter == s[j]) {
	    // std::cout << "second letter = " << "s["<<j<<"] = " << s[j] << std::endl;
	    letterPositions[letter].push_back(j);
	    lengthPalyndrome(s, i, j);
	  }
	}
      }
      else {
	for (const int j : letterPositions[letter]) {
	  if (j<=i || j-i < maxLengthPalyndrome_) break;
	  // std::cout << "i = " << i << ", j = " << j << std::endl;
	  lengthPalyndrome(s, i, j);
	}
      }
    }
    return s.substr(start_, maxLengthPalyndrome_);
  }

  void lengthPalyndrome(const string & s, int i, int j)
  {
    int tempStart = i;
    int tempEnd = j;
    int length = 0;
    // std::cout << "s["<<i<<"] = " << s[i] << ", s["<<j<<"] = " << s[j] << ", length = " << length << std::endl;
    // string sub(s.substr(i, j-i));
    // if( equal(sub.begin(), sub.begin() + sub.size()/2, sub.rbegin()) ) length = j-i;
    // if (s.substr(i, j-i) == s.substr(i, j-i)) length = j-i;
    while (i<j) {
      // Using the assumption that the length of s cannot exceed 1000 (10k is bigger, to be safe).
      if (subPalyndromeLength.count(i+10000*j) != 0) {
    	length = subPalyndromeLength[i+10000*j];
    	break;
      }
      else if (s[i++] != s[j--]) {
    	length = 0;
    	subPalyndromeLength[i+10000*j] = 0;
    	break;
      }
      length += 2;
    }
    if (i==j) ++length;
    subPalyndromeLength[i+tempEnd*10000] = length;
    if (length > maxLengthPalyndrome_) {
      maxLengthPalyndrome_ = length;
      start_ = tempStart;
    }
  }


  int maxLengthPalyndrome_;
  int start_;
  std::unordered_map<char, vector<int> > letterPositions;
  std::unordered_map<int, int> subPalyndromeLength;
};

int main()
{
  Solution a;
  // string s("ababccbaaa");
  string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

  std::cout << a.longestPalindrome(s) << std::endl;
}
