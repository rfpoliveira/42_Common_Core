/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:01:33 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/27 14:09:16 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_map_line(char *s)
{
	int	i;

	i = 0;
	if (s[i++] != '1')
	{
		ft_printf("Map not closed in the right\n");
		return (1);
	}
	while (s[i])
	{
		if (!(s[i] < '1' || s[i] != '0' || s[i] != 'E' \
			|| s[i] != 'P' || s[i] != 'C'))
		{
			ft_printf("Invalid charaters!\n");
			return (1);
		}
		i++;
	}
	if (s[i - 2] != '1')
	{
		ft_printf("Map not closed in the left!\n");
		return (1);
	}
	return (0);
}

static int check_map_topbot(char *s)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s[i] != '1' && s[i] != '\n')
		{
			ft_printf("Map not closed on top or bottom\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int check_count(char **map_matrix)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map_matrix[i])
	{
		while (map_matrix[i][j])
		{
			if (map_matrix[i][j] == 'C')
				count += 10;
			else if (map_matrix[i][j] == 'E' || map_matrix[i][j] == 'P')
				count += 1;
			i++;
		}
	}
	if (count % 10 != 2)
	{
		ft_printf("Map with no entrace or exit!\n");
		return (1);
	}
	if (count / 10 < 1)
	{
		ft_printf("Don't forget the coins!\n");
		return (1);
	}
	return (0);
}

int	check_map(char **map_matrix)

// return 0 = good map;
// return 1 = bad map;
// return 2 = malloc error;

{
	int		i;
	int		height;

	i = 1;
	height = 0;
	while(map_matrix[height])
		height++;
	while (i < height)
	{
		if (check_map_line(map_matrix[i]) == 1)
			return (1);
		i++;
	}
	if (check_map_topbot(map_matrix[0]) == 1 || check_map_topbot(map_matrix[height - 1]) == 1)
		return (1);
	if (check_count(map_matrix) == 1)
		return (1);
	return (0);
}

int main (int argc, char **argv)
{
	argc = 0;
	int i = check_map(create_matrix(argv[1]));
	ft_printf("%i", i);
}
