#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#include "square.h"
#include "askUser.h"
#include "presentBoard.h"
#include "game.h"
#include "boardActions.h"


void main() {
	int score = 0;

	while (1) {
		
		//gameDetails();
		
		int boardSize = 9;//numberOfTiles();
		int** myBoard = NULL;
		createBoard(&myBoard, boardSize);

		randomizeBoardValues(&myBoard, boardSize);
		printBoard(myBoard, boardSize);

		printf("if you reached here it is not a good sign");
		score += gamePlay(&myBoard, boardSize);
		freeMultiDimenstionArr(&myBoard, boardSize);
	}
}