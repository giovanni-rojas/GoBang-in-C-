#include "goboard.h"

//GoBoard constructor
GoBoard::GoBoard(int size)
{
  boardSize = size;
  grid = new char* [size];
  for(int i = 0; i < size; i++)
    grid[i] = new char[size];
  for(int i = 0; i <  boardSize; i++)
    for(int j = 0; j < boardSize; j++)
      grid[i][j] = '.';
  nrounds = 0;
  nmoves = 0;
  lastMove[0][0] = lastMove[0][1] = lastMove[1][0] = lastMove[1][1] = -1;
}

GoBoard::~GoBoard(){
  for(int i = 0; i < boardSize; i++)
    delete grid[i];
  delete[] grid;
}

//returns true if board does not exist
bool GoBoard::emptySpace(int i, int j){
  return grid[i][j] == '.';
}

//prints out basic board with both axes
void GoBoard::printBoard(int playerID){
  string border = "   +";
  cout << "   ";
  
  //formats border string
  for(int i = 0; i < boardSize; i++)
    border += "---+";

  //prints out grid's horizontal axis
  for(int i = 0; i < boardSize; i++){
    char letter = 'a' + i;
    cout << "  " << letter << " ";
  }
  
  cout << endl;
  
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

  printBoardInfo(playerID);	
}

//prompts human player for their move choice
void GoBoard::printPrompt(int playerID, string playerColor){
  if(playerColor == "Dark"){
    cout << playerColor << " player plays now" << endl;
    //cout << ">";
    //cout << "Player #" << playerID <<" chooses: ";
  }
  else if(playerColor == "Light"){
    cout << playerColor << " player plays now" << endl;
    //cout << playerColor << " player (COM) is calculating its next move... (this might take up to 30 seconds)";
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
char GoBoard::getWinner(){
  for(int i = 0; i < boardSize; i++)
    for(int j = 0; j < boardSize; j++){
      if(fiveConsecutive(i, j)){
	if(grid[i][j] == '.')
	  cout << "[getWinner] cannot win at empty spot" << endl;
	if(grid[i][j] == 'D')
	  return 'D';
	else
	  return 'L';
      }
    }
  return '\0';
}


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

void GoBoard::printBoardInfo(int playerID){
  //cout << "nmoves: " << nmoves << ", nrounds: " << nrounds << endl;
  char ch = 'a' + lastMove[playerID - 1][0];
  //char ch2 = 'a' + lastMove[1][0];
  //char col = 'a' + lastMove[getPlayerID]
  if(ch == 'a' - 1){
    //cout << "last move player #1 (N/A)" << endl;
    //cout << "last move player #2 (N/A)\n" << endl;
    cout << "Move played: --" << endl;
  }
  else{
    //cout << "last move player #1 (" << ch1 << "," << lastMove[0][1] + 1 << ")" << endl;
    //cout << "last move player #2 (" << ch2 << "," << lastMove[1][1] + 1 << ")\n" << endl;
    cout << "Move played: " << ch << lastMove[playerID - 1][1] + 1 << endl;
  }
}

//#######################################################################
/*
void GoBoard::setGoTemp(char playerColor, int row, int col){
  if(playerColor == 'D')
    grid[row][col] = 'D';
  else if(playerColor == 'L')
    grid[row][col] = 'L';
  else
    grid[row][col] = '.';
}

void GoBoard::setBack(int row, int col){
  grid[row][col] = '.';
}
*/
