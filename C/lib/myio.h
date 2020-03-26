#ifndef MYIO_H
# define MYIO_H
void print_arr(int arr[], int first, int last);
void ft_putchar(char c);
char ft_getchar(void);
void print_int(int n);
void print_str(char s[]);
int  scan_word(char s[]);
int  scan_line(char s[], int lim);
char getbufchar(void);
void putinbuf(char c);
int  scan_int(void);
int  scan_arr(int arr[]);
void print_float(double n, int signs);
#endif
