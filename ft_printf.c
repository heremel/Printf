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

int	ft_format(char c, va_list list)
{
	if (c == 'c')
		ft_putchar(va_arg(list, char));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list, int));
	else if (c == 'p')
		//
	else if (c == 's')
		ft_putstr(va_arg(list, char *));
	else if (c == 'u')
		//ft_putnbr
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'x')

	else if (c == 'X')
	
}
int ft_printf(char *str, ...)
{
	va_list	list;

}