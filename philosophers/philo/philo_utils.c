/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:52:49 by rpedrosa          #+#    #+#             */
/*   Updated: 2025/01/22 16:55:26 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	r_isdigit(char *s)
{
	int	i;

	while(s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}


int	r_atoi(const char *str)
{
	int	i;
	int	sig;
	int	res;

	res = 0;
	i = 0;
	sig = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
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

