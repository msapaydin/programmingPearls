#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//#define SLIDE_JUGGLE
//#define GCD_JUGGLE
//#define RECURSIVE
//#define TAIL_RECURSIVE
#define ITERATIVE
//#define REVERSE


void rotate(char*, int, int);


int main(int argc, char** argv)
{
    char arr[] = "abcdefgh";

    rotate(arr, strlen(arr), atoi(argv[1]));

    printf("%s\n", arr);

    return 0;
}


#ifdef SLIDE_JUGGLE
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
            x[n - rotdist + d] = t;
            t = x[++d];
        }

        x[((i * rotdist) + d) % n] = x[(((i + 1) * rotdist) + d) % n];
    }

    x[n - rotdist + d] = t;
}
#endif

#ifdef GCD_JUGGLE
int gcd(int i, int j)
{
    while (i != j)
        if (i > j)
            i -= j;
        else
            j -= i;

    return i;
}

void rotate(char* x, int n, int rotdist)
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
}
#endif

#ifdef RECURSIVE
void swap(char *arr, int i, int j, int m)
{
    char t;

    while (m--)
    {
        t = arr[i + m];
        arr[i + m] = arr[j + m];
        arr[j + m] = t;
    }
}

void rotate(char *x, int n, int m)
{
    if (n == m)
        return;

    if (n - m >= m)
    {
        rotate(x, n - m, m); // remove from end
        swap(x, n - (m + m), n - m, m); // swap from end
    }
    else
    {
        rotate(x + (n - m), n - (n - m), m - (n - m)); // remove from start
        swap(x, 0, n - m, n - m); // swap from start
    }
}
#endif

#ifdef TAIL_RECURSIVE
void swap(char *arr, int i, int j, int m)
{
    char t;

    while (m--)
    {
        t = arr[i + m];
        arr[i + m] = arr[j + m];
        arr[j + m] = t;
    }
}

void rotate(char *x, int n, int m)
{
    if (n == m)
        return;

    if (n - m >= m)
    {
        swap(x, 0, n - m, m);
        rotate(x, n - m, m);
    }
    else
    {
        swap(x, 0, m, n - m);
        rotate(x + (n - m), m, m - (n - m));
    }
}
#endif

#ifdef TAIL_RECURSIVE
void swap(char *arr, int length, int start_a, int start_b)
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

void rotate(char* x, int n, int rotdist)
{
    if (rotdist == 0 || rotdist == n)
        return;

    recursive_swap(x, n, 0, ((rotdist % n) + n) % n);
}
#endif

#ifdef ITERATIVE
void swap(char *arr, int i, int j, int m)
{
    char t;

    while (m--)
    {
        t = arr[i + m];
        arr[i + m] = arr[j + m];
        arr[j + m] = t;
    }
}

void rotate(char *x, int n, int rotdist)
{
    if ((rotdist == 0) || (rotdist == n))
        return;

    int i = rotdist;
    int p = rotdist;
    int j = n - p;

    while (i != j)
    {
        if (i > j)
        {
            swap(x, p - i, p, j);
            i -= j;
        }
        else
        {
            swap(x, p - i, p + j - i, i);
            j -= i;
        }
    }
    swap(x, p - i, p, i);
}
#endif

#ifdef REVERSE
void swap(char *arr, int i, int j)
{
    char t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void reverse(char *arr, int start, int end)
{
    while (i < j)
        swap(arr, i++, j--);
}

void rotate(char* x, int n, int rotdist)
{
    reverse(x, 0, rotdist-1);
    reverse(x, rotdist, n-1);
    reverse(x, 0, n-1);
}
#endif
