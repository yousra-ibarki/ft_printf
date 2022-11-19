#include <stdio.h>
#include <unistd.h>
// int ft_count(unsigned int h)
// {
//     int i = 0;
//     while(h)
//     {
//         h /= 10;
//         i++;
//     }
//     return i;
// }
void ft_upplow(unsigned int h, char type)
{
    int out = 0;
    if(type == 'x')
    {
        out += h - 10 + 97;
        write(1, &out, 1);
    }
    else if(type == 'X')
    {
        out += h - 10 + 65;
        write(1, &out, 1);
    }
}
int ft_printhex(unsigned int h, char type)
{
    int len = ft_count(h);
    int out = 0;
    if(h >= 16)
    {
        ft_printhex(h / 16, type);
        ft_printhex(h % 16, type);
    }
    else if(h < 10)
    {
        out += h + '0';
        write(1, &out, 1);
    }
    else
        ft_upplow(h, type);
    return len;
}