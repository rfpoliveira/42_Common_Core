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

static int print_type(char c, char *temp, va_list args)
{
	char *s;

	if (c == 's')
	{
		s = va_arg(args, char *);
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
}

int	printf(const char *mands, ...)
{
	va_list	args;
	int	result;
	char *temp;

	temp = ft_strdup(mands);
	va_start(args, mands);
	while(*(temp++))
	{
		if (*temp != '%' && ft_isprint(*temp) == 1)
		{
		write(1, temp, 1);
		result++;
		continue ;
		}
		else if (*temp == '%')
		{
			result += print_type(*temp, temp, args);
			temp += 2;
		}
	}
	va_end(args);
	return (result);
}

int	main (void)
{
	ft_printf("%s", "ola");
}
