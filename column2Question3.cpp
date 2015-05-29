#include <string.h>
#include <iostream>
using namespace std;

void rotate (char* str, int n, int i) {
  int numRotated = 0;
  int index = n-1;
  char tmp1,tmp2;
  
  
  while (numRotated < n) {
    //start rotating str[nu]
    tmp1 = str[index];
    while ((numRotated < n)) {
      
      tmp2 = str[((index-i) % n +n)%n];
      str[((index-i)%n + n)%n] = tmp1;
      cout << "index - i= " << (index - i) % n << " tmp1 = " << tmp1 << endl;
      tmp1 = tmp2;
      index -= i;
      if (index < 0)
	index += n;
      cout << "index = " << index << endl;
      numRotated++;
    }
  }
  //strcpy(str,"defghabc");
}

int main(void) {

  int i = 3;
  int n = 8;
  char  str [n];
  strcpy(str,"abcdefgh");
  rotate(str, n, i);
  cout << str << endl;
}
