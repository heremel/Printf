/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:38:45 by marvin            #+#    #+#             */
/*   Updated: 2024/11/02 16:38:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
int ft_putnbr(int nb)
{
	int count;

	count = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		nb = nb *-1;
		count += ft_putchar('-');
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}
int ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int count;

	count = 0;
	if (nb < 0)
	{
		nb = nb *-1;
		count += ft_putchar('-');
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}
