/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:12:00 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/03 11:59:05 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	*find_player(**map_matrix)
{	
	int	y;
	int	x;
	int	*player;

	y = 0;
	x = 0;
	while(map_matrix[y])
	{
		while(map_matrix[y][x])
		{
			if (map_matrix[y][x] == 'P')
				break ;
			x++;
		}
		y++;
	}
	player = {y , x};
	return (player);
}

static int	*make_count(char **map, int *player)
{
	int	end;
	int	x;
	int y;
	int	*count;

	x = player[1];
	y = player [0];
	end = 1;
	while (end)
	{
		if (map[y + 1][x] != '1')
			y++;
		else if (map[y][x - 1] != '1')
			x--;
		else if (map[y - 1][x] != '1')
			y--;
		else if (map [y][x + 1] != '1')
			x++;
		else
			end = 0;
		if (map[y][x] == 'C')
			count[0]++;
		if (map[y][x] == 'E')
			count[1] ++;
	}
	return (count);
}

int	flood_fill(char **map, int coins)
{
	int	*player;
	int *count;
	int	result;

	count = malloc(sizeof(int) * 2);
	player = malloc(sizeof(int) * 2);
	result = 0;
	player = find_player(map);
	count = make_count(map, player);
	if (count[0] != coins || count[1] != 1)
		result = 1;
	free(count);
	free(player);
	return (result);
}
