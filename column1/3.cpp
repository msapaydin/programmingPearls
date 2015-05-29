#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

const int n = 10000000;
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000




//need 10 million bits
//each int is 4 bytes or 32 bits
int a[1 + N/BITSPERWORD];

void set(int i) {a[i >> SHIFT] |= (1 << (i & MASK)); }

int test(int i) {return a[i >> SHIFT] & (1 << (i & MASK));};

void clr (int i) {a[i >> SHIFT] &= ~(1 << (i & MASK)); }


int main() {
    for (unsigned int i = 0; i < n; i++)
        clr(i);

    unsigned int val = 0;

    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            int value = atoi(line.c_str());
            set(value);
        }
        myfile.close();
    }

    else cout << "Unable to open file";


    for (unsigned int i = 0; i < n; i++) {
        if (test(i))
            cout << i << " ";
    }
    cout << endl;

    return 0;

}
