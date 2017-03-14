#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"

class ComputerPlayer: public Player{
 public:
  ComputerPlayer(int, string);
  void play(GoBoard &);

 private:
  
  void decision(GoBoard &, int &, int &);
  int horizontalVal(GoBoard &, int, int);
  int verticalVal(GoBoard &, int, int);
  int majorDiagVal(GoBoard &, int, int);
  int minorDiagVal(GoBoard &, int, int);
  int calculateScore(int, int, int);

};

#endif
