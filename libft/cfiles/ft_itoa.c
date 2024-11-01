/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:58:37 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/25 16:47:17 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digits(int n)
{
	int		count;
	long	i;

	count = 1;
	i = n;
	if (n < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 9)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		c;
	long	l;

	l = n;
	c = count_digits(l);
	result = malloc(c + 1);
	i = 0;
	result[0] = '0';
	if (l < 0)
	{
		l *= -1;
		result[0] = '-';
	}
	while (l > 0)
	{
		result[--c] = (l % 10) + 48;
		l /= 10;
		i++;
	}
	if (n <= 0)
		i++;
	result[i] = '\0';
	return (result);
}
/*
int main()
{
	int n = 0;
	char * s = ft_itoa(n);
	printf("%s", s);
	free(s);
}*/
