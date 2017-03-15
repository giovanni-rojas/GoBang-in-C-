#include "humanplayer.h"

HumanPlayer::HumanPlayer(int id, string color):Player(id, color)
{
}

void HumanPlayer::play(GoBoard &goBoard){
  char ch;
  int col, row;
  while(true){
    cin >> ch >> row;
    if(ch >= 'A' && ch <= 'Z')
      ch = ch + ('a' - 'A');
    if(ch < 'a' || ch > 'z' || row <= 0 || row > goBoard.getSize()){
      cout << "please enter a valid letter + number coordinate" << endl;
      goBoard.printPrompt(playerID, playerColor);
      continue;
    }
    col = ch - 'a';
    row = row - 1; //for entering into C++ array
    if(!goBoard.emptySpace(row,col)){
      cout << ch << row + 1 << " is filled, please enter another pair" << endl;
      goBoard.printPrompt(playerID, playerColor);
      continue;
    }
    break;
  }

  goBoard.setGo(playerID, playerColor, row, col);

}
