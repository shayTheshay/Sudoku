#include <stdio.h>


#include "messages.h"

void UserVictoryFailMessageTutorial(int victoryChecker) {
	if (victoryChecker == 0)
		printf("\nCongratulations! you passed the tutorial!!!\n");
	else
		printf("\nYou have had a error/s but you completed the tutorial congratulations!\n");
}



