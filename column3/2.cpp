#include <vector>
#include <iostream>

using namespace std;

unsigned int k = 5;
int a_array[] = {0,1,2,3,4,5};
std::vector<int> a(a_array,a_array + sizeof(a_array)/sizeof(int));
int c_array[] = {0,1,2,3,4,5,6};
std::vector<int> c(c_array,c_array + sizeof(c_array)/sizeof(int));
unsigned int m = 8;

int main() {

  unsigned int i, j;
  
  
  for (i = k+1; i <= m; i++) {
    int sum = 0;
    for (j = 1; j <= k; j++) {
      sum += c[j] * a[i-j];
    }
    sum += c[k+1];
    a.push_back(sum);
  }

  for (i = 1; i < a.size(); i++) {
    cout << " i = " << i << " a[i] = " << a[i] << endl;
  }
  return 0;
}

