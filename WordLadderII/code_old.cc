#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
public:
  vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {

    wordLength_ = start.size()-1;
    layer_ = 0;
    end_ = end;
    start_ = start;

    vector<string> vStart;
    vStart.push_back(start);
    sol_.push_back(vStart);

    // std::cout << "starting prefiltering" << std::endl;

    prefilter(start, dict);

    // std::cout << "filling solution" << std::endl;

    fillSol(dict);

    return sol_;
  }

  void prefilter(string & start, unordered_set<string> &dict)
  {
    for( unordered_set<string>::const_iterator dictWord = dict.begin(); dictWord != dict.end(); ++dictWord ) {
      int matches = countMatchedLetters(start, *dictWord);
      if(m_.count(matches) == 0 ) {
        vector<Word> v;
        m_[matches] = v;
      }
      m_[matches].push_back(Word(&*dictWord));
    }
  }

  void fillSol(unordered_set<string> & dict)
  {
    // std::cout << "length = " << sol_.size() << std::endl;
    // std::cout << "layer = " << layer_ << std::endl;

    int length = sol_.size();

    checkVector(length);

    if( last_ ) return;

    if( mt_.size() == 0 ) {
      sol_.clear();
      return;
    }
    ++layer_;

    mt_.clear();
    
    // Cleaning
    for( vector<vector<string> >::iterator it = sol_.begin(); it != sol_.end(); ) {
      // std::cout << "layer = " << layer_+1 << ", size = " << it->size() << std::endl;
      if( it->size() < layer_+1 ) it = sol_.erase(it);
      else ++it;
    }

    return fillSol(dict);
  }

  void checkVector(const int length)
  {
    // Loop on the vectors
    last_ = false;
    for( int i = 0; i < length; ++i ) {
      string word(sol_.at(i).at(layer_));
      // Find the category
      int matches = countMatchedLetters(start_, word);

      // std::cout << "word = " << word << std::endl;
      // std::cout << "category = " << matches << std::endl;
      // std::cout << "wl = " << wordLength_ << std::endl;

      int upper = (matches >= wordLength_-1) ? -1 : matches + 1;
      int lower = (matches  >= 1) ? (matches - 1) : 0;

      if( upper != -1 ) {
        vector<Word>::iterator w = m_[upper].begin();
        for( ; w != m_[upper].end(); ++w ) {
          if( !w->active ) continue;
          // std::cout << "checking " << word << " against upper " << *(w->word) << std::endl;
          if( countMatchedLetters(word, *(w->word)) == wordLength_ ) {
            mt_.push_back(&*w);
            fillSolNow(i, *(w->word));
          }
        }
      }
      if( upper != lower ) {
        vector<Word>::iterator w = m_[lower].begin();
        for( ; w != m_[lower].end(); ++w ) {
          if( !w->active ) continue;
          // std::cout << "checking " << word << " against lower " << *(w->word) << std::endl;
          if( countMatchedLetters(word, *(w->word)) == wordLength_ ) {
            mt_.push_back(&*w);
            fillSolNow(i, *(w->word));
          }
        }
      }
    }
    // Cleaning of the dict
    for( vector<Word *>::iterator it = mt_.begin(); it != mt_.end(); ++it ) {
      (*it)->active = false;
    }
  }

  void fillSolNow(int i, const string & dictWord)
  {
    if( sol_.at(i).size() == layer_+1 ) {
      sol_.at(i).push_back(dictWord);
      if( countMatchedLetters(dictWord, end_) == wordLength_ ) {
        sol_.at(i).push_back(end_);
        last_ = true;
      }
    }
    else {
      sol_.push_back(sol_.at(i));
      sol_.back().pop_back();
      sol_.back().push_back(dictWord);
      if( countMatchedLetters(dictWord, end_) == wordLength_ ) {
        sol_.back().push_back(end_);
        last_ = true;
      }
    }
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
  struct Word {
    Word(const string * dictWord): active(true), word(dictWord) {}
    bool active;
    const string * word;
  };
  int wordLength_;
  int layer_;
  vector<vector<string> > sol_;
  string end_;
  string start_;
  map<int, vector<Word> > m_;
  vector<Word*> mt_;
  bool last_;
};
