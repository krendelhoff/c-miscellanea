#include <stdio.h>
#include "library.h"
int main(void) 
{
    int arr[1000];
    for(int i = 0; i < 1000; i++) {
        arr[i] = 999 - i;
        printf("%d ", arr[i]);
        if (!(i % 38)) 
            putchar('\n');
    }
    shellsort(arr, 1000);
    putchar('\n');
    for(int i = 0; i < 999; i++) {
        printf("%d ", arr[i]);
        if (!(i % 38)) 
            putchar('\n');
    }
    putchar('\n');
}
