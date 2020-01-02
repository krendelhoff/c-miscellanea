#include <stdio.h>
#include "library.h"
#define MAX 100000
int main(void)
{
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = i;
    printf("%d\n", binsearch(20, arr, 21));
    printf("%d\n", binsearchv(20, arr, 21));
    return 0;
} //alalalala