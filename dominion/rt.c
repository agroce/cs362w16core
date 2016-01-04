#include "rngs.h"
#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char** argv) {
  if (argc < 3) {
    printf ("Not enough inputs:  seed target\n");
  }

  SelectStream(1);
  PutSeed((long)atoi(argv[1]));
  
  int done = 0;
  int c = 1000000000;
  
  while (!done) {
    c = floor(Random() * 1000000000);
    //    if (c % 100000 == 0) {
    //      printf ("c = %d\n", c);
    //    }
    if (c == atoi(argv[2])) {
      printf ("Found the bug!\n");
      done = 1;
    }
  }
}

