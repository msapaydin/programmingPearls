#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <set>

using namespace std;

const int n = 500000;

int main() {

  const clock_t begin_time = clock();

  set<int> S;

  set<int>::iterator j;

  unsigned int val = 0;
  
  string line;
  ifstream myfile ("example3.txt");

  if (myfile.is_open())
    {
      while (getline (myfile,line) )
	{
	  int value = atoi(line.c_str());
	  S.insert(value);
	}
      myfile.close();
    }

  else cout << "Unable to open file";

  for (j = S.begin(); j != S.end(); j++)
    cout << *j << " ";
  

  cout << endl;



  std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

  return 0;

} 
