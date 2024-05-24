#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <malloc.h>
#include <math.h>


#include "boardActions.h"
#include "presentBoard.h"
#include "square.h"

int changeSquareBoardVal(int*** arr, int row, char column, int value) {	// Changes the value of the given array 
	//remember that checkValueInRangeSquare function already checked on the values
	int valueChangable = 0;
	if ((*arr) != NULL) {
		int columNumber = column - (int)'A';
		(*arr)[columNumber][row] = value;
		valueChangable = 1;

	}
	else {
		printf("\nThere was a problem.\n");
	}


	return valueChangable;
}

int checkValueInRangeSquare(int row, char* column, int value, int length) { // Check if the values themselves are in accordance with what should be like integer or character and in the range
	//Need to check for bigger letter to smaller difference

	//Need to check for correct A to I place writing
	int okayOrNot = 0;
	//checkColumnLargeLetter(&column);
	int A = (int)'A';

	int columnCheck = (int)*column - (int)'A';

	if (value <= length && value >= 0)
		if (row >= 0 && row < length)
			if (columnCheck >= 0 && columnCheck < length)
				okayOrNot = 1;

	return okayOrNot;
}


int NotBaseValue(int** baseArray, int row, char column) { //make sure the given value does not collide with the base values
	int isEditable = 0;
	int columNumber = column - (int)'A';
	if (baseArray[columNumber][row] <= 0)
		isEditable = 1;
	return isEditable;
}

void randomizeBoardValues(int*** board, int boardSize) {
	int runnerNumber = 1,  sqrtNum = (int)sqrt(boardSize);
	
	srand(time(NULL));	// To make each input a random placement

	int buildBoardSuccess = createBoardValues(board, boardSize, 0, 0, sqrtNum, 1);

}


int createBoardValues(int*** board, int boardSize, int row, int column, int sqrNum, int numOfEmpty) { // ******************* needs to be continued *******************

	if (numOfEmpty == boardSize + 1)
		return 1;

	int* freeSpace = (int*) calloc(sizeof(int) , boardSize);
	if (freeSpace == NULL) {
		printf("Lack of memory allocated");
		return 0;
	}

	//printf("\nrow: %d\n", row);
	//printf("column: %d\n", column);

	int positionIncremented = 0;

	listOfValidPlaces(freeSpace, boardSize, board, row, column, sqrNum, numOfEmpty);
	
	//Loop that goes all over the possible places to input from the list, afterwards it checks where it came from
	int positionGood = 0;
	int checkIfGoodBoard = 0;


	while ( freeSpace[positionIncremented] != 0 ) {// Need to change the loop and check it entireley
	
		positionGood = 0;
		//function that checks for the row and column for any place that is not complient with the rules of sudoku 
		int rowRandomNumber = placementToNumber(freeSpace[positionIncremented], row, column, 1, sqrNum) + row;

		int columnRandomNumber = placementToNumber(freeSpace[positionIncremented], row, column, 0, sqrNum) + column;
		
		positionGood += checkRowOfPlacement(rowRandomNumber, *board, boardSize, numOfEmpty);
		
		positionGood += checkColumnOfPlacement(columnRandomNumber, *board, boardSize, numOfEmpty);
		checkIfGoodBoard = 0;

		if (positionGood == 2) {

			(*board)[rowRandomNumber][columnRandomNumber] = numOfEmpty;
			//Check for movement across the board, starting at (0,0)

			//If you move from Square 1 -> 2 or 2 -> 3 or 4 -> 5 or 5 -> 6 or 7 -> 8 or 8 -> 9

			if (column < boardSize - sqrNum) 
				checkIfGoodBoard = createBoardValues(board, boardSize, row, column + sqrNum, sqrNum, numOfEmpty);
			
			else if (row != boardSize - sqrNum && column == boardSize - sqrNum) // if you move from square 3 -> 4 or 6 -> 7
				checkIfGoodBoard = createBoardValues(board, boardSize, row + sqrNum, 0 , sqrNum, numOfEmpty);

			else //If you move from square 9 -> 1
				checkIfGoodBoard = createBoardValues(board, boardSize, 0, 0, sqrNum, numOfEmpty + 1);
				
			if (checkIfGoodBoard == 1) {
				free(freeSpace);
				return 1;
			}
		}
		if(positionGood == 2 && checkIfGoodBoard == 0)
			(*board)[rowRandomNumber][columnRandomNumber] = 0;

		positionIncremented++;
	}
	free(freeSpace);
	//You run out of options so now you need to go back 
	return 0;
}

void listOfValidPlaces(int* freeSpace, int boardSize, int ***board, int row, int column, int sqrNum, int numOfEmpty) {
	int placement = 0;
	for (int i = row; i < row + sqrNum; i++)
		for (int j = column; j < column + sqrNum; j++) {
			if ((*board)[i][j] == 0) {
				freeSpace[placement] = placeOnBoard(i, j, sqrNum);
				placement++;
			}
		}
	randomListOrderOfPlaces(freeSpace, boardSize);
}

int placeOnBoard(int row, int column, int sqrNum) {
	row %= sqrNum;
	column %= sqrNum;
	return row * sqrNum + column + 1;
}


void randomListOrderOfPlaces(int* freeSpace, int boardSize) {
	int endingPoint = boardSize - 1;
	while (freeSpace[endingPoint] == 0)
		endingPoint --;

	for (int i = endingPoint; i > 0; i--) {
		int j = rand() % (i + 1);
		int temp = freeSpace[i];
		freeSpace[i] = freeSpace[j];
		freeSpace[j] = temp;
	}
}




int placementToNumber(int insidePlace, int row, int column, int rowOrColumn, int sqrNum) {
	//rowOrColumn -> if it is 1 then row, if 0 then column
	int i = 0;
	int j = 0;
	
	for ( i = 0; i < sqrNum; i++)
		for (j = 0; j < sqrNum; j++) {
			insidePlace--;
			if (insidePlace == 0)
				if (rowOrColumn == 1)
					return i;
				else
					return j;
		}
}
