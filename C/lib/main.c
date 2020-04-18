#include <stdio.h>

int main(void)
{
    int i;
    int last;
    int current;
    int tmp;
    int array[] = {4, 5, 9, 2, 3, 7, 1};

    current = 1;
    last = 7 - 1;
    while (current <= last)
    {
        i = current + 1;
        while (i > 0 && array[i - 1] < array[i])
        {
            tmp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = tmp;
            i--;
        }
        current++;
    }
    i = 0;
    while (i < 7)
    {
        printf("%d ", array[i]);
        i++;
    }
    putchar('\n');
    return (0);
}
