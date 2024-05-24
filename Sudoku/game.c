#include <stdio.h>


#include "boardActions.h"
#include "presentBoard.h"
#include "square.h"
#include "askUser.h"


int gamePlay(int*** board, int boardSize) {


	emptyRandomBoardNumbers(board, boardSize, 1);
	printBoard(*board, boardSize);
	changeArrayValue(board, boardSize);
	int ifVictory = victoryConditions(board, boardSize);
	if(ifVictory == 1)

	return ifVictory;

}
