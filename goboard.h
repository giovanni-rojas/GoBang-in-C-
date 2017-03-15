#ifndef GOBOARD_H
#define GOBOARD_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

//#define boardSize 11 

class GoBoard
{
 public:
  
  GoBoard(int boardSize);
  ~GoBoard();
  bool emptySpace(int i, int j);
  void printBoard(int playerID);
  void printPrompt(int playerID, string playerColor);
  void setGo(int playerID, string playerColor, int i, int j);
  char getGo(int i, int j);
  int getSize(){return boardSize;}
  int getNMoves(){return nmoves;}
  char getWinner();

  //void setGoTemp(char playerColor, int row, int col);
  //void setBack(int row, int col);
  
 private:

  bool fiveConsecutive(int i, int j);
  void printBoardInfo(int playerID);

  char **grid;
  int boardSize;
  int nrounds;
  int nmoves;
  int lastMove[2][2]; //reps players #(i+1)'s last move

};

#endif //GOBOARD_H
