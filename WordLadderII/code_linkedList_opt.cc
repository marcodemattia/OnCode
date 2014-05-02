#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

/*
  The structure of the problem is a graph with multiple connections.
  The strategy is to first go through until the end word is reached. To avoid loops and minimize the time
  any word that is found at a given iteration is removed for the next iterations. The pattern from a given
  node to the end word is only dependent on the node and not on the previous path. Therfore, any other pattern
  that uses a given node will be longer than the first one in which the node is found.
  Each successive node is linked to the ones in the previous layer from which it is N-1 letters away.
  Once the end word node is reached the patterns are navigated back and the solution is built.

  The only tricky part is that iterating over an unordered_set is very slow. The container is designed for
  fast finding (hashed container) and not for fast iteration. It results more efficient to generate all
  possible variations of a given word and find it in the dictionary rather than looping over the dictionary
  and computing the number of matched letters.
*/


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

    wordLength_ = start.size() - 1;

    vector<vector<string> > sol;
    sol.push_back(vector<string>());

    // Check for the trivial case
    if( countMatchedLetters(start, end) == wordLength_ ) {
      sol[0].push_back(start);
      sol[0].push_back(end);
      return sol;
    }

    std::unordered_map<string, Node *> rootNode;
    rootNode.insert(std::make_pair(start, new Node(start)));

    Node * endNode = findNext(rootNode, dict, end);

    if( endNode == 0 ) {
      // std::cout << "error" << std::endl;
      sol.clear();
      return sol;
    }

    // Navigate back and build the solution
    fillSol(sol, endNode);
    for( vector<vector<string> >::iterator it = sol.begin(); it != sol.end(); ++it ) {
      std::reverse(it->begin(), it->end());
      it->push_back(end);
    }

    return sol;
  }

  void fillSol(vector<vector<string> > & sol, Node * endNode)
  {
    if( endNode->prev.size() == 0 ) return;

    std::cout << "sol.size() = " << sol.size() << std::endl;
    for( int i=0; i<sol.size(); ++i ) {
      for( int j=0; j<sol.at(i).size(); ++j ) {
        std::cout << "sol.at("<<i<<").at("<<j<<") = " << sol.at(i).at(j) << std::endl;
      }
    }
    
    vector<string> previous(sol.back());
    std::cout << "previous size = " << previous.size() << std::endl;
    for( int i=0; i<previous.size(); ++i ) {
      std::cout << "previous["<<i<<"] = " << previous.at(i) << std::endl;
    }

    std::cout << "endNode = " << endNode->word << ", size = " << endNode->prev.size() << std::endl;

    bool first = true;
    for( vector<Node *>::iterator it = endNode->prev.begin(); it != endNode->prev.end(); ++it ) {
      if( !first ) {
        std::cout << "not the first, pushing back previous" << std::endl;
        sol.push_back(previous);
      }
      else first = false;
      std::cout << "it = " << (*it)->word << std::endl;
      sol.back().push_back((*it)->word);
      fillSol(sol, *it);
    }
    // for( int i=0; i<sol.size(); ++i ) {
    //   for( int j=0; j<sol.at(i).size(); ++j ) {
    //     std::cout << "sol.at("<<i<<").at("<<j<<") = " << sol.at(i).at(j) << std::endl;
    //   }
    // }
  }

  Node * findNext(const std::unordered_map<string, Node *> & layer, unordered_set<string> & dict, const string & end)
  {
    // Check if it reaches the last node
    Node * endNode = 0;
    std::unordered_map<string, Node *>::const_iterator mainNode = layer.begin();
    for(; mainNode != layer.end(); ++mainNode ) {
      // Before checking the dict, check if the last word is a match
      if( countMatchedLetters(mainNode->second->word, end) == (wordLength_) ) {
        // Found a match. check all the other words and fill the result vectors.
        if( endNode == 0 ) endNode = new Node(end);
        endNode->prev.push_back(mainNode->second);
      }
    }
    if( endNode != 0 ) {
      // std::cout << "endNode found: " << endNode->word << std::endl;
      // std::cout << "endNode size: " << endNode->prev.size() << std::endl;
      return endNode;
    }

    // Not the last node, continue to the next layer

    std::unordered_map<std::string, Node * > nextLayer;

    // Loop on the nodes in the current layer
    mainNode = layer.begin();
    for( ; mainNode != layer.end(); ++mainNode ) {
      fillMatchingWords(nextLayer, dict, mainNode->second);
    }

    // Clean the dictionary
    std::unordered_map<string, Node *>::const_iterator nextNode = nextLayer.begin();
    for( ; nextNode != nextLayer.end(); ++nextNode ) {
      dict.erase(nextNode->second->word);
    }
    if( nextLayer.size() == 0 ) return endNode;
    return findNext(nextLayer, dict, end);
  }

  void fillMatchingWords(unordered_map<string, Node *> & nextLayer, const unordered_set<string> & dict, Node * mainNode)
  {
    // Loop over all possible combinations and see if they exist in the dictionary
    for( int i = 0; i < mainNode->word.size(); ++i ) {
      std::string wordCopy(mainNode->word);
      for( char l = 'a'; l <= 'z'; ++l ) {
        wordCopy[i] = l;
        if( dict.find(wordCopy) != dict.end() ) {
          // std::cout << "found " << wordCopy << std::endl;
          if( nextLayer.find(wordCopy) == nextLayer.end() ) {
            nextLayer.insert(std::make_pair(wordCopy, new Node(wordCopy)));
          }
          nextLayer[wordCopy]->prev.push_back(mainNode);
        }
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
  int wordLength_;

};
