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
	if (s[0] != 1)
		return (1);
	while (s[i])
	{
		if (s[i] != '0' || s[i] != 'E' || s[i] != 'P' || s[i] != 'C')
			return (1);
		i++;
	}
	if (s[i - 1] != 1)
		return (1);
	return (0);
}

static int check_map_topbot(char *s)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s[i++] != 1)
			return (1);
	}
	return (0);
}
static char	**save_map(char *map)
{
	char	**save;
	int		fd;
	int		i;

	i = 0;
	map = ft_strjoin("maps/", map);
	fd = open(map, O_RDONLY);
	while (save[i])
	{
		save[i] = get_next_line(fd);
		i++;
	}
	return (save);
}

staticint check_count(char **map_matrix)
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
		return (1);
	if (count / 10 < 1)
		return (1);
	return (0);
}

int	check_map(char **map_matrix, char *map)

// return 0 = good map;
// return 1 = bad map;
// return 2 = malloc error;

{
	int		i;
	int		count;

	i = 0;
	map_matrix = save_map(map);

	while (map_matrix[i + 1])
	{
		if (check_map_line(map_matrix[i]) == 1)
			return (1);
		i++;
	}
	if (check_map_topbot(map_matrix[0]) == 1 || check_map_topbot(map_matrix[i]) == 1)
		return (1);
	if (check_count(map_matrix) == 1)
		return (1);
	return (0);
}

int main (int argc, char **argv)
{
	argc = 0;
	check_map(argv[1]);
}
