#include <stdio.h>
#include <math.h>
int main()
{
    float x;
    x = 0;
    x = pow(2, 32); /* возводим 2 в 32 степень */
    printf("pow(2, 32) = %.0f\n", x);

    x = x - 1;
    printf("pow(2, 32) -  1  = %.0f\n", x);

    return 0;
}
