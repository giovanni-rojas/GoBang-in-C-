#include "computerplayer.h"

ComputerPlayer::ComputerPlayer(int id, string color) : Player(id, color){
}

void ComputerPlayer::play(GoBoard &goBoard){
  
  int row, col;
  decision(goBoard, row, col);
  //decision2(goBoard, row, col);
  char ch = 'a' + col;
  cout << ch << row + 1 << endl;
  goBoard.setGo(playerID, playerColor, row, col);
  
}


void ComputerPlayer::decision(GoBoard &goBoard, int &rowOpt, int &colOpt){
  int maxVali = -1, maxValj = -1;
  int maxValue = -1;
  for(int i = 0; i < goBoard.getSize(); i++)
    for(int j = 0; j < goBoard.getSize(); j++){
      if(!goBoard.emptySpace(i,j))
		continue;
      int score = horizontalVal(goBoard, i, j) + verticalVal(goBoard, i, j) + majorDiagVal(goBoard, i, j) + minorDiagVal(goBoard, i, j);
      if(score > maxValue){
		maxVali = i;
		maxValj = j;
		maxValue = score;
      }
    }
  rowOpt = maxVali;
  colOpt = maxValj;
}



int ComputerPlayer::horizontalVal(GoBoard &goBoard, int i, int j){

  int count1 = 0, count2 = 0;
  int sideBlock = 0;
  char selfChar, rivalChar;

  if(getPlayerColor() == "Dark"){
  	selfChar = 'D';
  	rivalChar = 'L';
  }
  else{
  	selfChar = 'L';
  	rivalChar = 'D';
  }

  //rightward search, self piece
  int j1 = j + 1;
  while(j1 < goBoard.getSize() && goBoard.getGo(i, j1) == selfChar){
    j1 += 1;
    count1 += 1;
  }
  if(j1 == goBoard.getSize() || goBoard.getGo(i, j1) == rivalChar)
    sideBlock += 1;

  //leftward search, self piece
  j1 = j - 1;
  while(j1 >= 0 && goBoard.getGo(i, j1) == selfChar){
    j1 -= 1;
    count1 += 1;
  }
  if(j1 < 0 || goBoard.getGo(i, j1) == rivalChar)
    sideBlock += 1;

  //rightward search, rival piece
  int j2 = j + 1;
  while(j2 < goBoard.getSize() && goBoard.getGo(i, j2) == rivalChar){
    j2 += 1;
    count2 += 1;
  }

  //leftward search, rival piece
  j2 = j - 1;
  while(j2 >= 0 && goBoard.getGo(i, j2) == rivalChar){
    j2 -= 1;
    count2 += 1;
  }

  return calculateScore(count1, count2, sideBlock);
}

int ComputerPlayer::verticalVal(GoBoard &goBoard, int i, int j){
  int count1 = 0, count2 = 0;
  int sideBlock = 0;
  char selfChar, rivalChar;

  if(getPlayerColor() == "Dark"){
  	selfChar = 'D';
  	rivalChar = 'L';
  }
  else{
  	selfChar = 'L';
  	rivalChar = 'D';
  }

  //downward search, self piece
  int i1 = i + 1;
  while(i1 < goBoard.getSize() && goBoard.getGo(i1, j) == selfChar){
    i1 += 1;
    count1 += 1;
  }
  if(i1 == goBoard.getSize() || goBoard.getGo(i1, j) == rivalChar)
    sideBlock += 1;

  //upward search, self piece
  i1 = i - 1;
  while(i1 >= 0 && goBoard.getGo(i1, j) == selfChar){
    i1 -= 1;
    count1 += 1;
  }
  if(i1 < 0 || goBoard.getGo(i1, j) == rivalChar)
    sideBlock += 1;

  //downward search, rival piece
  int i2 = i + 1;
  while(i2 < goBoard.getSize() && goBoard.getGo(i2, j) == rivalChar){
    i2 += 1;
    count2 += 1;
  }

  //upward search, rival piece
  i2 = i - 1;
  while(i2 >= 0 && goBoard.getGo(i2, j) == rivalChar){
    i2 -= 1;
    count2 += 1;
  }

  return calculateScore(count1, count2, sideBlock);
}

int ComputerPlayer::majorDiagVal(GoBoard &goBoard, int i, int j){
  int count1 = 0, count2 = 0;
  int sideBlock = 0;
  char selfChar, rivalChar;

  if(getPlayerColor() == "Dark"){
  	selfChar = 'D';
  	rivalChar = 'L';
  }
  else{
  	selfChar = 'L';
  	rivalChar = 'D';
  }
  
  //SEastward search, self piece
  int delta = 1;
  while(i + delta < goBoard.getSize() && j + delta < goBoard.getSize() && goBoard.getGo(i + delta, j + delta) == selfChar){
    delta += 1;
    count1 += 1;
  }
  if(i + delta == goBoard.getSize() || j + delta == goBoard.getSize() ||  goBoard.getGo(i + delta, j + delta) == rivalChar)
    sideBlock += 1;

  //NWestward search, self piece
  delta = -1;
  while(i + delta >= 0 && j + delta >= 0 && goBoard.getGo(i + delta, j + delta) == selfChar){
    delta -= 1;
    count1 += 1;
  }
  if(i + delta < 0 || j + delta < 0 || goBoard.getGo(i + delta, j + delta) == rivalChar)
    sideBlock += 1;

  //SEastward search, rival piece
  delta = 1;
  while(i + delta < goBoard.getSize() && j + delta < goBoard.getSize() && goBoard.getGo(i + delta, j + delta) == rivalChar){
    delta += 1;
    count2 += 1;
  }

  //NWestward search, rival piece
  delta = -1;
  while(i + delta >= 0 && j + delta >= 0 && goBoard.getGo(i + delta, j + delta) == rivalChar){
    delta -= 1;
    count2 += 1;
  }

  return calculateScore(count1, count2, sideBlock);
}

