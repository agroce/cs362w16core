int binsearch(int a[], int n, int x) {
  // returns index of item if found, -1 if not found
  // if duplicates, can return any index a[return value] == x
  
  int l, u, m;
  l = 0;
  u = n-1;
  while (l < u) {
    m = (l+u)/2;
    printf ("STATE: l, u, m: %d, %d, %d\n", l, u, m);
    if (a[m] == x) {
      return m;
    } else if (a[m] < x) {
      l = m+1;
    } else {
      u = m-1;
    }

  }
  
  return -1;
}

#define ITEMS 10
#define MAXITEM 10

int nondet_int();

int main () {
  int a[ITEMS];
  int i;
  for (i = 0; i < ITEMS; i++) {
    a[i] = nondet_int();
    printf ("STATE: a[%d] = %d\n", i, a[i]);
    __CPROVER_assume (a[i] >= 0); 
    __CPROVER_assume (a[i] <= MAXITEM);
    __CPROVER_assume ((i == 0) || (a[i] >= a[i-1]));
  }

  int s = nondet_int(); 
  printf ("STATE: s = %d\n", s);
  int r = binsearch(a, ITEMS, s);
  printf ("STATE: r = %d\n", r);
  assert ((r == -1) || (a[r] == s));
}
