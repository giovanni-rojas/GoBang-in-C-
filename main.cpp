#include <iostream>
#include "goboard.h"
#include "humanplayer.h"
#include "computerplayer.h"

using namespace std;

int main(int argc, char *argv[]){
  GoBoard goBoard;
  HumanPlayer human(1, "Dark");
  ComputerPlayer computer(2, "Light");

    /*if(argc > 1 && argv[1]== "-l"){
    HumanPlayer human(1, "Light");
    ComputerPlayer computer(2, "Dark");
  }
  
  else{    
    HumanPlayer human(1, "Dark");
    ComputerPlayer computer(2, "Light");
  }
    */
  while(true){
    goBoard.printBoard();
    string winner = goBoard.getWinner();
    if(!winner.empty()){
      cout << winner <<" player wins!"<< endl;
      break;
    }

    goBoard.printPrompt(human.getPlayerID(), human.getPlayerColor());
    human.play(goBoard);
    goBoard.printBoard();

    winner = goBoard.getWinner();
    if(!winner.empty()){
      cout << winner <<" player wins!"<< endl;
      break;
    }
    
    goBoard.printPrompt(computer.getPlayerID(), computer.getPlayerColor());
    computer.play(goBoard);
  }

  return 0;
}
