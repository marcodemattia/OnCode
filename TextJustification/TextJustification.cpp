#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Go through the words in the string array and add the length to a counter.
 * For each successive word after the first add a 1 (a minimum of one space
 * for each word is needed). If the next word does not fit the remaining length
 * stop the line and compute the number of spaces to distribute. The spaces needed
 * are the length of the line L minus the sum of the length of the words. If N
 * words are in the line we consider two cases. Case 1, N == 1: we simply add spaces
 * to the end to fill the length L. Note that it assumed that the length of the
 * words are all <= L. Case 2, N > 1: the total number of spaces K will be divided
 * as S = K/(N-1) among the different words. If K%(N-1) == 0 the same number of
 * spaces are added between each word. If K%(N-1) = R != 0 we assign an extra space
 * to each word starting from the first one and we reduce R by one each time
 * until it reaches 0. After exiting the loop we handle the last line, which
 * must be always left adjusted with single spaces between the words.
 */

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    
    if (words.size() == 1 && words[0] == "") {
      return vector<string>({string(L, ' ')});
    }
    
    vector<string> text;
    length_ = 0;
    counter_ = 0;
    wordIndeces_.clear();
    for (int i=0; i<words.size(); ++i) {
      const string & word(words[i]);
      std::cout << "word = " << word << std::endl;
      if (i>0) {
        if (length_ + counter_ + word.size() > L) {
          text.push_back(fillLine(words, L));
        }
      }
      // Add the word
      length_ += word.size();
      ++counter_;
      wordIndeces_.push_back(i);
    }
    if (length_ > 0) {
      text.push_back(fillLastLine(words, L));
    }
    
    return text;
  }
  
  string fillLine(const vector<string> & words, int L)
  {
    // Build the line and reset the counters
    string line;
    if (counter_==1) {
      line = words[wordIndeces_[0]] + string(L-length_, ' ');
    }
    else {
      // Compute how many spaces to insert between each word.
      unsigned int k = L - length_;
      unsigned int r = k%(counter_-1);
      unsigned int s = k/(counter_-1);
      for (int j=0; j<wordIndeces_.size()-1; ++j) {
        line += words[wordIndeces_[j]];
        line += string(s, ' ');
        if (r>0) {
          line += ' ';
          --r;
        }
      }
      line += words[wordIndeces_.back()];
      // std::cout << "line = " << line << std::endl;
    }
    counter_ = 0;
    length_ = 0;
    wordIndeces_.clear();
    return line;
  }

  string fillLastLine(const vector<string> & words, int L)
  {
    // Build the line and reset the counters
    string line;
    if (counter_==1) {
      line = words[wordIndeces_[0]] + string(L-length_, ' ');
    }
    else {
      // Compute how many spaces to insert between each word.
      for (int j=0; j<wordIndeces_.size()-1; ++j) {
        line += words[wordIndeces_[j]];
        line += ' ';
      }
      line += words[wordIndeces_.back()];
      std::cout << "line = " << line << std::endl;
      std::cout << "L - line.size() = " << line.size() << std::endl;
      if (L - line.size() > 0) {
        line+=string(L - line.size(), ' ');
      }
    }
    counter_ = 0;
    length_ = 0;
    wordIndeces_.clear();
    return line;
  }
  
  unsigned int counter_;
  unsigned int length_;
  vector<unsigned int> wordIndeces_;
};





int main()
{
  Solution a;

  // vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  // vector<string> text(a.fullJustify(words, 16));
  
  // vector<string> words = {"What","must","be","shall","be."};
  // vector<string> text(a.fullJustify(words, 12));
  
  vector<string> words = {"Imagination","is","more","important","than","knowledge."};
  vector<string> text(a.fullJustify(words, 14));

  for (auto line : text) {
    std::cout << line << "," << std::endl;
  }
  
  return 0;
}
