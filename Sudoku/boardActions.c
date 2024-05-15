#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <malloc.h>
#include <math.h>


#include "boardActions.h"
#include "presentBoard.h"

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

	if (value <= length && value > 0)
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

void randomizeBoardValues(int*** board, int boardSize) {//Responsible
	int runnerNumber = 1,  sqrtNum = (int)sqrt(boardSize);
	srand(time(NULL)); // To make each input a random placement

	createBoardValues(board, boardSize, 0, 0 , sqrtNum, runnerNumber);


}

void createBoardValues(int*** board, int boardSize, int row, int column, int sqrtNum, int runnerNumber) { // creating the board values that are randomized
	if (runnerNumber > boardSize)
		return;

	int numOfEmpty = 0;
	int** emptyPlaces = emptySpacesSquare(board, boardSize, row, column, sqrtNum, &numOfEmpty);





	// ******************* needs to be continued *******************



}


int** emptySpacesSquare(int** board, int boardSize, int row, int column, int sqrNum, int numOfEmpty) { // ******************* needs to be continued *******************
	
	if ( row )

	int ;
	for (int i = row; i < row + sqrNum; i++)
		for (int j = column; j < column + sqrNum; j++)
			printf("Continue code");


}