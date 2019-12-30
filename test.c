#include <stdio.h>
int main(void) 
{
    char line[100];
    line[0] = 'a';
    line[1] = 'b';
    line[2] = 'c';
    line[3] = '\0';
    printf("%d\n", line == "abc");
}