/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:08:29 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/02 16:08:29 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	*go_player(char **map_matrix)
{
	int	x;
	int	y;
	int	*count;

	count = ft_calloc(2, sizeof(int));
	y = 0;
	x = 0;
	while (map_matrix[y])
	{
		while (map_matrix[y][x])
		{
			if (map_matrix[y][x] == 'P')
				break ;
			x++;
		}
		if (map_matrix[y][x] == 'P')
			break ;
		x = 0;
		y++;
	}
	count[0] = y;
	count[1] = x;
	return (count);
}

static int	*flood(int *count, char **map, int *player)
{
	int	x;
	int	y;

	x = player[1];
	y = player[0];
	while (1)
	{
		map[y][x] = '1';
		if (map[y - 1][x] != '1')
			y--;
		else if (map[y][x - 1] != '1')
			x--;
		else if (map[y + 1][x] != '1')
			y++;
		else if (map[y][x + 1] != '1')
			x++;
		else
			break ;
		if (map[y][x] == 'C')
			count[0]++;
		else if (map[y][x] == 'E')
			count[1]++;
	}
	return (count);
}

int	check_path(char **map, int coins)
{
	int	*player;
	int	*count;
	int	result;

	count = ft_calloc(2, sizeof(int));
	result = 0;
	player = go_player(map);
	count = flood(count, map, player);
	if (count[0] != coins || count[1] != 1)
		result = 1;
	free(count);
	free(player);
	return (result);
}
/*
int	main(void)
{
char **map = create_matrix("maps/test.ber");
	int i = check_path(map, 2);
	ft_printf("%i\n", i);
	free(map);
}*/
