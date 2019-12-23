#include <stdio.h>
#define MAX 100000
int binsearch(int x, int s[], int n);
int binsearchv(int x, int s[], int n);
int main(void)
{
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = i;
    printf("%d\n", binsearch(20, arr, 21));
    printf("%d\n", binsearchv(20, arr, 21));
    return 0;
}
int binsearch(int x, int s[], int n)
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
int binsearchv(int x, int s[], int n)
{
    int low = 0, high = --n, mid;
    while(low < high) 
    {
        mid = (low + high) / 2;
        if (x <= s[low]) 
            high = mid;
        else low = mid + 1;
    }
    return (x == s[low]) ? low : -1;
}