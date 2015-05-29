#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>

using namespace std;


#define N 500000
#define k 500000


//generate a random number between lowerbound and upperbound (inclusive).

int randint (int lowerbound, int upperbound) {
  int retval = lowerbound + rand() % (upperbound + 1 - lowerbound);
}

void swap (int x[], int i, int j) {
  assert (i < N);
  assert (j < N);
  int tmp = x[i];
  x[i] = x[j];
  x[j] = tmp;
}


int main() {

  srand(time(NULL));
  int x[N];
  
  for (int i = 0; i < N; i++) {
    x[i] = i;
  }

    
  for (int i = 0; i < k; i++) {
    swap(x, i, randint(i, N-1));
    cout << x[i] << endl;
  }
  
  return 0;

} 
