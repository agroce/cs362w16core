#include "cbmc_dominion.h"



int main() {
  struct gameState G;
  
  int r, p, i;
  int old_hc[2];
  int old_deckc[2];
  int old_discc[2];
  
  p = 0;
  old_hc[p] = G.handCount[p];
  old_deckc[p] = G.deckCount[p];
  old_discc[p] = G.discardCount[p];

  p = 1;
  old_hc[p] = G.handCount[p];
  old_deckc[p] = G.deckCount[p];
  old_discc[p] = G.discardCount[p];

  for (i = 0; i < 5; i++) {
    p = (nondet_int() == 1) ? 0 : 1;
  
    __CPROVER_assume(G.deckCount[p] >= 0);
    __CPROVER_assume(G.discardCount[p] >= 0);
    __CPROVER_assume(G.handCount[p] >= 0);
    __CPROVER_assume(G.deckCount[p] < MAX_DECK);
    __CPROVER_assume(G.discardCount[p] < MAX_DECK);
    __CPROVER_assume(G.handCount[p] < MAX_HAND);
    
    r = drawCard(p, &G);
    
    if ((old_deckc[p] + old_discc[p]) == 0) {
      assert (G.handCount[p] == old_hc[p]);
      assert ((G.discardCount[p] + G.deckCount[p]) == (old_deckc[p] + old_discc[p]));
    } else {
      assert (G.handCount[p] == (old_hc[p] + 1));
      assert ((G.discardCount[p] + G.deckCount[p]) == (old_deckc[p] + old_discc[p] - 1));
    }

    old_hc[p] = G.handCount[p];
    old_deckc[p] = G.deckCount[p];
    old_discc[p] = G.discardCount[p];
  }
}
