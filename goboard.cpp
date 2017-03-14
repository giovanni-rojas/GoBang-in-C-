#include "goboard.h"

//GoBoard constructor
GoBoard::GoBoard()
{
  for(int i = 0; i <  boardSize; i++)
    for(int j = 0; j < boardSize; j++)
      grid[i][j] = '.';
  nrounds = 0;
  nmoves = 0;
  lastMove[0][0] = lastMove[0][1] = lastMove[1][0] = lastMove[1][1] = -1;
}

//returns true if board does not exist
bool GoBoard::emptySpace(int i, int j){
  return grid[i][j] == '.';
}

//prints out basic board with both axes
void GoBoard::printBoard(){
  string border = "   +";
  cout << "   ";
  /*
  //prints out grid's horizontal axis
  for(int i = 0; i < boardSize; i++){
    cout << i + 1 << " ";
    if(i < 9)
      cout << " ";
  }
  
  cout << endl;

  //prints out grid's vertical axis
  for(int i = 0; i < boardSize; i++){
    char letter = 'A' + i;
    cout << letter << " ";
    for(int j = 0; j < boardSize; j++){
      cout << grid[i][j];
      if(j == boardSize - 1)
	cout << endl;
      else
	cout << "  ";
    }
  }

  printBoardInfo();
  */
  
  //formats border string
  for(int i = 0; i < boardSize; i++)
    border += "---+";

  //prints out grid's horizontal axis
  for(int i = 0; i < boardSize; i++){
    char letter = 'a' + i;
    cout << "  " << letter << " ";
  }
  
  cout << endl;

  //prints out grid's vertical axis
  /*for(int i = 0; i < boardSize; i++){
    cout << i + 1 << " ";
    for(int j = 0; j < boardSize; j++){
      cout << grid[i][j];
      if(j == boardSize - 1)
	cout << endl;
      else
	cout << "  ";
    }
  }
  */
  
  for(int i = 0; i < boardSize; i++){
    cout << border << endl;
    if(i < 9)
      cout << " " << i + 1 << " | ";
    else
      cout << i + 1 << " | ";
    for(int j = 0; j < boardSize; j++){
      cout << grid[i][j] << " | ";
      if(j == boardSize - 1)
        cout << endl;
    }
  }

  cout << border << endl;

  printBoardInfo();	
}

//prompts human player for their move choice
void GoBoard::printPrompt(int playerID, string playerColor){
  if(playerID == 1){
    cout << "Dark player (human) plays now" << endl;
    cout << ">";
    //cout << "Player #" << playerID <<" chooses: ";
  }
  else if(playerID == 2){
    cout << "Light player (COM) plays now" << endl;
    cout << "Light player (COM) is calculating its next move... (this might take up to 30 seconds)";
  }
}

//sets the player's move choice on the board
void GoBoard::setGo(int playerID, string playerColor, int row, int col){
  if(playerID > 0 && !emptySpace(row,col)){
    cout << "[setGo]ERROR: cannot set the board" << endl;
    return;
  }
  if(playerColor == "Dark")
    grid[row][col] = 'D';
  else if(playerColor == "Light")
    grid[row][col] = 'L';
  else
    grid[row][col] = '.';

  if(playerID > 0){
    nmoves += 1;
    nrounds = nmoves / 2;
    lastMove[playerID - 1][0] = col;
    lastMove[playerID - 1][1] = row;
  }
}

char GoBoard::getGo(int i, int j){
  assert(i >= 0 && i < boardSize && j >= 0 && j < boardSize);
  return grid[i][j];
}


//returns playerID of game winner
string GoBoard::getWinner(){
  for(int i = 0; i < boardSize; i++)
    for(int j = 0; j < boardSize; j++){
      if(fiveConsecutive(i, j)){
	if(grid[i][j] == '.')
	  cout << "[getWinner] cannot win at empty spot" << endl;
	if(grid[i][j] == 'D')
	  return "Dark";
	else
	  return "Light";
      }
    }
  return "";
}

/*
void GoBoard::randomTest(){

}
*/

bool GoBoard::fiveConsecutive(int i, int j){
  char currentSpot = grid[i][j];
  if(currentSpot == '.')
    return false;

  //horizontal case
  if(j - 2 >= 0 && j + 2 <= boardSize - 1){
    int count = 0;
    for(int t = j - 2; t <= j + 2; t++)
      if(grid[i][t] == currentSpot)
	count += 1;
    if(count == 5)
      return true;
  }

  //vertical case
  if(i - 2 >= 0 && i + 2 <= boardSize - 1){
    int count = 0;
    for(int t = i - 2; t <= i + 2; t++)
      if(grid[t][j] == currentSpot)
	count += 1;
    if(count == 5)
      return true;
  }

  //diagonal case
  if(j - 2 >= 0 && j + 2 <= boardSize - 1 && i - 2 >= 0 && i + 2 <= boardSize - 1){
    int leftCount = 0, rightCount = 0;
    int startRow = i - 2;
    int startCol = j - 2;
    for(int t = 0; t < 5; t++)
      if(grid[startRow + t][startCol + t] == currentSpot)
	leftCount += 1;
    if(leftCount == 5)
      return true;
    startCol = j + 2;
    for(int t = 0; t < 5; t++)
      if(grid[startRow + t][startCol - t] == currentSpot)
	rightCount += 1;
    if(rightCount == 5)
      return true;
  }

  return false;
  
}

void GoBoard::printBoardInfo(){
  //cout << "nmoves: " << nmoves << ", nrounds: " << nrounds << endl;
  char ch1 = 'a' + lastMove[0][0];
  char ch2 = 'a' + lastMove[1][0];
  if(ch1 == 'a' - 1){
    //cout << "last move player #1 (N/A)" << endl;
    //cout << "last move player #2 (N/A)\n" << endl;
    cout << "Move played: --" << endl;
  }
  else{
    cout << "last move player #1 (" << ch1 << "," << lastMove[0][1] + 1 << ")" << endl;
    cout << "last move player #2 (" << ch2 << "," << lastMove[1][1] + 1 << ")\n" << endl;
  }
}
