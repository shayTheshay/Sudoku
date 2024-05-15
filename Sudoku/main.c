#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "square.h"
#include "askUser.h"
#include "presentBoard.h"
#include "game.h"
#include "boardActions.h"


void main() {
	int score = 0;
	while (1) {
		
		gameDetails();
		
		int boardSize = numberOfTiles();
		int** myBoard = NULL;
		createBoard(&myBoard, boardSize);

		randomizeBoardValues(&myBoard, boardSize);
		printBoard(myBoard, boardSize);

		score += gamePlay(&myBoard, boardSize);



		freeMultiDimenstionArr(&myBoard, boardSize);
	}
}