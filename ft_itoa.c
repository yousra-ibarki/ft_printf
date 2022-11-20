/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:17:13 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/19 15:17:16 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countf(int number)
{
	long	i;
	long	c;

	i = 1;
	c = 0;
	if (number < 0)
	{
		c++;
		number = -number;
	}
	if (number < 10)
	{
		c++;
		return (c);
	}
	while (i <= number)
	{
		i *= 10;
		c++;
	}
	return (c);
}

static char	*ifneg(char *ptr, int nbr, int len)
{
	ptr[0] = '-';
	nbr = -nbr;
	if (nbr >= 10)
	{
		while (--len > 0)
		{
			ptr[len] = (nbr % 10) + '0';
			nbr /= 10;
		}
	}
	return (ptr);
}

static char	*ft_tochar(char *ptr, int nbr, int len)
{
	long	i;

	i = 0;
	ptr[len] = '\0';
	if (nbr < 0)
		return (ifneg(ptr, nbr, len));
	if (nbr >= 10)
	{
		while (--len >= 0)
		{
			ptr[len] = (nbr % 10) + '0';
			nbr /= 10;
		}
	}
	else
		ptr[--len] = (nbr % 10) + '0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	long	i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_countf(n);
	ptr = malloc((sizeof(char) * len + 1));
	if (!ptr)
		return (0);
	ft_tochar(ptr, n, len);
	return (ptr);
}
