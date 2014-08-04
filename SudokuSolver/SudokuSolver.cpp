#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Build a set of constraints for lines, rows and blocks. Use them to find the fully constrained cells,
 * those that have only one possible value. If no fully constrained cell is found try one of the possibilities
 * and follow it until either no possible number is left for a cell (not a solution) or a full solution is found.
 * This last step is done recursively so that all possible paths are explored until a solution is found.
 */

class Solution {
public:
  void solveSudoku(vector<vector<char> > &board) {

    vector<list<char> > rows;
    vector<list<char> > columns;
    vector<list<char> > blocks;
    initialize(rows);
    initialize(columns);
    initialize(blocks);

    vector<vector<char> > tempBoard(board);

    // Remove all the elements that appear in the matrix
    for( int i=0; i<9; ++i ) {
      for (int j=0; j<9; ++j) {
        char letter = board[i][j];
        if( letter != '.' ) {
          rows[i].remove_if([&](const char c) {return (c==letter);});
          columns[j].remove_if([&](const char c) {return (c==letter);});
          blocks[i/3+(j/3)*3].remove_if([&](const char c) {return (c==letter);});
        }
      }
    }
    // What is left are the constraint lists.
    // Loop on them and find the positions of the fully constrained numbers.
    solve(board, tempBoard, rows, columns, blocks);
  }

  bool solve(vector<vector<char> > &board, vector<vector<char> > tempBoard,
             vector<list<char> > rows, vector<list<char> > columns, vector<list<char> > blocks,
             char testLetter = '_', int lastMissingRowTest = -1, int lastMissingColumnTest = -1)
  {
    if (testLetter != '_' ) {
      tempBoard[lastMissingRowTest][lastMissingColumnTest] = testLetter;
      rows[lastMissingRowTest].remove(testLetter);
      columns[lastMissingColumnTest].remove(testLetter);
      blocks[lastMissingRowTest/3+(lastMissingColumnTest/3)*3].remove(testLetter);
    }

    bool someMissing = true;
    bool found = false;
    while (someMissing == true) {
      found = false;
      someMissing = false;
      int lastMissingRow = -1;
      int lastMissingColumn = -1;
      vector<char> result;
      for( int i=0; i<9; ++i ) {
        for (int j=0; j<9; ++j) {
          char letter = tempBoard[i][j];
          if (tempBoard[i][j] == '.') {
            lastMissingRow = i;
            lastMissingColumn = j;
            someMissing = true;
            vector<char> intermediateResult;
            result.clear();
            set_intersection(rows[i].begin(), rows[i].end(),
                             columns[j].begin(), columns[j].end(),
                             back_inserter(intermediateResult));
            set_intersection(intermediateResult.begin(), intermediateResult.end(),
                             blocks[i/3+(j/3)*3].begin(), blocks[i/3+(j/3)*3].end(),
                             back_inserter(result));
            if( result.size() == 0 ) {
              // Not a solution, go back and try another path
              return false;
            }
            if(result.size() == 1) {
              // Fully constrained cell
              found = true;
              char foundLetter = result[0];
              tempBoard[i][j] = foundLetter;
              rows[i].remove(foundLetter);
              columns[j].remove(foundLetter);
              blocks[i/3+(j/3)*3].remove(foundLetter);
            }
          }
        }
      }
      if (!found && someMissing) {
        // No fully constrained cell remaining, start trying one of the multiple possibilities
        for (std::vector<char>::const_iterator it = result.begin(); it != result.end(); ++it) {
          if (solve(board, tempBoard, rows, columns, blocks, *it, lastMissingRow, lastMissingColumn) == true) {
            return true;
          }
        }
        return false;
      }
    }
    // Merge the board with the tempBoard
    for( int i=0; i<9; ++i ) {
      for (int j=0; j<9; ++j) {
        board[i][j] = tempBoard[i][j];
      }
    }
    return true;
  }

  void initialize(vector<list<char> > & v)
  {
    for (int i=0; i<9; ++i) {
      v.push_back(list<char>({'1', '2', '3', '4', '5', '6', '7', '8', '9'}));
    }
  }
};


int main() {

  std::vector<std::vector<char> > v;
  for (int i=0; i<9; ++i) {
    v.push_back(std::vector<char>());
    for (int j=0; j<9; ++j) {
      v.back().push_back('.');
    }
  }
//  v[0][0] = '5';
//  v[0][1] = '3';
//  v[0][4] = '7';
//  v[1][0] = '6';
//  v[1][3] = '1';
//  v[1][4] = '9';
//  v[1][5] = '5';
//  v[2][1] = '9';
//  v[2][2] = '8';
//  v[2][7] = '6';
//  v[3][0] = '8';
//  v[3][4] = '6';
//  v[3][8] = '3';
//  v[4][0] = '4';
//  v[4][3] = '8';
//  v[4][5] = '3';
//  v[4][8] = '1';
//  v[5][0] = '7';
//  v[5][4] = '2';
//  v[5][8] = '6';
//  v[6][1] = '6';
//  v[6][6] = '2';
//  v[6][7] = '8';
//  v[7][3] = '4';
//  v[7][4] = '1';
//  v[7][5] = '9';
//  v[7][8] = '5';
//  v[8][4] = '8';
//  v[8][7] = '7';
//  v[8][8] = '9';


  // ["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]
  v[0][2] = '9';
  v[0][3] = '7';
  v[0][4] = '4';
  v[0][5] = '8';
  v[1][0] = '7';
  v[2][1] = '2';
  v[2][3] = '1';
  v[2][5] = '9';
  v[3][2] = '7';
  v[3][6] = '2';
  v[3][7] = '4';
  v[4][1] = '6';
  v[4][2] = '4';
  v[4][4] = '1';
  v[4][6] = '5';
  v[4][7] = '9';
  v[5][1] = '9';
  v[5][2] = '8';
  v[5][6] = '3';
  v[6][3] = '8';
  v[6][5] = '3';
  v[6][7] = '2';
  v[7][8] = '6';
  v[8][3] = '2';
  v[8][4] = '7';
  v[8][5] = '5';
  v[8][6] = '9';


  std::cout << "Input:" << std::endl;
  for (int i=0; i<9; ++i) {
    for (int j=0; j<9; ++j) {
      std::cout << v[i][j];
    }
    std::cout << std::endl;
  }

  Solution a;
  a.solveSudoku(v);

  std::cout << std::endl;
  std::cout << "Solution:" << std::endl;

  for (int i=0; i<9; ++i) {
    for (int j=0; j<9; ++j) {
      std::cout << v[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}
