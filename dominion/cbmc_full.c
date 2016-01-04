#include "cbmc_dominion.h"

#define MAX_START_HAND 4

int main() {
  struct gameState G;

  int p;

  for (p = 0; p < MAX_PLAYERS; p++) {
    __CPROVER_assume(G.deckCount[p] >= 0);
    __CPROVER_assume(G.discardCount[p] >= 0);
    __CPROVER_assume(G.handCount[p] >= 0);
    __CPROVER_assume(G.deckCount[p] < MAX_DECK);
    __CPROVER_assume(G.discardCount[p] < MAX_DECK);
    __CPROVER_assume(G.handCount[p] < MAX_START_HAND);
  }

  __CPROVER_assume(G.numPlayers == 2);
  __CPROVER_assume(G.whoseTurn >= 0);
  __CPROVER_assume(G.whoseTurn < MAX_PLAYERS);
  __CPROVER_assume(G.playedCardCount >= 0);
  __CPROVER_assume(G.playedCardCount < (MAX_DECK)-1);

  int hp = nondet_int();

  __CPROVER_assume(hp >= 0);
  __CPROVER_assume(hp < G.handCount[G.whoseTurn]);

  __CPROVER_assume((G.hand[G.whoseTurn][hp] >= adventurer) && (G.hand[G.whoseTurn][hp] < remodel));

  int c1 = nondet_int();
  int c2 = nondet_int();
  int c3 = nondet_int();

  __CPROVER_assume(c1 >= 0); 
  __CPROVER_assume(c2 >= 0); 
  __CPROVER_assume(c3 >= 0); 
  __CPROVER_assume(c1 < G.handCount[G.whoseTurn]); 
  __CPROVER_assume(c2 < G.handCount[G.whoseTurn]); 
  __CPROVER_assume(c3 < G.handCount[G.whoseTurn]); 


  int r = playCard(hp, c1, c2, c3, &G);
}
