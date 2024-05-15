#include <stdio.h>
#include <string.h>
#include <math.h>

#include "presentBoard.h"


void printBoard(int** board, int boardSize) {

	int sqrtNum = (int)sqrt(boardSize);
	printf("  ");
	for (int i = 0; i < boardSize; i++) {
		if (i != 0 && (i) % sqrtNum == 0)
			printf(" ");
		printf("   %d", (i + 1));
	}
	printf("\n   ");
	separator(boardSize);
	
	printf("-");
	printf(" ");
	printf("\n");


	for (int i = 0; i < boardSize; i++) {
		printf("%c ", (i + 65));
		
		printf("|");

		for (int j = 0; j < boardSize; j++) {
			if (board != NULL && board[i][j] != NULL && board[i][j] != 0) {
				if (j != boardSize - 1)
					printf("| %d ", board[i][j]);
				else
					printf("| %d |", board[i][j]);
			}
			else {
				if (j != boardSize - 1)
					printf("|   ");
				else
					printf("|   |");
			}
		if ( j!= 0 && (j + 1) % sqrtNum == 0 && j != boardSize - 1)
			printf("|");
		}


		printf("|");
		printf("\n");
		printf("   ");
	
		separator(boardSize);

		if (i != 0 && (i+1) % sqrtNum == 0 && i!= boardSize -1) {
			printf("-\n   ");
			separator(boardSize);
		} 

		printf("-");
		printf("\n");
	}


}


void separator(int boardSize) {
	for (int i = 0; i < boardSize; i++)
		printf("- - ");
}

