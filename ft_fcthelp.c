#include "ft_printf.h"
int ft_putchar(int a)
{
    write(1, &a, 1);
    return 1;
}
int ft_prints(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return i;
}
int ft_printnb(int nb)
{
    int i = 0;
    char *n = ft_itoa(nb);
    while(n[i])
    {
        write(1, &n[i], 1);
        i++;
    }
    free(n);
    return i;
}
int ft_count(unsigned int h)
{
    int i = 0;
    while(h)
    {
        h /= 10;
        i++;
    }
    return i;
}