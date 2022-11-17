#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_printf(const char *s, ...)
{
    int i = 0;
    va_list varin; //varin hold the information of va_start and va_arg
    int len = 0;
    va_start(varin, s);
    while(s[i])
    {
        if(s[i] == '%' && s[i + 1] == 'c')
            len += ft_printc(va_arg(varin, int));
        else if(s[i] == '%' && s[i + 1] == 's')
            len += ft_prints(va_arg(varin, char *));
        else if(s[i] == '%' && s[i + 1] == 'p')
            len += ft_printfp(va_arg(varin, int));
        else if(s[i] == '%' && s[i + 1] == 'd' || s[i + 1] == 'i')
            len += ft_printnb(va_arg(varin, int));
        else if(s[i] == '%' && s[i + 1] == 'u')
            len += ft_printunsigned(va_arg(varin, unsigned int));
        else if(s[i] == '%' && s[i + 1] == 'x' || s[i + 1] == 'X')
            len += ft_printhexa(va_arg(varin, unsigned int), s[i + 1]);
        else if(s[i] == '%' && s[i + 1] == '%')
            len += ft_printper(va_arg(varin, char));
        else 
            len += ft_printc(s[i]);
        i++;
    }
    va_end(varin);
    return len;
}