#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
char	*ft_itoa(int n);
int ft_printf(const char *s, ...);
static int ft_checkformat(char c, va_list varin);
int ftt_count(int p);
int ft_printp(int p);
void ft_upplow(unsigned int h, char type);
int ft_printhex(unsigned int h, char type);
int ft_printunsigned(unsigned int nb);
int ft_putchar(int a);
int ft_prints(char *str);
int ft_printnb(int nb);
int ft_count(unsigned int h);

#endif