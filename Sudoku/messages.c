#include <stdio.h>


#include "messages.h"

void UserVictoryFailMessageTutorial(int victotyConditionsTutorial) {
	if (1 == victotyConditionsTutorial)
		printf("\nCongratulations! you passed the tutorial!!!\n");
	else
		printf("\nYou have had a error/s but you completed the tutorial congratulations!\n");
}

void UserVictoryFailMessageGame(int victoryConditionMet) {
	if (1 == victoryConditionMet) {
		printf("\nGreat job! you have finished this game successfuly\n");

	}
	else {
		printf("\nToo bad! at least you tried, maybe practice more.\n");

	}

}

