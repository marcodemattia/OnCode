#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  void solveSudoku(vector<vector<char> > &board) {
    // std::cout << "solving" << std::endl;
    
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
        // tempBoard[i][j] = board[i][j];
        if( letter != '.' ) {
          rows[i].remove_if([&](const char c) {return (c==letter);});
          columns[j].remove_if([&](const char c) {return (c==letter);});
          // std::cout <<i<<"%3+("<<j<<"%3)*3 = " << i%3+(j%3)*3 << std::endl;
          blocks[i/3+(j/3)*3].remove_if([&](const char c) {return (c==letter);});
        }
      }
    }
    
//    for (int i=0; i<9; ++i) {
//      std::cout << "blocks["<<i<<"] = " << std::endl;
//      for (list<char>::const_iterator it = blocks[i].begin(); it != blocks[i].end(); ++it)
//        std::cout << *it << std::endl;
//      for (list<char>::const_iterator it = rows[i].begin(); it != rows[i].end(); ++it)
//        std::cout << *it << std::endl;
//      for (list<char>::const_iterator it = columns[i].begin(); it != columns[i].end(); ++it)
//        std::cout << *it << std::endl;
//    }
    
    // return;
    
    // What is left are the constraint lists.
    // Loop on them and find the positions of the fully constrained numbers.
    if (solve(board, tempBoard, rows, columns, blocks)) std::cout << "Solved" << std::endl;
    else std::cout << "No solution found" << std::endl;
  }

  bool solve(vector<vector<char> > &board, vector<vector<char> > tempBoard,
             vector<list<char> > rows, vector<list<char> > columns, vector<list<char> > blocks,
             char testLetter = '_', int lastMissingRowTest = -1, int lastMissingColumnTest = -1)
  {
    if (testLetter != '_' ) {
      // std::cout << "we have a problem, result.size = " << result.size() << std::endl;
      std::cout << "testLetter["<<lastMissingRowTest<<"]["<<lastMissingColumnTest<<"] = " << testLetter << std::endl;
      tempBoard[lastMissingRowTest][lastMissingColumnTest] = testLetter;
      rows[lastMissingRowTest].remove(testLetter);
      columns[lastMissingColumnTest].remove(testLetter);
      blocks[lastMissingRowTest/3+(lastMissingColumnTest/3)*3].remove(testLetter);
    }

    bool someMissing = true;
    bool found = false;
    while( someMissing == true ) {
      found = false;
      someMissing = false;
      int lastMissingRow = -1;
      int lastMissingColumn = -1;
      vector<char> result;
      for( int i=0; i<9; ++i ) {
        for (int j=0; j<9; ++j) {
          // if (letter == '.' && tempBoard[i][j] == '.') {
          // char letter = board[i][j];
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
            // std::cout << "found one board["<<i<<"]["<<j<<"]" << std::endl;
            std::cout << "result size = " << result.size() << std::endl;
            if( result.size() == 0 ) {
              std::cout << "tempBoard = " << std::endl;
              for( int i=0; i<9; ++i ) {
                for (int j=0; j<9; ++j) {
                  // if (tempBoard[i][j] != '.') {
                  std::cout << tempBoard[i][j];
                    // board[i][j] = tempBoard[i][j];
                  // }
                }
                std::cout << std::endl;
              }
              std::cout << "this is not good" << std::endl;
              return false;
            }
            if(result.size() == 1) {
              found = true;
              char foundLetter = result[0];
              // board[i][j] = foundLetter;
              tempBoard[i][j] = foundLetter;
              rows[i].remove(foundLetter);
              columns[j].remove(foundLetter);
              blocks[i/3+(j/3)*3].remove(foundLetter);
            }
          }
        }
      }
      if (!found && someMissing) {
//        // Merge the board with the tempBoard
//        for( int i=0; i<9; ++i ) {
//          for (int j=0; j<9; ++j) {
//            if (tempBoard[i][j] != '.') {
//            // std::cout << "tempBoard["<<i<<"]["<<j<<"] = " << tempBoard[i][j] << std::endl;
//              board[i][j] = tempBoard[i][j];
//            }
//          }
//        }
//        return true;
        std::cout << "result size (test) = " << result.size() << std::endl;
        for (std::vector<char>::const_iterator it = result.begin(); it != result.end(); ++it) {
          if (solve(board, tempBoard, rows, columns, blocks, *it, lastMissingRow, lastMissingColumn) == true) {
            // std::cout << "this was good, inside" << std::endl;
            return true;
          }
        }
        return false;
//        // std::cout << "we have a problem, result.size = " << result.size() << std::endl;
//        char foundLetter = result[0];
//        std::cout << "foundLetter = " << foundLetter << std::endl;
//        // board[lastMissingRow][lastMissingColumn] = foundLetter;
//        tempBoard[lastMissingRow][lastMissingColumn] = foundLetter;
//        rows[lastMissingRow].remove(foundLetter);
//        columns[lastMissingColumn].remove(foundLetter);
//        blocks[lastMissingRow/3+(lastMissingColumn/3)*3].remove(foundLetter);
      }
    }
    std::cout << "this was good" << std::endl;
    // Merge the board with the tempBoard
    for( int i=0; i<9; ++i ) {
      for (int j=0; j<9; ++j) {
        // if (tempBoard[i][j] != '.') {
        std::cout << "tempBoard["<<i<<"]["<<j<<"] = " << tempBoard[i][j] << std::endl;
        board[i][j] = tempBoard[i][j];
        // }
      }
    }
    return true;
  }
  
  
  
  void initialize(vector<list<char> > & v)
  {
    for (int i=0; i<9; ++i) {
      v.push_back(list<char>({'1', '2', '3', '4', '5', '6', '7', '8', '9'}));
//      v[i].push_back('1');
//      v[i].push_back('2');
//      v[i].push_back('3');
//      v[i].push_back('4');
//      v[i].push_back('5');
//      v[i].push_back('6');
//      v[i].push_back('7');
//      v[i].push_back('8');
//      v[i].push_back('9');
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
