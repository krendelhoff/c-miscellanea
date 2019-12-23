#include <stdio.h>
void shellsort(int s[], int n);
void shellsortv2(int s[], int n);
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
void shellsort(int s[], int n)
{
    for(int gap = n / 2; gap > 0; gap /= 2)
        for(int i = gap; i < n; i++)
            for(int j = i - gap; j >= 0 && s[j] > s[j + gap]; j -= gap)
            {
                int temp = s[j];
                s[j] = s[j + gap];
                s[j + gap] = temp;
            }
}