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
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (c == 's')
		return (r_putstr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (r_putnbr(va_arg(args, int)));
	else if (c == 'p')
		return (r_putpointer(va_arg(args, unsigned int)));
	else if (c == 'u')
		return (r_putunsig(va_arg(args, unsigned int)));
	else if (c == 'x' || c = 'X')
		return (r_puthex(va_arg(args, unsigned int), c));
	else if (c == '%')
		{
		ft_putchar_fd(1, '%', 1);
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
	result = 0;
	va_start(args, format);
	while(format[i])
	{
		if (format[i] == '%')
		{
			result += print_type(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			result++;
		}
		i++;
	}
	va_end(args);
	return (result);
}

int	main (void)
{
	int i = ft_printf("%s eu sou o numero %i\n", "ola", 1);
	ft_printf("numero de cenas printadas: %i", i);
}
