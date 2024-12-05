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

counter	go_player(char **map_matrix, counter player)
{
	while (map_matrix[player.y])
	{
		while (map_matrix[player.y][player.x])
		{
			if (map_matrix[player.y][player.x] == 'P')
				break ;
			player.x++;
		}
		if (map_matrix[player.y][player.x] == 'P')
			break ;
		player.x = 0;
		player.y++;
	}
	return (player);
}

counter	fill(char **map, counter count, counter player, counter size)
{
	if (player.y < 0 || player.y >= size.y || player.x < 0 \
		|| player.x >= size.x || map[player.y][player.x] == '1')
		return (count);
	if (map[player.y][player.x] == 'C')
		count.x++;
	else if (map[player.y][player.x] == 'E')
		count.y++;
	map[player.y][player.x] = '1';
	count = fill(map, count, (counter){player.x - 1, player.y}, size);
	count = fill(map, count, (counter){player.x + 1, player.y}, size);
	count = fill(map, count, (counter){player.x, player.y - 1}, size);
	count = fill(map, count, (counter){player.x, player.y + 1}, size);
	return (count);
}

counter	flood_fill(char **map, counter count, counter player, counter size)
{
	count = fill(map, count, player, size);
	return (count);
}

int	check_path(char **map, int coins)
{
	counter	player;
	counter	count;
	counter	size;
	int		result;

	result = 0;
	player.x = 0;
	player.y = 0;
	count.x = 0;
	count.y = 0;
	size = map_dim(map);
	player = go_player(map, player);
	count = flood_fill(map, count, player, size);
	if (count.x != coins || count.y != 1)
		result = -1;
	return (result);
}
/*
int	main(void)
{
	char **map = create_matrix(".ber");
	int i = check_path(map, 2);
	ft_printf("%i\n", i);
	matrix_free(map);
}*/
