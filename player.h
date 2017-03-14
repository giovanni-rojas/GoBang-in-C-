#ifndef PLAYER_H
#define PLAYER_H

#include "goboard.h"

class Player
{
 public:
  Player(int, string);
  int getPlayerID();
  string getPlayerColor();
  virtual void play(GoBoard &){}

 protected:
  int playerID;
  string playerColor;

};

#endif
