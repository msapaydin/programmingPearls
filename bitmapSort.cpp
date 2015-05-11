#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

const int n = 10000000;



//need 10 million bits
//each int is 4 bytes or 32 bits
unsigned int bits[n/32];

//sets the bit #bit in val.
//the bit has to be less than 32.
void setBit(unsigned int &val, unsigned int bit) {
  assert ((bit >= 0) && (bit < 32));
  val = val | (1 << bit);
}

bool getBit(unsigned int val, int bit) {
  assert ((bit >= 0) && (bit < 32));
  bool retval = ((val & (1 << bit)) == 0)  ? false:true;
  return retval;
}

//sets the bit corresponding to value in the bits array.
//need to first find which entry in bits need to be set.
//the first 32 bits to 0'th element, the second 32 bits to 1'st element, and so on.
// then need to find which bit to set at the corresponding entry.

void set (unsigned int * bits, int value)
{
  unsigned int entryIndex = value / 32;
  //the above is the entry index.
  //we should then find the bit number.
  unsigned int bitIndex = value % 32;

  assert (entryIndex < n);
  assert (getBit(bits[entryIndex], bitIndex) == false);
  setBit(bits[entryIndex], bitIndex);

}

//returns true if the bit corresponding to value is set in bits array.

bool get (unsigned int * bits, int value) {
  //first find the entry that has the bit corresponding to value
  int entryIndex = value / 32;
  int bitIndex = value % 32;
  assert (entryIndex < n);
  return getBit(bits[entryIndex], bitIndex);
}

int main() {

  
  unsigned int val = 0;

  /* some test code */

  setBit(val, 1);
  setBit(val, 0);
  assert (val == 3);
  assert (getBit(val,0) == true);
  assert (getBit(val,1) == true);
  assert (getBit(val,2) == false);
  assert (getBit(val,3) == false);

  
  /* end of some test code */

  string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  int value = atoi(line.c_str());
	  set(bits, value);
	}
      myfile.close();
    }

  else cout << "Unable to open file";

  
  for (unsigned int i = 0; i < n; i++) {
    if (get(bits, i))
      cout << i << " ";
  }
  cout << endl;
  
  return 0;

} 
