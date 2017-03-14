#ifndef GOBOARD_H
#define GOBOARD_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
//#include <ctime>
using namespace std;

#define boardSize 11 

class GoBoard
{
 public:
  
  GoBoard();
  bool emptySpace(int i, int j);
  void printBoard();
  void printPrompt(int playerID, string playerColor);
  void setGo(int playerID, string playerColor, int i, int j);
  char getGo(int i, int j);
  string getWinner();

 private:

  //int boardSize = 11; //default
  bool fiveConsecutive(int i, int j);
  void printBoardInfo();

  char grid[boardSize][boardSize]; //in grid[col][row] form
  int nrounds;
  int nmoves;
  int lastMove[2][2]; //reps players #(i+1)'s last move

};

#endif //GOBOARD_H
