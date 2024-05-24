#pragma once

void createBoard(int*** myNumbers, int length);

int** staticArrayToDynamic(int* arr, int length);

int** copyDynamicArray(int** array, int length);

void freeMultiDimenstionArr(int*** array, int length);

void wait(double seconds);

void emptyRandomBoardNumbers(int*** array, int length, int difficulty);

int victoryConditions(int** array, int length);

int checkRows(int sumVictory, int** array, int length);

int checkColumns(int sumVictory, int** array, int length);

int checkSquares(int sumVictory, int** array, int length);

int checkRowOfPlacement(int row, int** array, int boardSize, int numCheckedOnRow);

int checkColumnOfPlacement(int column, int** array, int boardSize, int numCheckedOnColumn);