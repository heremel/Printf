/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:26:19 by marvin            #+#    #+#             */
/*   Updated: 2024/11/02 16:26:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_hexa_base(unsigned int n)
{
	char *hexa;

	hexa = "123456789abcdef";
	if (n == 0)
	{
		ft_putchar('0');
		return;
	}
	else if (n >= 16)
	{
		ft_hexa_base(n / 16);
	}
	ft_putchar(hexa[n % 16]);
}
void	ft_hexa_base_uppercase(unsigned int n)
{
	char *hexa;

	hexa = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_putchar('0');
		return;
	}
	else if (n >= 16)
	{
		ft_hexa_base_uppercase(n / 16);
	}
	ft_putchar(hexa[n % 16]);
}
int	ft_format(char c, va_list list)
{
	if (c == 'c')
		ft_putchar(va_arg(list, char));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list, int));
	else if (c == 'p')
		ft_pustr(va_arg(list, void *));
	else if (c == 's')
		ft_putstr(va_arg(list, char *));
	else if (c == 'u')
		//ft_putnbr
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'x')
		ft_hexa_base(va_arg(list, unsigned int));
	else if (c == 'X')
		ft_hexa_base_uppercase(va_arg(list, unsigned int));
}
int ft_printf(char *str, ...)
{
	va_list	list;
	va_start(list, str);
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_format(str[i], list);
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(list);
	return (count);

}

#include <stdio.h>

int main()
{
	char *str = "Hello World";
	printf("%s\n", str);
}