/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:13:45 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/06 17:24:49 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void img_ini (t_vars *vars)
{
	vars->img->player_up = mlx_xpm_file_to_image
		(vars->mlx, "assests/images/player_up.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->player_down = mlx_xpm_file_to_image
		(vars->mlx, "assests/images/player_down.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->player_left = mlx_xpm_file_to_image
		(vars->mlx, "assests/images/player_left.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->player_right = mlx_xpm_file_to_image
		(vars->mlx, "assests/images/player_right.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->bg = mlx_xpm_file_to_image
		(vars->mlx, "assests/images/bg.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->token = mlx_xpm_file_to_image
		(vars->mlx, "assests/images/token.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->wall = mlx_xpm_file_to_image
		(vars->mlx, "assests/images/wall.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->exit_c = mlx_xpm_file_to_image
		(vars->mlx, "assests/images/ex.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->exit_o = mlx_xpm_file_to_image
		(vars->mlx, "assests/images/exit_o.xpm", &vars->img->img_w, &vars->img->img_h);
}

static void win_ini (t_vars *vars)
{
	counter dimentions;

	map->matrix = create_matrix(map_path);
	dimensions = map_dim(map->matrix);
	vars->map->dim.y = dimensions.y * 32;
	vars->map->dim.x = dimensions.x * 32;
}

void  game_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	win_ini(vars);
	vars->win = mlx_new_window(vars->mlx, vars->map->dim.y, vars->map->dim.x, "so_long");
	img_ini(vars);
	draw_map(vars);
}
