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
	mlx_put_image_to_window(vars->mlx, vars->win, img, x * 32, y * 32);
}

static void draw_exit(t_vars *vars, int y, int x)
{
	if (vars->coins == 0)
	{
		draw(vars, vars->img.exit_o,y ,x);
		vars->endgame = 1;
	}
	else 
		draw(vars, vars->img.exit_c, y, x);
}

int draw_map(t_vars *vars)
{
	int	y;
	int	x;

	vars->endgame = 0;
	y = 0,
	x = 0;
	while (vars->matrix[y])
	{
		while (vars->matrix[y][x])
		{
			if (vars->matrix[y][x] == '1')
				draw(vars, vars->img.wall, y, x);
			else if (vars->matrix[y][x] == 'F')
				{
					draw_exit(vars, y, x);
					draw(vars, vars->img.player, y, x);
				}
			else if (vars->matrix[y][x] == '0')
				draw(vars, vars->img.bg, y, x);
			else if (vars->matrix[y][x] == 'P')
				draw(vars, vars->img.player, y, x);
			else if (vars->matrix[y][x] == 'E')
				draw_exit(vars, y, x);
			else if (vars->matrix[y][x] == 'C')
				draw(vars, vars->img.token, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
