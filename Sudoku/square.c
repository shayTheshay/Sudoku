#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdlib.h> 
#include <malloc.h>
#include <time.h>

#include "square.h"

void createBoard(int*** myNumbers, int length) {
    *myNumbers = (int**)malloc(sizeof(int*) * length);
    if (NULL == *myNumbers) {
        printf("Problem occured not enough memory\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        (*myNumbers)[i] = (int*)malloc(sizeof(int) * length);
        if (NULL != ((*myNumbers)[i]))
            for (int j = 0; j < length; j++) {
                (*myNumbers)[i][j] = 0; // or any other logic to initialize the values
            }
        else {
            printf("Problem occured not enough memory\n");
            for (int j = 0; j < i; j++)
                free((*myNumbers)[i]);
            free(*myNumbers);
            return;
        }
    }
}


int** staticArrayToDynamic(int *arr, int length) {
    int ** arrToReturn = (int**)calloc(length, sizeof(int*));
    if (NULL == arrToReturn) {
        printf("Problem occured not enough memory\n");
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        arrToReturn[i] = (int*)calloc(length, sizeof(int));
        if ((arrToReturn[i]) != NULL)
            for (int j = 0; j < length; j++) {
                arrToReturn[i][j] = *((arr + i * length) + j); // or any other logic to initialize the values
            }
        else {
            printf("Problem occured not enough memory\n");
            for (int j = 0; j < i; j++)
                free(arrToReturn[i]);
            free(arrToReturn);
            arrToReturn = NULL;
            break;
        }
    }
    return arrToReturn;
}

int** copyDynamicArray(int** array, int length) {
    int** arrToReturn = (int**)calloc(length, sizeof(int*));
    if (NULL == arrToReturn) {
        printf("Problem occured not enough memory\n");
        return NULL;
    }
    
    for (int i = 0; i < length; i++) {
        arrToReturn[i] = (int*)calloc(length, sizeof(int));
        if (NULL != arrToReturn[i])
            for (int j = 0; j < length; j++) {
                arrToReturn[i][j] = array[i][j]; // or any other logic to initialize the values
            }
        else {
            printf("Problem occured not enough memory\n");
            for (int j = 0; j < i; j++)
                free(arrToReturn[i]);
            free(arrToReturn);
            arrToReturn = NULL;
            break;
        }
    }

    return arrToReturn;
}



void freeMultiDimenstionArr(int*** array, int length) {
    for (int i = 0; i < length; i++) 
        free((*array)[i]);
    free(*array);
}


void emptyRandomBoardNumbers(int*** array, int length, int difficulty) {// Needed is order to check if all the numbers are getting blanked*******************
    srand(time(NULL));
    int numOfRandomPairs = 0;
    if (0 == difficulty)
        numOfRandomPairs = length;
    else
        numOfRandomPairs = length * length - (length * length)/4 - 3;
    
    
    int randomNumberRow, randomNumberColumn;
    
    for (int i = 0; i < numOfRandomPairs; i++) 
    {
        randomNumberRow = rand() % length;
        randomNumberColumn = rand() % length;
        
        if ((*array)[randomNumberRow][randomNumberColumn] == 0 ) {
            do {
                randomNumberRow = rand() % length;
                randomNumberColumn = rand() % length;
            } while ((*array)[randomNumberRow][randomNumberColumn] == 0 );
        }
        (*array)[randomNumberRow][randomNumberColumn] = 0;

    }
}


void wait(double seconds)
{
    time_t start = clock();
    while ((clock() - start) < seconds * CLOCKS_PER_SEC)
    {
        /* do nothing */
    }
}


int victoryConditions(int** array, int length) {
    int rowsCheck, columnsCheck, squaresCheck;
    int sumForVictory = 0;
    
    for (int i = 1; i <= length; i++)
        sumForVictory += i;

    rowsCheck = checkRows(sumForVictory, array, length);
    columnsCheck = checkColumns(sumForVictory, array, length);
    squaresCheck = checkRows(sumForVictory, array, length);

    if (0 == rowsCheck && 0 == columnsCheck && 0 == squaresCheck)
        return 1;
    else
        return 0;
}

int checkRows(int sumRow, int** array, int length) {
    int copySum = 0, errorFind = 0;
    for (int i = 0; i < length; i++) {
        copySum = sumRow;
        for (int j = 0; j < length; j++) 
            copySum -= array[i][j];

        if (copySum != 0)
            errorFind++;

    }

    return errorFind;
}

int checkColumns(int sumColumn, int** array, int length) { 
    int copySum = 0, errorFind = 0;
    for (int i = 0; i < length; i++) {
        copySum = sumColumn;
        for (int j = 0; j < length; j++)
            copySum -= (array)[j][i];

        if (copySum != 0)
            errorFind++;

    }

    return errorFind;

}


int checkSquares(int sumSquare, int** array, int length) {
    int sqrtNum = (int)sqrt(length);
    
    int copySum = 0, errorFind = 0;

    for (int place = 0; place < sqrtNum; place++)
        for (int placeDiagonal = 0; placeDiagonal < sqrtNum; placeDiagonal++) {
            copySum = sumSquare;
            for (int i = place + place * sqrtNum; i < sqrtNum + place * sqrtNum; i++)
                for (int j = placeDiagonal + placeDiagonal * sqrtNum; j < sqrtNum + placeDiagonal * sqrtNum; j++) {
                    copySum -= (array)[j][i];
                }
            if (copySum != 0)
                errorFind++;
        }

    return errorFind;
}




int checkRowOfPlacement(int row, int** array, int boardSize, int numCheckedOnRow) {
    int errorFind = 1;
    for (int j = 0; j < boardSize; j++) {
        //printf("\nThe value of row column and number are: (%d, %d) = %d \n", row, j, array[row][j]);
        if (array[row][j] == numCheckedOnRow) {
            errorFind = 0;
            break;
        }
    }

    return errorFind;
}

int checkColumnOfPlacement(int column, int** array, int boardSize, int numCheckedOnColumn) {
    int errorFind = 1;
    for (int i = 0; i < boardSize; i++) {

        //printf("\nThe value of row column and number are: (%d, %d) = %d \n", i, column, array[i][column]);
        if (array[i][column] == numCheckedOnColumn) {
            errorFind = 0;
            break;
        }
    }

    return errorFind;
}

