#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int compare(const int* a, const int* b);

int main () {
  struct gameState G;
  struct gameState G2;

  // Initialize G.

  memcpy (&G2, &G, sizeof(struct gameState));

  int ret = shuffle(0,&G);

  if (G.deckCount[0] > 0) {
    assert (ret != -1);
    
    qsort ((void*)(G.deck[0]), G.deckCount[0], sizeof(int), compare);
    qsort ((void*)(G2.deck[0]), G2.deckCount[0], sizeof(int), compare);    
  } else
    assert (ret == -1);

  assert(memcmp(&G, &G2, sizeof(struct gameState)) == 0);  

}
