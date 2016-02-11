#include "dominion.h"
#include <assert.h>

int main() {

  // Setup

  struct gameState G;

  G.deckCount[0] = 3;
  G.deck[0][0] = copper;
  G.deck[0][1] = silver;
  G.deck[0][2] = gold;

  // Do something

  shuffle(0,&G);
  
  // Did something, now check it

  int i;

  int cardsPresent[treasure_map+1];
  cardsPresent[copper] = 0;
  cardsPresent[silver] = 0;
  cardsPresent[gold] = 0;

  for (i = 0; i < 3; i++) {
    cardsPresent[G.deck[0][i]] = 1;
  }

  assert (cardsPresent[copper] && cardsPresent[silver] && cardsPresent[gold]);
}
