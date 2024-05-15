#include <stdio.h>


#include "askUser.h"
#include "presentBoard.h"
#include "square.h"
#include "boardActions.h"
#include "messages.h"

#define BOARD_SIZE 9

void gameDetails() {

	printf("Hi user;) this is the great sudoku game!\n");
	printf("Before we are going to play do you want a recap of the rules? type:\"Yes\" or \"NO\"\n");
	char recapYesNo[5];
	if (scanf_s("%s", recapYesNo, (unsigned)sizeof(recapYesNo)) == 1) {
		if (strcmp(recapYesNo, "Yes") == 0) {
			printf("You have entered Yes, let's look at the rules!\n");
			rulesExplained();
		}
		else if (strcmp(recapYesNo, "No") == 0) {
			printf("Okay! let's head to playing\n");

		}
		else {
			printf("You did not enter yes or no, I will put the rules anyway\n");
			rulesExplained();
		}
	}


}


void rulesExplained() {

	printf("So you want to review the rules? here is an example of 9x9 sudoku board with numbers\n");
	wait(3);
	printf("\nHere is an example of a 9x9 completed board\n");
	const int exampleArray[BOARD_SIZE][BOARD_SIZE] = { 
		{4, 3, 5, 2, 6, 9, 7, 8, 1},
		{6, 8, 2, 5, 7, 1, 4, 9, 3},
		{1, 9, 7, 8, 3, 4, 5, 6, 2},
		{8, 2, 6, 1, 9, 5, 3, 4 ,7},
		{3, 7, 4, 6, 8, 2, 9, 1, 5},
		{9, 5, 1, 7, 4, 3, 6 ,2 ,8},
		{5, 1, 9, 3, 2, 6, 8, 7 ,4},
		{2, 4, 8, 9, 5, 7, 1, 3 ,6},
		{7, 6, 3, 4, 1, 8, 2 ,5, 9} };

	int** exampleChosen = staticToDynamic(exampleArray, BOARD_SIZE);
	printBoard(exampleChosen, BOARD_SIZE);


	printf("This board is completed, take notice of the little squares, of 3x3 each one.\nLike the box of number 1-3 A-C.\n");
	wait(10);
	printf("\nFirst rule, each square contains all the numbers 1 - 9 must contain only once,\nplease take a few seconds to make sure that each mini square contains just that.\n");
	wait(7);
	printf("\nSecond rule, each column and row should have the full 1-9 numbers with again no reaccurences.\n");
	wait(7);
	printf("\nThird, each number that was initially marked in the original array cannot be changed.\n");
	wait(7);
	printf("\nNow let's see a live game example\n");
	wait(7);
	printf("Look at this board, it has some missing numbers! it is not complete.\n");
	
	blankNumbersExapmpleEasy(&exampleChosen, BOARD_SIZE);
	printBoard(exampleChosen, BOARD_SIZE);
	wait(5);
	printf("\nNow after we look at the board we need to fill it.\nTo fill the board type the letter you want for rows, and then the number for the column number.\n");
	printf("Now press ENTER and then write what number to what number you want to change, here is an example\n");
	wait(5);
	printf("\nPlease enter the place you want to change\nA4\nNow enter the number you want to change into\n5\n");
	
	wait(5);
	printf("\nNow let's complete this sudoku just for the example! Follow the what is said on the explanation\n");
	
	changeArrayValue(&exampleChosen, BOARD_SIZE);
	int  ifVictory = victoryConditions(exampleChosen, BOARD_SIZE);
	UserVictoryFailMessageTutorial(ifVictory);

	printf("\n");
	freeMultiDimenstionArr(&exampleChosen, BOARD_SIZE);
}

int numberOfTiles() { //Choose on which number of tiles to play by user.
	printf("On what number of tiles do you want to play? for now choose 9 If you don't type 9 it will be chosen automaticaly\n");
	int numOfTiles = 9;
	//scanf_s("%d", &numOfTiles); //When you want To play un - comment This message
	if (numOfTiles == NULL)
		numOfTiles = 9;
	else 
		switch (numOfTiles) {
			//case 4:
			case 9:
			//case 16:

				break;
			default:
				numOfTiles = 9;
				break;
		}
	return numOfTiles;
}


int requestPlaceToChange(int *row, char *column) { //Request the values that are needed in order to change a value in the board.
	int checkValueCorrect = 1;
	int val = 0;
	printf("Please enter the row(number): ");
	checkValueCorrect *= scanf_s("%d", row);

	while (getchar() != '\n');


	printf("Please enter the Letter(column): ");
	checkValueCorrect *= scanf_s(" %c", column, sizeof(char));

	while (getchar() != '\n');


	printf("Please enter the value: ");
	checkValueCorrect *= scanf_s("%d", &val);
	if (checkValueCorrect == 0)
		val = -1;
 
	return val;
}

void changeArrayValue(int*** array, int length) { //Responsible for all the functions of checking values and activating backend to change the values of the array.

	int countEmpty = 0;
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			if ((*array)[i][j] == 0)
				countEmpty++;
	
	int** baseArray = copyDynamicArray(*array, length);
	int row = 0;
	while (countEmpty != 0) {
		char column = NULL;
		row = 0;
		int value = requestPlaceToChange(&row, &column); //Ask the user for input of the column row and value to input in the array.
		row = row - 1;
		int checkChangeType = 0;
		if (checkValueInRangeSquare(row, &column, value, length)) //Check Values are in range of length, The value given does not interfere with the base of the board and that the row&&column added number does not create an obvious fail
			if (NotBaseValue(baseArray, row, column)) {//Check that the values are not trying to change the base board values
				int valPrev = (*array)[column - 'A'][row];
				if (changeSquareBoardVal(array, row, column, value)) {//change the values in the array	
					checkChangeType = value * valPrev;
					switch (checkChangeType) { //Check if you write a value, delete a value, or change a value you already changed in order to know when the board is full in order to proceed 
					case 0://Needed to change
						if (valPrev != 0 && value == 0)
							countEmpty++;
						else
							if (valPrev == 0 && value != 0) 
								countEmpty--;
						break;
					default:

						break;
					}
				}
				else
					printf("\nThere was a problem changing this value\n");
			}
			else
				printf("\n%d%c cannot be changed, it was at the base board\n", row + 1, column);
		else
			printf("\nThe value was not changed because one of the values was not correct, please check again!\n");
		printBoard(*array, length);

	}

	
	freeMultiDimenstionArr(&baseArray, length);

}


