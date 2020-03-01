#include <stdio.h>
#include <math.h>
int getLine(char s[]);
int main(void)
{
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int lo = 0, hi = 19, m = 0, mid, n, i = 0, j;
  char s[100], c;
  int strlen = getLine(s);
  printf("Finished!\n");
  printf("The length of the string is: %d\n", strlen);
  printf("Your string: %s\n", s);
  j = strlen - 1;
  n = 0;
  while (j >= 0)
    {
      n = pow(10, j)*(s[i] - '0') + n;
      i++;
      j--;
    }
  printf("Your num is: %d\n", n);
  while (lo <= hi)
    {
      if ((lo + hi) % 2 == 0)
        mid = (lo + hi)/2;
      else
        mid = (lo + hi)/2 + 1;
      if (n == array[mid])
        {
          printf("Position number: %d\n", mid);
          m = 1;
          break;
        }
      if (n > array[mid])
        lo = mid + 1;
      if (n < array[mid])
        hi = mid - 1;
    }
  if (m == 0)
  printf("There is no such term in the array.\n");
  return 0;
}
int getLine(char s[])
{
  char c;
  int i = 0;
  while ((c = getchar()) != '\n')
  {
    s[i] = c;
    ++i;
  }
  //s[i + 1] = '\0';
  return i;
}
