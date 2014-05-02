#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Node
{
public:
  Node(string inWord)
    : word(inWord)
  {}

  string word;
  std::vector<Node *> prev;
};

class Solution {
public:
  vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {

    wordLength_ = start.size()-1;
    layer_ = 0;

    vector<vector<string> > sol;
    vector<string> vStart;
    vStart.push_back(start);
    sol.push_back(vStart);

    fillSol(dict, sol, end);

    return sol;
  }

  void fillSol(unordered_set<string> & dict, vector<vector<string> > & sol, const string & end)
  {
    // std::cout << "length = " << sol.size() << std::endl;
    // std::cout << "layer = " << layer_ << std::endl;

    int length = sol.size();
    // if( length > 0 ) layer = sol[0].size();

    int lastFound = false;
    for( vector<vector<string> >::iterator v = sol.begin(); v != sol.end(); ++v ) {
      bool matched = (countMatchedLetters(v->back(), end) == wordLength_);
      if( matched ) {
        lastFound = true;
        v->push_back(end);
      }
    }
    if( lastFound ) {
      for( vector<vector<string> >::iterator v = sol.begin(); v != sol.end(); ) {
        if( v->back() != end ) v = sol.erase(v);
        else ++v;
      }
      return;
    }

    bool noMatches = true;
    for( unordered_set<string>::const_iterator dictWord = dict.begin(); dictWord != dict.end(); ) {
      if( checkVector(sol, *dictWord, length) ) {
        noMatches = false;
        dictWord = dict.erase(dictWord);
      }
      else ++dictWord;
    }
    if( noMatches ) {
      sol.clear();
      return;
    }
    ++layer_;
    return fillSol(dict, sol, end);
  }

  bool checkVector(vector<vector<string> > & sol, const string & dictWord, const int length)
  {
    bool found = false;
    int firstMatch = -1;
    // for( vector<vector<string> >::const_iterator layer = sol.begin(); layer != sol.end(); ++layer ) {
    for( int i = 0; i < length; ++i ) {
      string word(sol.at(i).at(layer_));
      // std::cout << "checking " << dictWord << " against " << word << std::endl;
      if( countMatchedLetters(word, dictWord) == wordLength_ ) {
        found = true;
        if( firstMatch == -1 ) firstMatch = i;
        if( sol.at(i).size() == layer_+1 ) {
          // if( !found )  {
          // std::cout << "appending: " << dictWord << std::endl;
          sol.at(i).push_back(dictWord);
        }
        else{
          // std::cout << "appending new vector: " << dictWord << std::endl;
          sol.push_back(sol.at(i));
          sol.back().pop_back();
          sol.back().push_back(dictWord);
          // sol.back().back() = dictWord;
        }
      }
    }
    // // Wait until the end to avoid changing "word"
    // if( firstMatch != -1 ) {
    //   std::cout << "appending: " << dictWord << std::endl;
    //   sol.at(firstMatch).push_back(dictWord);
    // }

    // for( int i = 0; i < length; ++i ) {
    //   std::cout << "sol.at("<<i<<").back() = " << sol.at(i).back() << std::endl;
    // }
    // for( int i = 0; i < length; ++i ) {
    //   for( int j=0; j<sol.at(i).size(); ++j ) {
    //     std::cout << "sol.at("<<i<<").at("<<j<<") = " << sol.at(i).at(j) << std::endl;
    //   }
    // }
    return found;
  }

  int countMatchedLetters(const string & w1, const string & w2) const
  {
    int matches = 0;
    string::const_iterator s = w1.begin();
    string::const_iterator c = w2.begin();
    for( ; s != w1.end(); ++s, ++c ) {
      if( *s == *c ) {
        ++matches;
      }
    }
    return matches;
  }

private:
  int wordLength_;
  int layer_;
};

int main()
{
  unordered_set<string> dict;
  // dict.insert("hot");
  // dict.insert("dot");
  // dict.insert("dog");
  // dict.insert("lot");
  // dict.insert("log");

  // "leet", "code",

  dict.insert("lest");
  dict.insert("leet");
  dict.insert("lose");
  dict.insert("code");
  dict.insert("lode");
  dict.insert("robe");
  dict.insert("lost");

  Solution a;
  vector<vector<string> > sol(a.findLadders("leet", "code", dict));
  // vector<vector<string> > sol(a.findLadders("hit", "cog", dict));
  // vector<vector<string> > sol(a.findLadders("hot", "dog", dict));
  for( vector<vector<string> >::const_iterator it1 = sol.begin(); it1 != sol.end(); ++it1 ) {
    for( vector<string>::const_iterator it2 = it1->begin(); it2 != it1->end(); ++it2 ) {
      std::cout << *it2 << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
