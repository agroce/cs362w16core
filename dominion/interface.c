/* 	Interactive Dominion Interface
	
Sam Heinith CS362
1/26/2010
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "rngs.h"
#include "interface.h"
#include "dominion.h"


void cardNumToName(int card, char *name){
  switch(card){
  case curse: strcpy(name,"Curse");
    break;
  case estate: strcpy(name,"Estate");
    break;
  case duchy: strcpy(name,"Duchy");
    break;
  case province: strcpy(name,"Province");
    break;
  case copper: strcpy(name,"Copper");
    break;
  case silver: strcpy(name,"Silver");
    break;
  case gold: strcpy(name,"Gold");
    break;
  case adventurer: strcpy(name,"Adventurer");
    break;
  case council_room: strcpy(name,"Council Room");
    break;
  case feast: strcpy(name,"Feast");
    break;
  case gardens: strcpy(name,"Gardens");
    break;
  case mine: strcpy(name,"Mine");
    break;
  case remodel: strcpy(name,"Remodel");
    break;
  case smithy: strcpy(name,"Smithy");
    break;
  case village: strcpy(name,"Village");
    break;
  case baron: strcpy(name,"Baron");
    break;
  case great_hall: strcpy(name,"Great Hall");
    break;
  case minion: strcpy(name,"Minion");
    break;
  case steward: strcpy(name,"Steward");
    break;
  case tribute: strcpy(name,"Tribute");
    break;
  case ambassador: strcpy(name,"Ambassador");
    break;
  case cutpurse: strcpy(name,"Cutpurse");
    break;
  case embargo: strcpy(name,"Embargo");
    break;
  case outpost: strcpy(name,"Outpost");
    break;
  case salvager: strcpy(name,"Salvager");
    break;
  case sea_hag: strcpy(name,"Sea Hag");
    break;
  case treasure_map: strcpy(name,"Treasure Map");
    break;

  default: strcpy(name,"?");
  }

}



int getCardCost(int card) {
  int cost;
  switch(card) {
  case curse: cost = CURSE_COST;
    break;
  case estate: cost = ESTATE_COST;
    break;
  case duchy: cost = DUCHY_COST;
    break;
  case province: cost = PROVINCE_COST;
    break;
  case copper: cost = COPPER_COST;
    break;
  case silver: cost = SILVER_COST;
    break;
  case gold: cost = GOLD_COST;
    break;
  case adventurer: cost = ADVENTURER_COST;
    break;
  case council_room: cost = COUNCIL_ROOM_COST;
    break;
  case feast: cost = FEAST_COST;
    break;
  case gardens: cost = GARDEN_COST;
    break;
  case mine:  cost = MINE_COST;
    break;
  case remodel: cost = REMODEL_COST;
    break;
  case smithy: cost = SMITHY_COST;
    break;
  case village: cost = VILLAGE_COST;
    break;
  case baron: cost = BARON_COST;
    break;
  case great_hall: cost = GREAT_HALL_COST;
    break;
  case minion: cost = MINION_COST;
    break;
  case steward: cost = STEWARD_COST;
    break;
  case tribute: cost = TRIBUTE_COST;
    break;
  case ambassador: cost = AMBASSADOR_COST;
    break;
  case cutpurse: cost = CUTPURSE_COST;
    break;
  case embargo: cost = EMBARGO_COST;
    break;
  case outpost: cost = OUTPOST_COST;
    break;
  case salvager: cost = SALVAGER_COST;
    break;
  case sea_hag: cost = SEA_HAG_COST;
    break;
  case treasure_map: cost = TREASURE_MAP_COST;
    break;
  default: cost = ONETHOUSAND;
  }
  return cost;
}






void printHand(int player, struct gameState *game) {
  int handCount = game->handCount[player];
  int handIndex;
  printf("Player %d's hand:\n", player);
  if(handCount > 0) printf("#  Card\n");
  for(handIndex = 0; handIndex < handCount; handIndex++) {
    int card = game->hand[player][handIndex];
    char name[MAX_STRING_LENGTH];
    cardNumToName(card, name);
    printf("%-2d %-13s\n", handIndex, name);
  }
  printf("\n");
}



void printDeck(int player, struct gameState *game) {
  int deckCount = game->deckCount[player];
  int deckIndex;
  printf("Player %d's deck: \n", player);
  if(deckCount > 0) printf("#  Card\n");
  for(deckIndex = 0; deckIndex < deckCount; deckIndex++) {
    int card = game->deck[player][deckIndex];
    char name[MAX_STRING_LENGTH];
    cardNumToName(card, name);
    printf("%-2d %-13s\n", deckIndex, name);
  }
  printf("\n");
}

void printPlayed(int player, struct gameState *game) {
  int playedCount = game->playedCardCount;
  int playedIndex;
  printf("Player %d's played cards: \n", player);
  if(playedCount > 0) printf("#  Card\n");
  for(playedIndex = 0; playedIndex < playedCount; playedIndex++) {
    int card = game->playedCards[playedIndex];
    char name[MAX_STRING_LENGTH];
    cardNumToName(card, name);
    printf("%-2d %-13s \n", playedIndex, name);
  }
  printf("\n");
}



void printDiscard(int player, struct gameState *game) {
  int discardCount = game->discardCount[player];
  int discardIndex;
  printf("Player %d's discard: \n", player);
  if(discardCount > 0) printf("#  Card\n");
  for(discardIndex = 0; discardIndex < discardCount; discardIndex++) {
    int card = game->discard[player][discardIndex];
    char name[MAX_STRING_LENGTH];
    cardNumToName(card, name);
    printf("%-2d %-13s \n", discardIndex, name);
  }
  printf("\n");
}




void printSupply(struct gameState *game) {
  int cardNum, cardCost, cardCount;
  char name[MAX_STRING_LENGTH];
  printf("#   Card          Cost   Copies\n");
  for(cardNum = 0; cardNum < NUM_TOTAL_K_CARDS; cardNum++){
    cardCount = game->supplyCount[cardNum];
    if(cardCount == -1) continue;
    cardNumToName(cardNum, name);
    cardCost = getCardCost(cardNum);
    printf("%-2d  %-13s %-5d  %-5d", cardNum, name, cardCost, cardCount);
    printf("\n");
  }
  printf("\n");
}


void printState(struct gameState *game) {
  int numActions = game->numActions;
  int numCoins = game->coins;
  int numBuys = game->numBuys;
  int currentPlayer = game->whoseTurn;
  int phase = game->phase;
  char phaseName[MAX_STRING_LENGTH];
  phaseNumToName(phase,phaseName);
  printf("Player %d:\n%s phase\n%d actions\n%d coins\n%d buys\n\n", currentPlayer, phaseName, numActions, numCoins, numBuys);
}

void printScores(struct gameState *game) {
  int playerNum, score[MAX_PLAYERS];
  int numPlayers = game->numPlayers;
  for(playerNum = 0; playerNum < numPlayers; playerNum++) {
    score[playerNum] = scoreFor(playerNum,game);
    printf("Player %d has a score of %d\n", playerNum, score[playerNum]);
  }
}


void printHelp(void) {
  printf("Commands are: \n\
  add [Supply Card Number] 			- add any card to your hand (teh hacks)\n\
  buy [Supply Card Number] 			- buy a card at supply position\n\
  end 			      			- end your turn\n\
  init [Number of Players] [Number of Bots] 	- initialize the game\n\
  num 			      			- print number of cards in your hand\n\
  play [Hand Index] [Choice] [Choice] [Choice]	- play a card from your hand\n\
  resign					- end the game showing the current scores\n\
  show 						- show your current hand\n\
  stat 						- show your turn's status\n\
  supp 						- show the supply\n\
  whos 			      			- whos turn\n\
  exit 			      			- exit the interface");
  printf("\n\n");

}


void phaseNumToName(int phase, char *name) {
  switch(phase){
  case ACTION_PHASE: strcpy(name,"Action");
    break;
  case BUY_PHASE: strcpy(name,"Buy");
    break;
  case CLEANUP_PHASE: strcpy(name,"Cleanup");
    break;	
  }
}


int addCardToHand(int player, int card, struct gameState *game) {
  if(card >= adventurer && card < NUM_TOTAL_K_CARDS){
    int handTop = game->handCount[player];
    game->hand[player][handTop] = card;
    game->handCount[player]++;
    return SUCCESS;
  } else {
    return FAILURE;
  }

}

void selectKingdomCards(int randomSeed, int kingCards[NUM_K_CARDS]) {
   int i, used, card, numSelected = 0;
   SelectStream(1);
	PutSeed((long)randomSeed);
 
	
  while(numSelected < NUM_K_CARDS) {
    used = FALSE;
    card = floor(Random() * NUM_TOTAL_K_CARDS);
    if(card < adventurer) continue;
    for(i = 0; i < numSelected; i++) {
      if(kingCards[i] == card) {
	used = TRUE;
	break;
      }
    }
    if(used == TRUE) continue;
    kingCards[numSelected] = card;
    numSelected++;
  }
}


int countHandCoins(int player, struct gameState *game) {
  int card, index, coinage = 0;
	
  for(index = 0; index < game->handCount[player]; index++) {
    card = game->hand[player][index];
    switch(card) {
    case copper: coinage += COPPER_VALUE;
      break;
    case silver: coinage += SILVER_VALUE;
      break;
    case gold: coinage += GOLD_VALUE;
      break;
    }
  }
  return coinage;
}


void executeBotTurn(int player, int *turnNum, struct gameState *game) {
  int coins = countHandCoins(player, game);
	
  printf("*****************Executing Bot Player %d Turn Number %d*****************\n", player, *turnNum);
  printSupply(game);	
  //sleep(1); //Thinking...
	
  if(coins >= PROVINCE_COST && supplyCount(province,game) > 0) {
    buyCard(province,game);
    printf("Player %d buys card Province\n\n", player);
  }
  else if(supplyCount(province,game) == 0 && coins >= DUCHY_COST ) {
    buyCard(duchy,game);
    printf("Player %d buys card Duchy\n\n", player);
  }
  else if(coins >= GOLD_COST && supplyCount(gold,game) > 0) {
    buyCard(gold,game);
    printf("Player %d buys card Gold\n\n", player);
  }
  else if(coins >= SILVER_COST && supplyCount(silver,game) > 0) {
    buyCard(silver,game);
    printf("Player %d buys card Silver\n\n", player);

  }

	
  if(player == (game->numPlayers -1)) (*turnNum)++;
  endTurn(game);
  if(! isGameOver(game)) {
    int currentPlayer = whoseTurn(game);
    printf("Player %d's turn number %d\n\n", currentPlayer, (*turnNum));
  }
}
