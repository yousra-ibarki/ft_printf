#include <unistd.h>
#include <stdio.h>
int ft_count(int p)
{
    int n = 1;
    int i = 0;
    while(n <= p)
    {
        n *= 10;
        i++;
    }
    return i;
}
int ft_printp(int p)
{
    int len = 0;
    int out = 0;
    len += write(1, "0x", 2);
    if(p == 0)
        len += write(1, "0", 1);
    else
    {
        if(p >= 16)
        {
            ft_printp(p / 16);
            ft_printp(p % 16);
        }
        else if(p < 10)
        {
            out += p + '0';
            write(1, &out, 1);
        }
        else
        {
            out += p - 10 + 97;
            write(1, &out, 1);
        }
    }
    return (ft_count(p) + len);
}