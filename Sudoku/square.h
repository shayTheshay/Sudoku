#pragma once

void createBoard(int*** myNumbers, int length);

int** staticToDynamic(int* arr, int length);

int** copyDynamicArray(int** array, int length);

void freeMultiDimenstionArr(int*** array, int length);

void wait(double seconds);

void blankNumbersExapmpleEasy(int*** array, int length);

int victoryConditions(int** array, int length);

int checkRows(int sumVictory, int** array, int length);

int checkColumns(int sumVictory, int** array, int length);

int checkSquares(int sumVictory, int** array, int length);