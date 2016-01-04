/* 	Interactive Dominion Interface
	
	Sam Heinith CS362
	1/26/2010
*/



#ifndef _INTERFACE_H
#define _INTERFACE_H



#include "dominion.h"

//Last card enum (Treasure map) card number plus one for the 0th card.
#define NUM_TOTAL_K_CARDS (treasure_map + 1)
#define NUM_K_CARDS 10
#define NUM_V_CARDS_2 8
#define NUM_V_CARDS_3or4 12
#define NUM_C_CARDS_2 10
#define NUM_C_CARDS_3 20
#define NUM_C_CARDS_4 30
#define NUM_COPPER 60
#define NUM_SILVER 40
#define NUM_GOLD 30
#define UNUSED -1
#define START_COPPER 7
#define START_ESTATE 3
#define HANDSIZE 5

#define COMPARE(string1, string2) strncmp(string1, string2, 4)
#define MAX_STRING_LENGTH 32
#define TRUE 1
#define FALSE 0

#define SUCCESS 0
#define FAILURE -1

#define MATCH 0
#define WINNER 1
#define NOT_WINNER 0

//The Game Phases
#define ACTION_PHASE 0
#define BUY_PHASE 1
#define CLEANUP_PHASE 2

#define COPPER_VALUE 1
#define SILVER_VALUE 2
#define GOLD_VALUE 3

//From Dominion List Spoiler
#define COPPER_COST 0
#define SILVER_COST 3
#define GOLD_COST 6
#define ESTATE_COST 2
#define DUCHY_COST 5
#define PROVINCE_COST 8
#define CURSE_COST 0
#define ADVENTURER_COST 6
#define COUNCIL_ROOM_COST 5
#define FEAST_COST 4
#define GARDEN_COST 4
#define MINE_COST 5
#define MONEYLENDER_COST 4
#define REMODEL_COST 4
#define SMITHY_COST 4
#define VILLAGE_COST 3
#define WOODCUTTER_COST 3
#define BARON_COST 4
#define GREAT_HALL_COST 3
#define MINION_COST 5
#define SHANTY_TOWN_COST 3
#define STEWARD_COST 3
#define TRIBUTE_COST 5
#define WISHING_WELL_COST 3
#define AMBASSADOR_COST 3
#define CUTPURSE_COST 4
#define EMBARGO_COST 2
#define OUTPOST_COST 5
#define SALVAGER_COST 4
#define SEA_HAG_COST 4
#define TREASURE_MAP_COST 4
#define ONETHOUSAND 1000


int addCardToHand(int player, int card, struct gameState *game); 

int countHandCoins(int player, struct gameState *game);


void executeBotTurn(int player, int *turnNum, struct gameState *game);

void phaseNumToName(int phase, char *name); 
void cardNumToName(int card, char *name);

int getCardCost(int card);

void printHelp(void);

void printHand(int player, struct gameState *game);

void printDeck(int player, struct gameState *game);

void printDiscard(int player, struct gameState *game);

void printPlayed(int player, struct gameState *game);

void printState(struct gameState *game);

void printSupply(struct gameState *game);

void printGameState(struct gameState *game);

void printScores(struct gameState *game);

void selectKingdomCards(int randomSeed, int kingdomCards[NUM_K_CARDS]);



#endif






