#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

const int n = 500000;

int a[n];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main() {

  const clock_t begin_time = clock();

  unsigned int val = 0;
  int i = 0;
  
  string line;
  ifstream myfile ("example3.txt");
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  int value = atoi(line.c_str());
	  a[i] = value;
	  i++;
	}
      myfile.close();
    }

  else cout << "Unable to open file";

  qsort(a, n, sizeof(int), compare);
  
  for (unsigned int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;


  // do something
  std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

  return 0;

} 
