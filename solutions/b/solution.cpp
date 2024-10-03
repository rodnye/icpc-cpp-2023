
/*! 
 * ICPC Problems 2023
 * Problem: 2023B
 * Answer: Rodny Estrada<rrodnyestrada1@gmail.com>
 */
#include <iostream>
#include <vector>
using namespace std;

class Cell {
  public:
    int number;
    int mark = 0;  // (0: empty), (1: first player), (2: second player), (-1: deleted) 
};


int check_winner (vector<Cell> &board) {
  int n = board.size();
  int sumPlayer1 = 0;
  int sumPlayer2 = 0;
  for (int i = 0; i < n; i++) {
    Cell &cell = board[i];
    if (cell.mark == -1 || cell.mark == 0) return 0; // no winner yet
    if (cell.mark == 1) sumPlayer1 += cell.number;
    else if (cell.mark == 2) sumPlayer2 += cell.number;
  }

  if (sumPlayer1 != sumPlayer2) return 1; // first player wins
  if (sumPlayer1 == sumPlayer2) return 2; // second player wins
}


int main () {
  int rounds; // N
  cin >> rounds;

  // numbers initially writen on board
  int leftNumbers = 3 * rounds;
  vector<Cell> board(3 * rounds);
  for (int i = 0; i < 3 * rounds; i++ ) {
    cin >> board[i].number;
  }

  for (int i = 0; i < rounds; i++) {
    // 1: first player set mark
    // 2: second player set mark
    // 3: second player remove a cell
    int turn = 
      i % 2 == 0? 2 :
      i % 3 == 0? 3 : 1;
    
    // ...
    // implement algorithm here...
    // ...
  }

  return 0;
}