#include <stdio.h>
#include "library.h"
int main(void)
{
    printf("%d\n", setbits(85, 4, 3, 59));
    printf("%d\n", invert(85, 4, 3));
    printf("%d\n", rightrot(85, 3));
    printf("%d\n", bitcount(100));
}
