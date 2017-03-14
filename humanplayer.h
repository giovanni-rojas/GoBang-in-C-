#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"

class HumanPlayer: public Player{

 public:
  HumanPlayer(int, string);
  void play(GoBoard &);

};

#endif
