#include "code.cc"

using namespace std;

int main()
{
  unordered_set<string> dict;
  dict.insert("hot");
  dict.insert("cog");
  dict.insert("dog");
  dict.insert("tot");
  dict.insert("hog");
  dict.insert("hop");
  dict.insert("pot");
  dict.insert("dot");

  Solution a;
  vector<vector<string> > sol(a.findLadders("hot", "dog", dict));
  for( vector<vector<string> >::const_iterator it1 = sol.begin(); it1 != sol.end(); ++it1 ) {
    for( vector<string>::const_iterator it2 = it1->begin(); it2 != it1->end(); ++it2 ) {
      std::cout << *it2 << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}

