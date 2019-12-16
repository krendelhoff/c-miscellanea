#include <stdio.h>
int main (void) {
    float fahr, celcius, theMostLower;
    int upper, lower, step, zero;
    theMostLower = (5.0/9)*(-32);
    zero = 0;
    printf("%3.2f\t%6d\n", theMostLower, zero);
    upper = 150;
    lower = -15;
    celcius = lower;
    step = 5;
    while (celcius <= upper) {
        fahr = (9.0/5.0)*celcius + 32.0;
        printf("%3.0f\t%10.0f\n", celcius, fahr);
        celcius = celcius + step;
    }
}