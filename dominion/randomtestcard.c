#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1300

//This randomly tests smithy

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Card Test for Smithy\n");

	  /*
										--- Author's Note ---
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.
	  (I just put this on the second file as well)

	  This program wouldn't work without the printouts, oddly enough.
	  */

	  for (i = 0; i < MAX_TESTS; i++) {

		  
		 players = rand() % 4;
		 seed = rand();		//pick random seed
		
		 initializeGame(players, k, seed, &state);	//initialize Gamestate

		  //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		  		  	  		  		  printf("%d\n", i);


		  cardEffect(smithy, 1, 1, 1, &state);		//Run adventurer card

		  printf("%dB\n", i);
	  }


	   for (i = 0; i < MAX_TESTS; i++) {

		   
	  printf("PRE2\n");

	  initializeGame(players, k, seed, &stat);	//initialize Gamestate

	printf("POST\n");
		
		  //Initiate valid state variables
		  stat.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  stat.discardCount[player] = rand() % MAX_DECK;
		  stat.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = stat.handCount[player];
		  deckCount = stat.deckCount[player];

   		  printf("%d\n", i);


		  cardEffect(smithy, 1, 1, 1, &stat);		//Run adventurer card

		  		  printf("%dB\n", i);

	  }


	   for (i = 0; i < MAX_TESTS; i++) {


		   	   	  printf("PRE2\n");


 	  initializeGame(players, k, seed, &sta);	//initialize Gamestate

	  	printf("POST2\n");

		  //Initiate valid state variables
		  sta.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  sta.discardCount[player] = rand() % MAX_DECK;
		  sta.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = sta.handCount[player];
		  deckCount = sta.deckCount[player];

		  printf("%d\n", i);

		  cardEffect(smithy, 1, 1, 1, &sta);		//Run adventurer card

		 printf("%dB\n", i);

	  }


	  printf("Tests Complete\n");

	  return 0;
}
