#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

int main (int argc, char** argv) {

  struct gameState G;
  
  int i;

  int start = -1;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
  
  memset(&G, 'z', sizeof(struct gameState));
  
  initializeGame(4, k, atoi(argv[1]), &G);
  
  printf ("Rough guide to locations in structure:\n");
  printf ("0: numPlayers\n");
  printf ("%ld: supplyCount[0]\n", ((long)&(G.supplyCount[0]))-((long)&G));
  printf ("%ld: embargoTokens[0]\n", ((long)&(G.embargoTokens[0]))-((long)&G));
  printf ("%ld: hand[0][0]\n", ((long)&(G.hand[0][0]))-(long)(&G));
  printf ("%ld: deck[0][0]\n", ((long)&(G.deck[0][0]))-(long)(&G));
  printf ("%ld: discard[0][0]\n", ((long)&(G.discard[0][0]))-(long)(&G));
  printf ("%ld: playerCards[0]\n", ((long)&(G.playedCards[0]))-(long)(&G));

  for (i = 0; i < sizeof(struct gameState); i++) {
    if (((char*)&G)[i] == 'z') {
      if (start == -1) {
	start = i;
      }
    } else{
      if (start != -1) {
	if (start == (i-1)) {
	  printf ("Byte %d uninitialized.\n", start);
	} else {
	  printf ("Bytes %d-%d uninitialized.\n", start, i-1);
	}
	start = -1;
      }
    }
  }

  if (start != -1) {
    if (start == (i-1)) {
      printf ("Byte %d uninitialized.\n", start);
    } else {
      printf ("Bytes %d-%d uninitialized.\n", start, i-1);
    }
  }

  return 0;
}