int ComputerPlayer::minorDiagVal(GoBoard &goBoard, int i, int j){
  int count1 = 0, count2 = 0;
  int sideBlock = 0;
  char selfChar, rivalChar;

  if(getPlayerColor() == "Dark"){
  	selfChar = 'D';
  	rivalChar = 'L';
  }
  else{
  	selfChar = 'L';
  	rivalChar = 'D';
  }

  //NEastward search, self piece
  int delta = 1;
  while(i - delta >= 0 && j + delta < goBoard.getSize() && goBoard.getGo(i - delta, j + delta) == selfChar){
    delta += 1;
    count1 += 1;
  }
  if(i - delta < 0 || j + delta == goBoard.getSize() ||  goBoard.getGo(i - delta, j + delta) == rivalChar)
    sideBlock += 1;

  //SWestward search, self piece
  delta = 1;
  while(i + delta < goBoard.getSize() && j - delta >= 0 && goBoard.getGo(i + delta, j - delta) == selfChar){
    delta += 1;
    count1 += 1;
  }
  if(i + delta == goBoard.getSize() || j - delta < 0 || goBoard.getGo(i + delta, j - delta) == rivalChar)
    sideBlock += 1;

  //NEastward search, rival piece
  delta = 1;
  while(i - delta >= 0 && j + delta < goBoard.getSize() && goBoard.getGo(i - delta, j + delta) == rivalChar){
    delta += 1;
    count2 += 1;
  }
  

  //SWestward search, rival piece
  delta = 1;
  while(i + delta < goBoard.getSize() && j - delta >= 0 && goBoard.getGo(i + delta, j - delta) == rivalChar){
    delta += 1;
    count2 += 1;
  }

  return calculateScore(count1, count2, sideBlock);
}


int ComputerPlayer::calculateScore(int count1, int count2, int sideBlock){
  if(count2 == 3)
    count2 += 40;
  if(count1 == 3)
    count1 += 25;
  if(count2 >= 4)
    count2 += 100;
  if(count1 >= 4)
    count1 += 120;
  return (count1 + count2) * 5 - sideBlock;
}


//##################################################
/*
int ComputerPlayer::minimax(GoBoard &goBoard, int depth, bool isMax){
  char selfChar, rivalChar;
  int count = 0;
  if(getPlayerColor() == "Dark"){
  	selfChar = 'D';
  	rivalChar = 'L';
  }
  else{
  	selfChar = 'L';
  	rivalChar = 'D';
  }

  if(goBoard.getWinner() == selfChar)
    return 10;

  if(goBoard.getWinner() == rivalChar)
    return -10;
  
  //tie
  if(count == (goBoard.getSize() * goBoard.getSize()))
     return 0;

  if (isMax){
    int best = -1000;
    
    // Traverse all cells
    for (int i = 0; i < goBoard.getSize(); i++){
      for (int j = 0; j < goBoard.getSize(); j++){
	// Check if cell is empty
        if(!goBoard.emptySpace(i,j))
		continue;
	    // Make the move
	    goBoard.setGoTemp(selfChar, i, j);
	    
	    // Call minimax recursively and choose
	    // the maximum value
	    best = max( best,
			minimax(&goBoard, depth+1, !isMax) );
	    
	    // Undo the move
	    goBoard.setBack(i, j);
	    count++;
      }
    }
    return best;
  }
  else{
    int best = 1000;
    
    // Traverse all cells
    for (int i = 0; i < goBoard.getSize(); i++){
      for (int j = 0; j < goBoard.getSize(); j++){
	// Check if cell is empty
        if(!goBoard.emptySpace(i,j))
		continue;
	    // Make the move
	    goBoard.setGoTemp(rivalChar, i, j);
	    
	    // Call minimax recursively and choose
	    // the maximum value
	    best = min( best,
			minimax(&goBoard, depth+1, !isMax) );
	    
	    // Undo the move
	    goBoard.setBack(i, j);
	    count++;
      }
    }
    return best;
  }
}

void ComputerPlayer::decision2(GoBoard &goBoard, int &iOpt, int &jOpt){
  char selfChar;
    //, rivalChar;

  if(getPlayerColor() == "Dark"){
  	selfChar = 'D';
  	//rivalChar = 'L';
  }
  else{
  	selfChar = 'L';
  	//rivalChar = 'D';
  }
  

  int bestVal = -1000;
  int maxVali = -1,  maxValj = -1;
  //  iOpt = -1;
  // jOpt = -1;
  
  // Traverse all cells, evalutae minimax function for
  // all empty cells. And return the cell with optimal
  // value.
  for (int i = 0; i < goBoard.getSize(); i++){
    for (int j = 0; j < goBoard.getSize(); j++){
      // Check if celll is empty
      if(!goBoard.emptySpace(i,j))
		continue;
	// Make the move
      goBoard.setGoTemp(selfChar, i, j);
	
	// compute evaluation function for this
	// move.
      int moveVal = minimax(&goBoard, 0, false);
	
	// Undo the move
      goBoard.setBack(i, j);
      
	// If the value of the current move is
	// more than the best value, then update
	// best/
      if (moveVal > bestVal){
	maxVali = i;
	maxValj = j;
	bestVal = moveVal;
      }
    }
  }

  iOpt = maxVali;
  jOpt = maxValj;
}
*/
