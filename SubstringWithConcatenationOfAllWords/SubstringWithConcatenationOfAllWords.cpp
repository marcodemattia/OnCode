#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

/**
 * Create a hashed map from the list of words with counters of how many times a word appears.
 * Go through the long string and find the first matching word. Move to the next word (all words
 * have the same size) and check if it matches. If all the words in the substring of length
 * (number of words)*(word length) are matched save the starting index of this substring.
 * To cope with word repetitions in the list of words, store counters in the hashed map
 * and decrease them when a matching word is found. Only words with counters > 0 are
 * considered for the matched.
 */

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> sol;
    if (L.size() == 0 || (L.size()*L[0].size() > S.size())) return sol;

    int wordSize = L[0].size();
    int stringLength = L.size()*L[0].size()-wordSize;
    
    // Prepare the hashed map
    std::unordered_map<std::string, int> map;
    for (auto word : L) {
      auto it = map.find(word);
      if (it!=map.end()) map[word] += 1;
      else map.insert(std::make_pair(word, 1));
    }
    
    // Plus one because if the length is the same we will enter the loop and
    // check if it matches.
    int tot = S.size() - L.size()*L[0].size() + 1;
    bool found = false;
    
    for (int i=0; i<tot; ++i) {
      string sub(S.substr(i, wordSize));
      if(map.find(sub) != map.end()) {
        found = true;
        int position = i+wordSize;
        auto mapCopy(map);
        mapCopy[sub] -= 1;
        while (position <= i+stringLength) {
          sub = S.substr(position, wordSize);
          auto it = map.find(sub);
          if (it != map.end() && mapCopy[sub] > 0) {
            mapCopy[sub] -= 1;
          }
          else {
            found = false;
            break;
          }
          position += wordSize;
        }
        if (found) sol.push_back(i);
      }
    }
    return sol;
  }
};

int main()
{

  // string S("barfoothefoobarman");
  // vector<string> L({"foo", "bar"});
  // string S("mississippi");
  // vector<string> L({"mississippis"});
  // string S("a");
  // vector<string> L({"a"});
  string S("aaa");
  vector<string> L({"a", "b"});
  
  Solution a;
  vector<int> sol(a.findSubstring(S, L));
  
  for (auto i : sol) {
    std::cout << i << ", " << std::endl;
  }
  return 0;
}