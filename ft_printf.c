#include "ft_printf.h"

static int ft_checkformat(char c, va_list varin)
{
    int len = 0;
    if(c == '%')
    {
        if(c == 'c')
            len += ft_putchar(va_arg(varin, int));
        else if(c == 's')
            len += ft_prints(va_arg(varin, char *));
        else if(c == 'p')
            len += ft_printp(va_arg(varin, int));
        else if(c == 'd' || c == 'i')
            len += ft_printnb(va_arg(varin, int));
        else if(c == 'u')
            len += ft_printunsigned(va_arg(varin, unsigned int));
        else if(c == 'x' || c == 'X')
            len += ft_printhex(va_arg(varin, unsigned int), c);
        else if(c == '%')
            len += ft_putchar('%');
    }
    return len;
}

int ft_printf(const char *s, ...)
{
    int i = 0;
    va_list varin; 
    int len = 0;
    va_start(varin, s);
    while(s[i])
    {
        len += ft_checkformat(s[i], varin);
        i++;
    }
    va_end(varin);
    return len;
}