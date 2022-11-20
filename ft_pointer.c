/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:17:26 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/19 15:17:34 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftt_count(unsigned long long p)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	while (n <= p)
	{
		n *= 10;
		i++;
	}
	return (i);
}

int	ft_check(unsigned long long p)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (p == 0)
		len += write(1, "0", 1);
	return (len);
}

int	ft_printp(unsigned long long p)
{
	int	len;
	int	out;

	len = 0;
	out = 0;
	len += ft_check(p);
	if (p != 0)
	{
		if (p >= 16)
		{
			ft_printp(p / 16);
			ft_printp(p % 16);
		}
		else if (p < 10)
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
