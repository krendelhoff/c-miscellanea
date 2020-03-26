#ifndef ALGORITHMS_H
# define ALGORITHMS_H
void   selection_sort(int arr[], int first, int last);
int    arrlen(int arr[]);
int    strlength(char s[]);
void   swap_int(int arr[], int b, int f);
int    binary_search(int arr[], int hi, int lo, int n);
void   insertion_sort(int arr[], int first, int last);
int    str_to_int(char s[]);
double str_to_float(char s[]);
int    find(char s[], char c);
int    factorial(int n);
int    is_prime(int n);
void   print_prime_numbers(int n);
void   print_number_factors(int n);
void   sieve(int arr[], int n);
void   initialize_by_zero(int arr[], int length);
void   reverse_arr(int arr[], int first, int last);
void   reverse_str(char s[]);
void   swap_char(char s[], int b, int f);
void   cyclic_shift_left_str(char s[]);
void   cyclic_shift_right_str(char s[]);
int    fibonacci(int n);
void   remove_trailing_spaces(char s[]);
void   remove_term(char s[], int index);
#endif
