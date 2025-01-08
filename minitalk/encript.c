/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encript.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:23:14 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/08 15:08:32 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int encript(int c)
{
	int	i;
	int	bin;
	int	rest;

	i = 1;
	rest = 0;
	bin = 0;
	while(c > 0)
	{
		rest = c % 2;
		bin = bin + (i * rest);
		c = c / 2;
		i = i * 10;
	}
	return (bin);
}

char decript(int bin)
{
	int deci;
	int i;
	int	rest;

	i = 0;
	rest = 0;
	deci = 0;

	while(bin != 0)
	{
		rest = bin % 10;
		deci += rest << i;
		bin /= 10;
		i++;
	}
	return (deci);
}
