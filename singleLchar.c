#include <unistd.h>
int ft_putchar(char a)
{
    write(1, &a, 1);
    return 1;
}