#include "dominion.h"

#define DIE_ON_ASSERT 0

int massert(int b, char* s) {
  if (!b) {
    printf ("ASSERTION FAILURE: %s\n", s);
    if (DIE_ON_ASSERT) {
      exit(1);
    }
  }
}

int main () {
  struct gameState G;
  int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo,
	       outpost};
  
  initializeGame(2, k, 3, &G);

  G.hand[0][0] = minion;
  int coins = G.coins;
  playCard(0, 1, 0, 0, &G);
  massert (G.coins == coins + 2, "Coins incorrect"); 
  printf ("%d, %d\n", G.coins, coins);
  printf ("%d\n", G.handCount[0]);
}
