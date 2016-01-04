#include "dominion.h"
#include <assert.h>

int main () {

  struct gameState G;

  int k[10] = {smithy, gardens, adventurer, minion, feast, village, sea_hag, treasure_map, baron, great_hall};

  int r, i;

  for (i = 0; i < 8; i++) {
    r = initializeGame(i, k, 2, &G);
    if ((i >= 2) && (i <= 4)) {
      if (i == 2) {
	assert(G.supplyCount[estate] == 8);
	assert(G.supplyCount[duchy] == 8);
	assert(G.supplyCount[province] == 8);
	assert(G.supplyCount[gardens] == 8);
	assert(G.supplyCount[great_hall] == 8);
      } else {
	assert(G.supplyCount[estate] == 12);
	assert(G.supplyCount[duchy] == 12);
	assert(G.supplyCount[province] == 12);
	assert(G.supplyCount[gardens] == 12);
	assert(G.supplyCount[great_hall] == 12);
      }
      assert (r == 0);
    } else {
      assert (r != 0);
    }
  }

  printf("TEST SUCCESSFULLY COMPLETED.\n");
}
