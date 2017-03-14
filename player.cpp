#include "player.h"

//constructor
Player::Player(int id, string color){
  playerID = id;
  playerColor = color;
}

int Player::getPlayerID(){
  return playerID;
}

string Player::getPlayerColor(){
  return playerColor;
}
