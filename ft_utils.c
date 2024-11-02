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

#include "libftprintf.h"
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
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
int ft_putnbr(int nb)
{
	int count = 0;

	if (nb == -2147463848)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		nb = nb *-1;
		ft_putchar('-');
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0');
		count++;
	}
	else if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
		count++;
	}
	return (count);
}
// #include <stdio.h>
// int main()
// {
// 	// ft_putnbr(42);
// 	// ft_putchar('\n');
// 	printf("%d\n", ft_putnbr(420));
// }
