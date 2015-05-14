#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

//const int n = 10000000;
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
#define k 1000000




//need 10 million bits
//each int is 4 bytes or 32 bits
int a[1 + N/BITSPERWORD];

void set(int i) {a[i >> SHIFT] |= (1 << (i & MASK)); }

int test(int i) {return a[i >> SHIFT] & (1 << (i & MASK));};

void clr (int i) {a[i >> SHIFT] &= ~(1 << (i & MASK)); }


int main() {


  int count = 0;
  srand(time(NULL));

  while (1) {
    int value = rand() % N;
    if (!test(value)) {
      set(value);
      count++;
      if (count >= k)
	break;
    }
  }


  
  for (unsigned int i = 0; i < N; i++) {
    if (test(i))
      cout << i << endl;
  }

  
  return 0;

} 
