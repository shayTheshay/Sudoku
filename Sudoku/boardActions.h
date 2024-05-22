#pragma once
#include <stdbool.h>

int changeSquareBoardVal(int*** arr, int row, char column, int value);

int checkValueInRangeSquare(int row, char* column, int value, int length);

int NotBaseValue(int** baseArray, int row, char column); //Check if the values cannot be changed because it was inroduced in the beginning as a base values of the Board

void randomizeBoardValues(int*** board, int boardSize);

void randomListOrderOfPlaces(int* freeSpace, int boardSize);

void listOfValidPlaces(int* freeSpace, int boardSize, int*** board, int row, int column, int sqrNum, int numOfEmpty);

int createBoardValues(int*** board, int boardSize, int row, int column, int sqrNum, int numOfEmpty);

int placementToNumber(int insidePlace, int row, int column, int rowOrColumn, int sqrNum);

int placeOnBoard(int row, int column, int sqrNum);