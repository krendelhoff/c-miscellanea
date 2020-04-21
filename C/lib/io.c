#include "libft.h"

char g_buf;
char g_buffer[BUFFER_SIZE];
int  g_i = -1;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char ft_getchar(void)
{
    read(2, &g_buf, 1);
    return (g_buf);
}

char getbufchar(void)
{
    char c;

    if (g_i < 0)
        return (ft_getchar());
    else
    {
        c = g_buffer[g_i];
        g_i--;
        return (c);
    }
}

void putinbuf(char c)
{
    g_i++;
    g_buffer[g_i] = c;
}
