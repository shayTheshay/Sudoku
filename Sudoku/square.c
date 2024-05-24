#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdlib.h> 
#include <malloc.h>
#include <time.h>

#include "square.h"

void createBoard(int*** myNumbers, int length) {
    *myNumbers = (int**)malloc(sizeof(int*) * length);
    if ((*myNumbers) != NULL) {
        for (int i = 0; i < length; i++) {
            (*myNumbers)[i] = (int*)malloc(sizeof(int) * length);
            if (((*myNumbers)[i]) != NULL)
                for (int j = 0; j < length; j++) {
                    (*myNumbers)[i][j] = 0; // or any other logic to initialize the values
                }
            else {
                printf("Problem occured not enough memory\n");
                for (int j = 0; j < i; j++)
                    free((*myNumbers)[i]);
                free((*myNumbers));
                break;
            }
        }
    }
    else
        printf("Problem occured not enough memory\n");
}


int** staticToDynamic(int *arr, int length) {
    int ** arrToReturn = (int**)calloc(length, sizeof(int*));
    if (arrToReturn != NULL) {
        for (int i = 0; i < length; i++) {
            (arrToReturn)[i] = (int*)calloc(length, sizeof(int));
            if (((arrToReturn)[i]) != NULL)
                for (int j = 0; j < length; j++) {
                    (arrToReturn)[i][j] = *((arr + i * length) + j); // or any other logic to initialize the values
                }
            else {
                printf("Problem occured not enough memory\n");
                for (int j = 0; j < i; j++)
                    free((arrToReturn)[i]);
                free((arrToReturn));
                break;
            }
        }
    }
    else 
        printf("Problem occured not enough memory\n");

    return arrToReturn;
}

int** copyDynamicArray(int** array, int length) {
    int** arrToReturn = (int**)calloc(length, sizeof(int*));
    if (arrToReturn != NULL) {
        for (int i = 0; i < length; i++) {
            (arrToReturn)[i] = (int*)calloc(length, sizeof(int));
            if (((arrToReturn)[i]) != NULL)
                for (int j = 0; j < length; j++) {
                    (arrToReturn)[i][j] = array[i][j]; // or any other logic to initialize the values
                }
            else {
                printf("Problem occured not enough memory\n");
                for (int j = 0; j < i; j++)
                    free((arrToReturn)[i]);
                free((arrToReturn));
                break;
            }
        }
    }
    else
        printf("Problem occured not enough memory\n");
    return arrToReturn;
}



void freeMultiDimenstionArr(int*** array, int length) {
    for (int i = 0; i < length; i++) 
        free((*array)[i]);
    free(*array);
}


void blankNumbersExapmpleEasy(int*** array, int length) {
    srand(time(NULL));

    int randomPairs = 0;//(length * 2) + 3  + rand() % 6;
    int randomNumberOne, randomNumberTwo;

    for (int i = 0; i < randomPairs; i++) {
        randomNumberOne = rand() % 9;
        randomNumberTwo = rand() % 9;
        
        if ((*array)[randomNumberOne][randomNumberTwo] == 0 || (*array)[randomNumberTwo][randomNumberOne] == 0) {
            do {
                randomNumberOne = rand() % 9;
                randomNumberTwo = rand() % 9;
            } while ((*array)[randomNumberOne][randomNumberTwo] == 0 || (*array)[randomNumberTwo][randomNumberOne] == 0);
        }
        (*array)[randomNumberOne][randomNumberTwo] = 0;
        //(*array)[randomNumberTwo][randomNumberOne] = 0;
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