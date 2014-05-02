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

    wordLength_ = start.size();

    vector<vector<string> > sol;
    sol.push_back(vector<string>());

    std::vector<Node *> rootNode;
    rootNode.push_back(new Node(start));

    Node * endNode = findNext(rootNode, dict, end);

    if( endNode == 0 ) {
      // std::cout << "error" << std::endl;
      return sol;
    }

    // Navigate back and build the solution
    fillSol(sol, endNode);
    for( vector<vector<string> >::iterator it = sol.begin(); it != sol.end(); ++it ) {
      it->push_back(end);
    }

    return sol;
  }

  void fillSol(vector<vector<string> > & sol, Node * endNode)
  {
    // std::cout << "size = " << endNode->prev.size() << std::endl;
    if( endNode->prev.size() == 0 ) return;

    vector<string> previous(sol.back());

    bool first = true;
    for( vector<Node *>::iterator it = endNode->prev.begin(); it != endNode->prev.end(); ++it ) {
      if( !first ) sol.push_back(previous);
      else first = false;
      // std::cout << "it = " << *it << std::endl;
      fillSol(sol, *it);
      sol.back().push_back((*it)->word);
    }
  }

  Node * findNext(const std::vector<Node *> & layer, unordered_set<string> & dict, const string & end)
  {
    // Check if it reaches the last node
    Node * endNode = 0;
    for( std::vector<Node *>::const_iterator mainNode = layer.begin(); mainNode != layer.end(); ++mainNode ) {
      // Before checking the dict, check if the last word is a match
      if( countMatchedLetters((*mainNode)->word, end) == (wordLength_-1) ) {
        // Found a match. check all the other words and fill the result vectors.
        if( endNode == 0 ) endNode = new Node(end);
        endNode->prev.push_back(*mainNode);
      }
    }
    if( endNode != 0 ) {
      // std::cout << "endNode found: " << endNode->word << std::endl;
      // std::cout << "endNode size: " << endNode->prev.size() << std::endl;
      return endNode;
    }

    // Not the last node, continue to the next layer

    std::vector<Node * > nextLayer;
    // Loop on all the words in the dictionary
    unordered_set<string>::const_iterator it = dict.begin();
    for( ; it != dict.end(); ) {
      // std::cout << *it << std::endl;

      Node * node = 0;

      // Loop on the nodes in the current layer
      for( std::vector<Node *>::const_iterator mainNode = layer.begin(); mainNode != layer.end(); ++mainNode ) {

        // If N-1 matches are found
        if( countMatchedLetters((*mainNode)->word, *it) == (wordLength_-1) ) {
          // std::cout << *it << std::endl;
          if( node == 0 ) node = new Node(*it);
          node->prev.push_back(*mainNode);
        }
      }

      if( node != 0 ) {
        // The word is used, remove it from the dict
        it = dict.erase(it);
        nextLayer.push_back(node);
      }
      else ++it;
    }

    if( nextLayer.size() == 0 ) return endNode;
    return findNext(nextLayer, dict, end);
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
