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

int	ft_hexa_base()
{
	int hexa;

	hexa = "123456789abcdef";
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
		//hexa lowerrcase
	else if (c == 'X')
		//hexa uppercase
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