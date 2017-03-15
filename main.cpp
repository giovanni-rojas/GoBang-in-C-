#include <iostream>
#include <stdlib.h>
#include "goboard.h"
#include "humanplayer.h"
#include "computerplayer.h"

using namespace std;

int main(int argc, char *argv[]){
  //GoBoard goBoard;
  //HumanPlayer human(1, "Dark");
  //ComputerPlayer computer(2, "Light");
  
  if(argc == 1){   
    GoBoard goBoard(11); 
    HumanPlayer human(1, "Dark");
    ComputerPlayer computer(2, "Light");

    while(true){
      goBoard.printBoard(computer.getPlayerID());
      char winner = goBoard.getWinner();
      if(winner != '\0'){
        cout << winner <<" player wins!"<< endl;
        break;
      }

      goBoard.printPrompt(human.getPlayerID(), human.getPlayerColor());
      human.play(goBoard);
      goBoard.printBoard(human.getPlayerID());

      winner = goBoard.getWinner();
      if(winner != '\0'){
        cout << winner <<" player wins!"<< endl;
        break;
      }
    
      goBoard.printPrompt(computer.getPlayerID(), computer.getPlayerColor());
      computer.play(goBoard);
    } 
  }


  
  if(argc == 2 && (argv[1][1] == 'l')){    
    GoBoard goBoard(11); 
    HumanPlayer human(2, "Light");
    ComputerPlayer computer(1, "Dark");

    while(true){
      goBoard.printBoard(human.getPlayerID());
      char winner = goBoard.getWinner();
      if(winner != '\0'){
        cout << winner <<" player wins!"<< endl;
        break;
      }

      goBoard.printPrompt(computer.getPlayerID(), computer.getPlayerColor());
      computer.play(goBoard);
      goBoard.printBoard(computer.getPlayerID());

      winner = goBoard.getWinner();
      if(winner != '\0'){
        cout << winner <<" player wins!"<< endl;
        break;
      }
    
      goBoard.printPrompt(human.getPlayerID(), human.getPlayerColor());
      human.play(goBoard);
    } 
  }

  if(argc == 3 && (argv[1][1] == 'n')){    
    GoBoard goBoard(atoi(argv[2])); 
    HumanPlayer human(1, "Dark");
    ComputerPlayer computer(2, "Light");

    while(true){
      goBoard.printBoard(computer.getPlayerID());
      char winner = goBoard.getWinner();
      if(winner != '\0'){
        cout << winner <<" player wins!"<< endl;
        break;
      }

      goBoard.printPrompt(human.getPlayerID(), human.getPlayerColor());
      human.play(goBoard);
      goBoard.printBoard(human.getPlayerID());

      winner = goBoard.getWinner();
      if(winner != '\0'){
        cout << winner <<" player wins!"<< endl;
        break;
      }
    
      goBoard.printPrompt(computer.getPlayerID(), computer.getPlayerColor());
      computer.play(goBoard);
    } 
  }
  

  if(argc == 4 && (argv[2][1] == 'n')){    
    GoBoard goBoard(atoi(argv[3])); 
    HumanPlayer human(2, "Light");
    ComputerPlayer computer(1, "Dark");

    while(true){
      goBoard.printBoard(human.getPlayerID());
      char winner = goBoard.getWinner();
      if(winner != '\0'){
        cout << winner <<" player wins!"<< endl;
        break;
      }

      goBoard.printPrompt(computer.getPlayerID(), computer.getPlayerColor());
      computer.play(goBoard);
      goBoard.printBoard(computer.getPlayerID());

      winner = goBoard.getWinner();
      if(winner != '\0'){
        cout << winner <<" player wins!"<< endl;
        break;
      }
    
      goBoard.printPrompt(human.getPlayerID(), human.getPlayerColor());
      human.play(goBoard);
    } 
  }
  
  return 0;

  /* for(int i = 0; i < argc; i++){
    if (std::string(argv[i]) == "-n")
      GoBoard goBoard(atoi(argv[i+1]));
    else
      GoBoard goBoard(11);
      }
  for(int i = 0; i < argc; i++){
    if (std::string(argv[i]) == "-l" || std::string(argv[i]) == "-n"){
      if (std::string(argv[i]) == "-n")
	GoBoard goBoard(atoi(argv[i+1]));
      else
	GoBoard goBoard(11);
      if(std::string(argv[i]) == "-l"){
	HumanPlayer human(2, "Light");
	ComputerPlayer computer(1, "Dark");
	
	while(true){
	  goBoard.printBoard(human.getPlayerID());
	  char winner = goBoard.getWinner();
	  if(winner != '\0'){
	    cout << winner <<" player wins!"<< endl;
	    break;
	  }
	  
	  goBoard.printPrompt(computer.getPlayerID(), computer.getPlayerColor());
	  computer.play(goBoard);
	  goBoard.printBoard(computer.getPlayerID());
	  
	  winner = goBoard.getWinner();
	  if(winner != '\0'){
	    cout << winner <<" player wins!"<< endl;
	    break;
	  }
	  
	  goBoard.printPrompt(human.getPlayerID(), human.getPlayerColor());
	  human.play(goBoard);
	}
      }
    }
    else{
      GoBoard goBoard(11);
      HumanPlayer human(1, "Dark");
      ComputerPlayer computer(2, "Light");
      
      while(true){
	goBoard.printBoard(computer.getPlayerID());
	char winner = goBoard.getWinner();
	if(winner != '\0'){
	  cout << winner <<" player wins!"<< endl;
	  break;
	}
	
	goBoard.printPrompt(human.getPlayerID(), human.getPlayerColor());
	human.play(goBoard);
	goBoard.printBoard(human.getPlayerID());
	
	winner = goBoard.getWinner();
	if(winner != '\0'){
	  cout << winner <<" player wins!"<< endl;
	  break;
	}
	
	goBoard.printPrompt(computer.getPlayerID(), computer.getPlayerColor());
	computer.play(goBoard);
      }
    }
  }
  return 0;*/
}
