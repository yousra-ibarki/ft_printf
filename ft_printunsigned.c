/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:18:32 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/19 15:18:35 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int nb)
{
	int		len;
	char	*nbr;
	int		i;

	len = ft_count(nb);
	i = 0;
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	while (i < len)
	{
		nbr[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	i = 0;
	while (nbr[i])
	{
		write(1, &nbr[i], 1);
		i++;
	}
	free(nbr);
	nbr[len] = '\0';
	return (len);
}
