#include <unistd.h>
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