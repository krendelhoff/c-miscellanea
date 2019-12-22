#include <stdio.h>
#define MAX 100000
int find(int x, int s[], int n);
int main(void)
{
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = i;
    printf("%d\n", find(20, arr, 21));
    return 0;
}
int find(int x, int s[], int n)
{
    int high = --n, low = 0, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (s[mid] > x)
        {
            high = mid - 1;
        }
        else if (s[mid] < x)
        {
            low = mid + 1;
        }
        else
            return mid;
    }
    return -1;
}