#include <unistd.h>
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