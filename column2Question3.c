#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//#define JUGGLE_OUR_SOLUTION
//#define JUGGLE_OUR_SOLUTION
#define REVERSE


int gcd(int, int);
void reverse(char* arr, int, int);
void swap(char*, int, int);
char *rotate(char*, int, int);


int main(int argc, char** argv)
{
    char arr[] = "abcdefgh";

    printf("%s\n", rotate(arr, strlen(arr), atoi(argv[1])));

    return 0;
}


int gcd(int i, int j)
{
    while (i != j)
        if (i > j)
            i -= j;
        else
            j -= i;

    return i;
}

void reverse(char *arr, int start, int end)
{
    int i = start;
    int j = end;

    if (start >= end)
        return;

    while (i < j)
        swap(arr, i++, j--);
}

void swap(char *arr, int i, int j)
{
    if (i == j)
        return;

    char t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}


char *rotate(char* x, int n, int rotdist)
#ifdef JUGGLE_OUR_SOLUTION
{
    if (!rotdist)
        return;

    int d = 0;

    char t = x[0];

    for (int i = 0; i < n; i++)
    {
        if ((((i * rotdist) + d) % n == d) && (i > 0))
        {
            x[n - rotdist + d] = t;
            t = x[++d];
        }

        x[((i * rotdist) + d) % n] = x[(((i + 1) * rotdist) + d) % n];
    }

    x[n - rotdist + d] = t;
}
#endif

#ifdef JUGGLE_BOOK_SOLUTION
{
    for (int i = 0; i < gcd(rotdist, n); i++)
    {
        char t = x[i];
        int j = i;

        while (1)
        {
            int k = j + rotdist;
            if (k >= n)
                k -= n;
            if (k == i)
                break;
            x[j] = x[k];
            j = k;
        }
        x[j] = t;
    }

    return x;
}
#endif

#ifdef REVERSE
{
    reverse(x, 0, rotdist-1);
    reverse(x, rotdist, n-1);
    reverse(x, 0, n-1);

    return x;
}
#endif
