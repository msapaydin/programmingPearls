#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//#define JUGGLE_OUR_SOLUTION
//#define JUGGLE_OUR_SOLUTION
#define RECURSIVE
//#define REVERSE


char *rotate(char*, int, int);


int main(int argc, char** argv)
{
    char arr[] = "abcdefgh";

    printf("%s\n", rotate(arr, strlen(arr), atoi(argv[1])));

    return 0;
}


#ifdef JUGGLE_OUR_SOLUTION
char *rotate(char* x, int n, int rotdist)
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
int gcd(int i, int j)
{
    while (i != j)
        if (i > j)
            i -= j;
        else
            j -= i;

    return i;
}

char *rotate(char* x, int n, int rotdist)
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

#ifdef RECURSIVE
void swap(char *arr, int start_a, int start_b, int length)
{
    char t;

    for (int i = 0; i < length; i++)
    {
        t = arr[start_a + i];
        arr[start_a + i] = arr[start_b + i];
        arr[start_b + i] = t;
    }
}

void recursive_swap(char *arr, int n, int start, int size_a)
{
    printf("n=%i start=%i size_a=%i\n", n, start, size_a);
    for (int i = start; i <= start + n - 1; i++)
        printf("%c", arr[i]);
    printf("\n");

    if (size_a <= n - size_a)
        swap(arr, start, n - size_a + start, size_a);
    else
        swap(arr, start, size_a + start, n - size_a);

    for (int i = start; i <= start + n - 1; i++)
        printf("%c", arr[i]);
    printf("\n");

    if (n != 2 * size_a)
    {
        if (size_a <= n - size_a)
            recursive_swap(arr, n - size_a, start, size_a);
        else
            recursive_swap(arr, size_a, start + n - size_a, 2 * size_a - n);
    }
}

char *rotate(char* x, int n, int rotdist)
{
    if (rotdist == 0 || rotdist == n)
        return x;

    recursive_swap(x, n, 0, ((rotdist % n) + n) % n);

    return x;
}
#endif

#ifdef REVERSE
void swap(char *arr, int i, int j)
{
    if (i == j)
        return;

    char t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
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

char *rotate(char* x, int n, int rotdist)
{
    reverse(x, 0, rotdist-1);
    reverse(x, rotdist, n-1);
    reverse(x, 0, n-1);

    return x;
}
#endif
