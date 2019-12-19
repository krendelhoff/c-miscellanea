#include <stdio.h>
#define QUAN ('z' - 'a' + 1)
#define QUAN1 10
int main(void) {
    char c;
    int frequencyLetters[QUAN],
        frequencyNum[QUAN1];
    for (short g = 0; g < QUAN; g++) {
        frequencyLetters[g] = 0;
    }
    for (short g = 0; g < QUAN1; g++) {
        frequencyNum[g] = 0;
    }
    while ((c = getchar()) != '\n') {
        if (c >= 'a' && c <= 'z') {
            frequencyLetters[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            frequencyLetters[c - 'A']++;
        } else if (c >= '0' && c <= '9') {
            frequencyNum[c - '0']++;
        }
    }
    for (short i = 0; i < QUAN; i++) {
        putchar('a' + i);
        putchar(':');
        for (short j = 0; j < frequencyLetters[i]; j++) {
            putchar('-');
        }
        putchar('\n');
    }
    for (short i = 0; i < QUAN1; i++) {
        putchar('0' + i);
        putchar(':');
        for (short j = 0; j < frequencyNum[i]; j++) {
            putchar('-');
        }
        putchar('\n');
    }
    /*char c;
    int state;
    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            state = OUT;
            putchar(' ');
        } else if (state == OUT) {
            state = IN;
            putchar(')');
        } else putchar(')');
    }
    putchar('\n');*/
    /*int c;
    c = '1';
    printf("%d", c);*/
    /*char c;
    int state;
    while ((c = getchar()) != '`') {
        if (c == ' ') {
            state = OUT;
            putchar('\n');
        } else if (state == OUT) {
            state = IN;
            putchar(c);
        } else putchar(c);
    }*/
    /*char c, b;
    int n;
    n = 0;
    b = 'p';
    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            ++n;
        }
        if (b == ' ' && n >= 1) {
            n = 0;
            continue;
        } else {
            putchar(c);
        }
        b = c;
    }
    putchar('\n');*/
    /*char c;
    short nl;
    nl = 0;
    while((c = getchar()) != 'p') {
        if (c == '\t' || c == ' ' || c == '\n') {
            ++nl;
        }
    }
    printf("%d", nl);*/
}
