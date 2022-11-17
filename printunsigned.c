#include<unistd.h>
#include <stdlib.h>
#include <stdio.h>
int ft_count(unsigned int nb)
{
    int i = 0;
    while(nb)
    {
        nb /= 10;
        i++;
    }
    return i;
}

int ft_printunsigned(unsigned int nb)
{
    int len = ft_count(nb);
    printf("len is %d\n", len);
    char *nbr;
    int i = 0;
    nbr = malloc(sizeof(char) * (len + 1));
    if(!nbr)
        return 0;
    while(i < len)
    {
        nbr[i] = nb % 10 + '0';
        nb /= 10;
        i++;
    }
    i = 0;
    while(nbr[i])
    {
        write(1, &nbr[i], 1);
        i++;
    }
    free(nbr);
    nbr[len] = '\0';
    return len;
}