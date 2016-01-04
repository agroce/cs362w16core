/* 	Interactive Dominion Interface
	Version 7
	
	Sam Heinith CS362
	Questions/Comments:
	heiniths@onid.orst.edu
	1/26/2010
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "interface.h"
#include "rngs.h"


int main2(int argc, char *argv[]) {
	//Default cards, as defined in playDom
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState g;
	initializeGame(2,k,1,&g);
	printf ("SUCCESSFUL INIT\n");
	getchar();
}

int main(int argc, char* argv[]) {
		char *add  = "add";
	char *buyC = "buy";
	char *endT = "end";
	char *exit = "exit";
	char *help = "help";
	char *init = "init";
	char *numH = "num";
	char *play = "play";
	char *resign  = "resi";
	char *show = "show";
	char *stat = "stat";
	char *supply = "supp";
	char *whos = "whos";
		
	char command[MAX_STRING_LENGTH];
	char line[MAX_STRING_LENGTH];
	char cardName[MAX_STRING_LENGTH];

	//Array to hold bot presence 
	int isBot[MAX_PLAYERS] = { 0, 0, 0, 0};

	int players[MAX_PLAYERS];
	int playerNum;
	int outcome;
	int currentPlayer;
	int gameOver = FALSE;
	int gameStarted = FALSE;
	int turnNum = 0;

	int randomSeed = atoi(argv[1]);

	//Default cards, as defined in playDom
	int kCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	struct gameState g;
	struct gameState * game = &g;

	memset(game,0,sizeof(struct gameState));
		
	if(argc != 2){
		printf("Usage: player [integer random number seed]\n");
		return EXIT_SUCCESS;
	}

	if(randomSeed <= 0){
		printf("Usage: player [integer random number seed]\n");
		return EXIT_SUCCESS;
	}	
	
	initializeGame(2,kCards,randomSeed,game);

	printf("Please enter a command or \"help\" for commands\n");
	

	while(TRUE) {
		int arg0 = UNUSED;
		int arg1 = UNUSED;
		int arg2 = UNUSED;
		int arg3 = UNUSED;

		outcome = FAILURE;
		strcpy(line,"");
		strcpy(command,"");
		strcpy(cardName,"");
		
		currentPlayer = whoseTurn(game);
		
		//If you are getting a seg fault comment this if block out
		gameOver = isGameOver(game); 		
		if(gameStarted == TRUE && gameOver == TRUE){
			printScores(game);
			getWinners(players, game);
			printf("After %d turns, the winner(s) are:\n", turnNum);
			for(playerNum = 0; playerNum < game->numPlayers; playerNum++){
				if(players[playerNum] == WINNER) printf("Player %d\n", playerNum);
			}
		for(playerNum = 0; playerNum < game->numPlayers; playerNum++){
				printHand(playerNum, game);
				printPlayed(playerNum, game);
				printDiscard(playerNum, game);
				printDeck(playerNum, game);
			}
			
			break; //Exit out of the game/while loop
		}         
		

		if(isBot[currentPlayer] == TRUE) {
				executeBotTurn(currentPlayer, &turnNum, game);
				continue;
		}
		
		printf("$ ");
		fgets(line, MAX_STRING_LENGTH, stdin);
		sscanf(line, "%s %d %d %d %d", command, &arg0, &arg1, &arg2, &arg3);


		if(COMPARE(command, add) == 0) {
			outcome = addCardToHand(currentPlayer, arg0, game);
			cardNumToName(arg0, cardName);
			printf("Player %d adds %s to their hand\n\n", currentPlayer, cardName);
		} else
		if(COMPARE(command, buyC) == 0) {
			outcome = buyCard(arg0, game);
			cardNumToName(arg0, cardName);
			if(outcome == SUCCESS){
				printf("Player %d buys card %d, %s\n\n", currentPlayer, arg0, cardName);
			} else {
				printf("Player %d cannot buy card %d, %s\n\n", currentPlayer, arg0, cardName);
			}
		} else
		if(COMPARE(command, endT) == 0) {
			if(gameStarted == TRUE) {
				if(currentPlayer == (game->numPlayers -1)) turnNum++;
				endTurn(game);
				currentPlayer = whoseTurn(game);
				printf("Player %d's turn number %d\n\n", currentPlayer, turnNum);
			}

		} else			
		if(COMPARE(command, exit) == 0) {
			break;
		} else
		if(COMPARE(command, help) == 0) {
			printHelp();
		} else
		if(COMPARE(command, init) == 0) {
			int numHuman = arg0 - arg1;
			for(playerNum = numHuman; playerNum < arg0; playerNum++) {
				isBot[playerNum] = TRUE;
			}			
	//		selectKingdomCards(randomSeed, kCards);  //Comment this out to use the default card set defined in playDom.
			outcome = initializeGame(arg0, kCards, randomSeed, game);
			printf("\n");
			if(outcome == SUCCESS){
				gameStarted = TRUE;
				currentPlayer = whoseTurn(game);
				printf("Player %d's turn number %d\n\n", currentPlayer, turnNum);
			}

		} else
		if(COMPARE(command, numH) == 0) {
			int numCards = numHandCards(game);
			printf("There are %d cards in your hand.\n", numCards);
		} else
		if(COMPARE(command, play) == 0) {
			int card = handCard(arg0,game);
			outcome = playCard(arg0, arg1, arg2, arg3, game);
			cardNumToName(card, cardName);
			if(outcome == SUCCESS){
				printf("Player %d plays %s\n\n", currentPlayer, cardName);
			} else {
				printf("Player %d cannot play card %d\n\n", currentPlayer, arg0);
			}

		} else
		if(COMPARE(command, resign) == 0) {
			endTurn(game);
			printScores(game);
			break;
		} else
		if(COMPARE(command, show) == 0) {
			if(gameStarted == FALSE) continue;
			printHand(currentPlayer, game);
			printPlayed(currentPlayer, game);
			//printDiscard(currentPlayer, game);
			//printDeck(currentPlayer, game);
		} else
		if(COMPARE(command, stat) == 0) {
			if(gameStarted == FALSE) continue;
			printState(game);
		} else
		if(COMPARE(command, supply) == 0) {
			printSupply(game);
		} else
		if(COMPARE(command, whos) == 0) {
			int playerNum =	whoseTurn(game);
			printf("Player %d's turn\n", playerNum);
		} 
    	}
	
    	return EXIT_SUCCESS;

}
