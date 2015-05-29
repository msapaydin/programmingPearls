#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int gcd(int, int);
void rotate(char*, int, int);


int main(int argc, char** argv)
{
    char arr[] = "abcdefgh";

    rotate(arr, strlen(arr), atoi(argv[1]));

    printf("%s\n", arr);

    return 0;
}


void rotate(char* x, int n, int rotdist)
{
    if (!rotdist)
        return;

    int d = 0;

    char t = x[0];

    for (int i = 0; i < n; i++)
    {

        if ((((i * rotdist) + d) % n == d) && (i > 0))
        {
            printf("%i\n", d);
            x[n - rotdist + d] = t;
            t = x[++d];
        }

        printf("%i > %i", ((i * rotdist) + d) % n, (((i + 1) * rotdist) + d) % n);
        printf("\n");

        x[((i * rotdist) + d) % n] = x[(((i + 1) * rotdist) + d) % n];
    }

    x[n - rotdist + d] = t;
}
