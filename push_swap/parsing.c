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

int	parsing(char **mtx, int argc)
{
	int	  i;
	int	  j;

	i = argc - 1;
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
