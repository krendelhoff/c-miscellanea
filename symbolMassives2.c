#include <stdio.h>
#define MAXLINE 1000
#define THRESHOLD 80
int getLine(char s[], int lim); 
int main(void)
{
    char line[MAXLINE];
    int len;
    while((len = getLine(line, MAXLINE)) > 0) {
        if (len > THRESHOLD) {
            printf("\n");
            printf("Строка бОльшая 80 символов:%s\n", line);
        }
    }
    return 0;
}
int getLine(char s[], int lim) {
    int i;
    char c;
    for(i = 0; i < lim - 1 && (c = getchar()) != '0' && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;    
}
