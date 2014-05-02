// #include "code.cc"
// #include "code_old.cc"
#include "code_linkedList_opt.cc"

using namespace std;

int main()
{
  unordered_set<string> dict;

  dict.insert("ted");
  dict.insert("tex");
  dict.insert("red");
  dict.insert("tax");
  dict.insert("tad");
  dict.insert("den");
  dict.insert("rex");
  dict.insert("pee");

  Solution a;
  vector<vector<string> > sol(a.findLadders("red", "tax", dict));
  for( vector<vector<string> >::const_iterator it1 = sol.begin(); it1 != sol.end(); ++it1 ) {
    for( vector<string>::const_iterator it2 = it1->begin(); it2 != it1->end(); ++it2 ) {
      std::cout << *it2 << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}

