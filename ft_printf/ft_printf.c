/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:58:33 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/06 17:41:25 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int print_type(char c, va_list args)
{
	if (c == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
		return (3);
	}
	if (c == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	result;
	int	i;
	
	i = 0;
	va_start(args, format);
	while(format[i])
	{
		if (format[i] == '%')
		{
			result += print_type(format[i + 1], args);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}

int	main (void)
{
	ft_printf("%s eu sou o numero %i", "ola", 1);
}
