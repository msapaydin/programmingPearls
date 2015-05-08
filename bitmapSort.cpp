#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

const int n = 10000000;



//need 10 million bits
//each int is 4 bytes or 32 bits
//maybe we should use unsigned int's
unsigned int bits[n/32];

//sets the bit #bit in val.
//the bit has to be less than 32.
void setBit(unsigned int &val, unsigned int bit) {
  assert ((bit >= 0) && (bit < 32));
  val = val | (1 << bit);
}

bool getBit(unsigned int val, int bit) {
  assert ((bit >= 0) && (bit < 32));
  /*
  cout << " val = " << val << " bit number = " << bit << " bit value = " <<  ((val & (1 << bit))) << endl;
   for (int i = 0; i <= bit; i++) {
     cout << "(1 << i ) " << (1 << i ) << " "  << "val && (1 << i) " << (val & (1 << i)) << endl;
   }
   cout << endl;
  */
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
  //cout << " entryIndex = " << entryIndex << " bitIndex = " << bitIndex << endl;
  assert (entryIndex < n);
  assert (getBit(bits[entryIndex], bitIndex) == false);
  setBit(bits[entryIndex], bitIndex);
  //cout << bits[entryIndex] << endl;
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
  setBit(val, 1);
  setBit(val, 0);
  assert (val == 3);
  assert (getBit(val,0) == true);
  assert (getBit(val,1) == true);
  assert (getBit(val,2) == false);
  assert (getBit(val,3) == false);

  




  string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  //cout << line << '\n';
	  int value = atoi(line.c_str());
	  //cout << " value = " << value << endl;
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
