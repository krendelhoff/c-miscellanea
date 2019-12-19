#include <stdio.h>
float preob(float);
int main(void) {
    float fahr;
    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3.0f\t%6.2f\n", fahr, preob(fahr));
    }
}
float preob(float t) {
    return 5.0*(t - 32)/9;
}