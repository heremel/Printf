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

#include "ft_printf.h"

int ft_hexa_adress(unsigned long n)
{
	char *hexa;
	int	count;

	count = 0;
	if (!n && n == 0)
		return (ft_putstr("(nil)"));
	hexa = "0123456789abcdef";
	if (n >= 16)
		count += ft_hexa_adress(n / 16);
	if (n < 16)
		count += ft_putstr("0x");
	count += ft_putchar(hexa[n % 16]);
	return (count);
}
int	ft_hexa_base(unsigned int n, int check)
{
	char *hexa;
	int	count;

	count = 0;
	if (!n && n != 0)
		return (ft_putstr("(nil)"));
	if (check == 0)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_hexa_base(n / 16, check);
	}
	count += ft_putchar(hexa[n % 16]);
	return (count);
}
void	ft_format(char c, va_list list, int *count)
{
	if (c == 'c')
		*count += ft_putchar(va_arg(list, int));
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(list, int));
	else if (c == 'p')
		*count += ft_hexa_adress(va_arg(list, unsigned long));
	else if (c == 's')
		*count += ft_putstr(va_arg(list, char *));
	else if (c == 'u')
		*count += ft_putnbr_unsigned(va_arg(list, unsigned int));
	else if (c == '%')
		*count += ft_putchar('%');
	else if (c == 'x')
		*count += ft_hexa_base(va_arg(list, unsigned int), 0);
	else if (c == 'X')
		*count += ft_hexa_base(va_arg(list, unsigned int), 1);
	else
	{
		ft_putchar('%');
		ft_putchar(c);
	}
}
int ft_printf(const char *str, ...)
{
	va_list	list;
	int i;
	int count;
	va_start(list, str);

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(str[i], list, &count);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);

}

#include <stdio.h>

int main()
{
	ft_printf("%a\n", "blablacar");
	// printf(" %u ", -1);
}