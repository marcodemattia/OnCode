#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> sol;
    
    // Generate all combinations of the strings in L and search for them in the string s.
    std::sort(L.begin(), L.end());
    do {
      string sub;
      for (auto s : L) {
        sub += s;
      }
      size_t pos = S.find(sub, 0);
      while (pos != string::npos) {
        sol.push_back(pos);
        pos = S.find(sub, pos+1);
      }
    } while (std::next_permutation(L.begin(), L.end()));

    std::sort(sol.begin(), sol.end());
    return sol;
  }
};

int main()
{

  string S("barfoothefoobarman");
  vector<string> L({"foo", "bar"});

  Solution a;
  vector<int> sol(a.findSubstring(S, L));
  
  for (auto i : sol) {
    std::cout << i << ", " << std::endl;
  }
  return 0;
}