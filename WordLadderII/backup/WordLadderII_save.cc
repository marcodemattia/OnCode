#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {

    wordLength_ = start.size()-1;
    layer_ = 0;
    end_ = end;

    vector<string> vStart;
    vStart.push_back(start);
    sol_.push_back(vStart);

    fillSol(dict);

    return sol_;
  }

  void fillSol(unordered_set<string> & dict)
  {
    // std::cout << "length = " << sol.size() << std::endl;
    // std::cout << "layer = " << layer_ << std::endl;

    int length = sol_.size();
    // if( length > 0 ) layer = sol[0].size();

    // int lastFound = false;
    // for( vector<vector<string> >::iterator v = sol_.begin(); v != sol_.end(); ++v ) {
    //   bool matched = (countMatchedLetters(v->back(), end_) == wordLength_);
    //   if( matched ) {
    //     lastFound = true;
    //     v->push_back(end_);
    //   }
    // }
    // if( lastFound ) {
    //   for( vector<vector<string> >::iterator v = sol_.begin(); v != sol_.end(); ) {
    //     if( v->back() != end_ ) v = sol_.erase(v);
    //     else ++v;
    //   }
    //   return;
    // }
    
    bool noMatches = true;
    for( unordered_set<string>::const_iterator dictWord = dict.begin(); dictWord != dict.end(); ) {
      int result = checkVector(*dictWord, length);
      if( result == 0 ) {
        for( vector<vector<string> >::iterator v = sol_.begin(); v != sol_.end(); ) {
          if( v->back() != end_ ) v = sol_.erase(v);
          else ++v;
        }
        return;
      }
      else if( result == 1 ) {
        // if( checkVector(*dictWord, length) ) {
        noMatches = false;
        dictWord = dict.erase(dictWord);
      }
      else ++dictWord;
    }
    if( noMatches ) {
      sol_.clear();
      return;
    }
    ++layer_;
    
    // Cleaning
    for( vector<vector<string> >::iterator it = sol_.begin(); it != sol_.end(); ) {
      // std::cout << "layer = " << layer_+1 << ", size = " << it->size() << std::endl;
      if( it->size() < layer_+1 ) it = sol_.erase(it);
      else ++it;
    }

    return fillSol(dict);
  }

  int checkVector(const string & dictWord, const int length)
  {
    bool last = false;
    bool found = false;
    int firstMatch = -1;
    for( int i = 0; i < length; ++i ) {
      string word(sol_.at(i).at(layer_));
      if( countMatchedLetters(word, dictWord) == wordLength_ ) {
        found = true;
        if( firstMatch == -1 ) firstMatch = i;
        if( sol_.at(i).size() == layer_+1 ) {
          sol_.at(i).push_back(dictWord);
          if( countMatchedLetters(dictWord, end_) == wordLength_ ) {
            sol_.at(i).push_back(end_);
            last = true;
          }
        }
        else {
          sol_.push_back(sol_.at(i));
          sol_.back().pop_back();
          sol_.back().push_back(dictWord);
          if( countMatchedLetters(dictWord, end_) == wordLength_ ) {
            sol_.back().push_back(end_);
            last = true;
          }
        }
      }
    }
    if( last ) return 0;
    else if( found ) return 1;
    return -1;
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
  vector<vector<string> > sol_;
  string end_;
};

int main()
{
  unordered_set<string> dict;
  dict.insert("hot");
  dict.insert("dot");
  dict.insert("dog");
  dict.insert("lot");
  dict.insert("log");

  Solution a;
  // vector<vector<string> > sol(a.findLadders("hit", "cog", dict));
  vector<vector<string> > sol(a.findLadders("hot", "dog", dict));
  for( vector<vector<string> >::const_iterator it1 = sol.begin(); it1 != sol.end(); ++it1 ) {
    for( vector<string>::const_iterator it2 = it1->begin(); it2 != it1->end(); ++it2 ) {
      std::cout << *it2 << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}
