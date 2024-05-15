#pragma once
#include <stdbool.h>

int changeSquareBoardVal(int*** arr, int row, char column, int value);

int checkValueInRangeSquare(int row, char* column, int value, int length);

int NotBaseValue(int** baseArray, int row, char column); //Check if the values cannot be changed because it was inroduced in the beginning as a base values of the Board

void randomizeBoardValues(int** board, int boardSize);

void createBoardValues(int** board, int boardSize, int runnerNumber, int row, int column);

bool isValidValues(int** board, int boardSize, int row, int col, int num, int sqrtNum);