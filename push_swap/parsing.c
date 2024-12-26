/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:19:43 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/17 12:37:03 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sig;
	long	res;

	res = 0;
	i = 0;
	sig = 1;
	if (str[i] == '-')
	{
		sig *= -1;
		i++;
	}
	if (str[i] == '+' && str[i - 1] != '+' && str[i - 1] != '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * sig);
}

int	  check_arg(char *n)
{
	int	  numb;
	int	  i;

	i = 0;
	if (n[0] == '-' || n[0] == '+')
		i++;
	while(n[i])
	{
		if (ft_isdigit(n[i]) == 0)
			return (-1);
		i++;
	}
	if (i > 11)
		return (-1);
	numb = ft_atol(n);
	if (numb > INT_MAX || numb < INT_MIN)
		return (-1);
	return (0);
}

int	parsing(char **mtx, int argc)
{
	int	  i;
	int	  j;

	i = argc - 2;
	j = 0;
	while (i >= 1)
	{
		j = i;
		while (j >= 2)
		{
			if  (atol(mtx[i]) == atol(mtx[j - 1]))
				return (-1);
			j--;
		}
		if (check_arg(mtx[i]) == -1)
			return (-1);
		i--;
	}
	return (0);
}
