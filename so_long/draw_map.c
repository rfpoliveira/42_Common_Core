/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:45:48 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/06 17:57:42 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void draw(t_vars *vars, void *img, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, y * 32, x * 32);
}

void map_draw(t_vars *vars)
{
	int	y;
	int	x;

	while (vars->map->matrix[y])
	{
		while (vars->map->matrix[y][x])
		{
			if (vars->map->matrix[y][x] == '1')
				draw(vars, vars->img->wall, y, x);
			else if (vars->map->matrix[y][x] == '0')
				draw(vars, vars->img->bg, y, x);
			else if (vars->map->matrix[y][x] == 'P')
				draw(vars, vars->img->player_left, y, x);
			else if (vars->map->matrix[y][x] == 'E')
				draw(vars, vars->img->exit_c, x, y);
			else if (vars->map->matrix[y][x] == 'C')
				draw(vars, vars->img->token, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}
