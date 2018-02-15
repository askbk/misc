#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

char gameBoard[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
int playerMove, lastOpponent, winner = -1;

void clearScreen() {
  for (size_t i = 0; i < 100; i++) {
    cout << "\n";
  }
}

void printBoard() {
  for (size_t i = 0; i < 9; i++) {
    cout << gameBoard[i];
    if (!((i + 1) % 3)) {
      cout << "\n";
    }
  }
}

bool validateInput(int a) {
  int inp = a;
  if (-1 < inp && inp < 9) {
    if (!(gameBoard[inp] == '.')) {
      return false;
    }
    return true;
  } else {
    return false;
  }
}

bool available(int a) {
  if (gameBoard[a] == '.') {
    return true;
  }
  return false;
}

int twoInRow(char current) {
  int count = 0, emptyHole = -1;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = i; j < 9; j += 3) { // vertical rows
      if (available(j)) {
        emptyHole = j;
      } else if (gameBoard[j] == current) {
        ++count;
      }
    }
    if (count == 2) {
      return emptyHole;
    }
    count = 0;
    emptyHole = -1;
    int start = 3 * i;
    for (size_t j = start; j < start + 3; j++) { // horizontal
      if (available(j)) {
        emptyHole = j;
      } else if (gameBoard[j] == current) {
        ++count;
      }
    }
    if (count == 2) {
      return emptyHole;
    }
    count = 0;
    emptyHole = -1;
  }

  count = 0;
  emptyHole = -1;
  for (size_t i = 0; i < 9; i += 4) {
    if (available(i)) {
      emptyHole = i;
    } else if (gameBoard[i] == current) {
      ++count;
    }
  }
  if (count == 2) {
    return emptyHole;
  }
  count = 0;
  emptyHole = -1;
  for (size_t i = 2; i < 8; i += 2) {
    if (available(i)) {
      emptyHole = i;
    } else if (gameBoard[i] == current) {
      ++count;
    }
  }
  if (count == 2) {
    return emptyHole;
  }
  return -1;
}

bool threeInRow(char current) {
  int count = 0;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = i; j < 9; j += 3) { // vertical rows
      if (available(j)) {
        break;
      } else if (gameBoard[j] == current) {
        ++count;
      }
    }
    if (count == 3) {
      if (current == 'O') {
        winner = 0;
      } else {
        winner = 1;
      }
      return true;
    }
    count = 0;
    int start = 3 * i;
    for (size_t j = start; j < start + 3; j++) { // horizontal
      if (available(j)) {
        break;
      } else if (gameBoard[j] == current) {
        ++count;
      }
    }
    if (count == 3) {
      if (current == 'O') {
        winner = 0;
      } else {
        winner = 1;
      }
      return true;
    }
    count = 0;
  }

  count = 0;
  for (size_t i = 0; i < 9; i += 4) {
    if (available(i)) {
      break;
    } else if (gameBoard[i] == current) {
      ++count;
    }
  }
  if (count == 3) {
    if (current == 'O') {
      winner = 0;
    } else {
      winner = 1;
    }
    return true;
  }
  count = 0;
  for (size_t i = 2; i < 8; i += 2) {
    if (available(i)) {
      break;
    } else if (gameBoard[i] == current) {
      ++count;
    }
  }
  if (count == 3) {
    if (current == 'O') {
      winner = 0;
    } else {
      winner = 1;
    }
    return true;
  }
  return false;
}

void opponent(int a) {
  int move = twoInRow('O');
  if (move != -1) {
    gameBoard[move] = 'O';
    //cout << "moving to " << move << " to win\n";
    return;
  }
  move = twoInRow('X');
  if (move != -1) {
    gameBoard[move] = 'O';
    //cout << "moving to " << move << " to obstruct\n";
    return;
  }
  move = 4;
  if (available(move)) {
    gameBoard[move] = 'O';
    //cout << "moving to " << move << " for mid\n";
    return;
  }
  move = 8 - a;
  if (available(move)) {
    gameBoard[move] = 'O';
    //cout << "moving to " << move << " for tactics\n";
    return;
  }
  for (size_t i = 0; i < 9; i += 2) {
    if (available(i)) {
      gameBoard[i] = 'O';
      //cout << "moving to " << move << " for corner\n";
      return;
    }
  }
  for (size_t i = 1; i < 9; i += 2) {
    if (available(i)) {
      gameBoard[i] = 'O';
      //cout << "moving to " << move << " for available\n";
      return;
    }
  }
}

int main() {
  int turns = 0;
  while (winner == -1) {
    clearScreen();
    printBoard();
    cout << "your turn. please enter a position 0-8\n";
    for (;;) {
      if (cin >> playerMove) {
        if (validateInput(playerMove)) {
          break;
        }
        cout << "invalid input. is occupied or out of bounds? ;)\n";
      } else {
        cout << "Please enter a valid integer 0-8" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
    gameBoard[playerMove] = 'X';
    ++turns;
    if (turns==9) {
      break;
    }
    if (threeInRow('X')) {
      break;
    }
    opponent(playerMove);
    ++turns;
    if (threeInRow('O')) {
      break;
    }
  }
  clearScreen();
  printBoard();
  if (winner == 1) {
    cout << "yuo win! ;)\n";
  } else if (winner == 0) {
    cout << "cumputadore wins! ;)\n";
  } else {
    cout << "ends in tie! :) :)\n";
  }
}
