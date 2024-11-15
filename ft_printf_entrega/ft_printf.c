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

#include "ft_printf.h"

static int	print_type(char c, va_list args)
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
		return (r_put_ptr(va_arg(args, unsigned long long)));
	else if (c == 'u')
		return (r_putunsig(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (r_put_hex(va_arg(args, unsigned int), c));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;
	int		i;

	i = 0;
	result = 0;
	va_start(args, format);
	while (format[i])
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
/*
int	main (void)
{

	//general tests
	char *s = NULL;//"hello world!"; 
	int i = 0;
	unsigned long x = ULONG_MAX;
	unsigned int u = 0;
	char c = 0;

	int count = ft_printf("string: %s, int: %i, hex: %x e %X, pointer: %p, \
unsigned: %u, char: %c\n", s, i, (unsigned int)x, (unsigned int)x, 0x0, u, c);
	ft_printf("total: %i\n", count);

	int count2 = printf("string: %s, int: %i, hex: %x e %X, pointer: %p, \
unsigned: %u, char: %c\n", s, i, (unsigned int)x, (unsigned int)x, 0x0, u, c);
	printf("total: %i\n", count2);

	//null pointer
	i = ft_printf("%p\n", NULL);
	ft_printf("%i\n", i);
	i = printf("%p\n", NULL);
	printf("%i\n", i);
	//hex edges
	i = ft_printf("numero: %x\n", 0);
	ft_printf("conta: %i\n", i);

	i = printf("numero: %x\n", 0);
	printf("conta: %i\n", i);

	i = ft_printf("output: %x\n", LONG_MAX);
	ft_printf("conta: %i\n", i);

	unsigned long jj = printf("output: %lx\n", LONG_MAX);
	printf("conta: %lx\n", jj);	
}
*/
/*
#include "stddef.h"

int main(void)
{
    int real_return, my_return;

    // Test with strings
    real_return = printf("Real: %s\n", "Hello, World!");
    my_return = ft_printf("Mine: %s\n", "Hello, World!");
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with NULL string
    real_return = printf("Real: %s\n", (char *)NULL);
    my_return = ft_printf("Mine: %s\n", (char *)NULL);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with characters
    real_return = printf("Real: %c\n", 'A');
    my_return = ft_printf("Mine: %c\n", 'A');
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with integers
    real_return = printf("Real: %d\n", 12345);
    my_return = ft_printf("Mine: %d\n", 12345);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with unsigned integers
    real_return = printf("Real: %u\n", 12345);
    my_return = ft_printf("Mine: %u\n", 12345);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with hexadecimal (lowercase)
    real_return = printf("Real: %x\n", 12345);
    my_return = ft_printf("Mine: %x\n", 12345);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Additional tests for %x (lowercase)
    real_return = printf("Real: %x\n", 0);
    my_return = ft_printf("Mine: %x\n", 0);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    real_return = printf("Real: %x\n", 255);
    my_return = ft_printf("Mine: %x\n", 255);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    real_return = printf("Real: %x\n", 4294967295U);
    my_return = ft_printf("Mine: %x\n", 4294967295U);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with hexadecimal (uppercase)
    real_return = printf("Real: %X\n", 12345);
    my_return = ft_printf("Mine: %X\n", 12345);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Additional tests for %X (uppercase)
    real_return = printf("Real: %X\n", 0);
    my_return = ft_printf("Mine: %X\n", 0);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    real_return = printf("Real: %X\n", 255);
    my_return = ft_printf("Mine: %X\n", 255);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    real_return = printf("Real: %X\n", 4294967295U);
    my_return = ft_printf("Mine: %X\n", 4294967295U);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with pointer
    int x = 42;
    real_return = printf("Real: %p\n", (void *)&x);
    my_return = ft_printf("Mine: %p\n", (void *)&x);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with percentage
    real_return = printf("Real: %%\n");
    my_return = ft_printf("Mine: %%\n");
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    return 0;
}*/
