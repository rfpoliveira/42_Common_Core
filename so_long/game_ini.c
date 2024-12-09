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

void img_ini (t_vars *vars)
{
	vars->img->player = mlx_xpm_file_to_image
		(vars->mlx, "assets/images/pl.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->bg = mlx_xpm_file_to_image
		(vars->mlx, "assets/images/bg.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->token = mlx_xpm_file_to_image
		(vars->mlx, "assets/images/token.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->wall = mlx_xpm_file_to_image
		(vars->mlx, "assets/images/wall.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->exit_c = mlx_xpm_file_to_image
		(vars->mlx, "assets/images/exit_c.xpm", &vars->img->img_w, &vars->img->img_h);
	vars->img->exit_o = mlx_xpm_file_to_image
		(vars->mlx, "assets/images/exit_o.xpm", &vars->img->img_w, &vars->img->img_h);
	/*if (!(vars->img->player_up) || !(vars->img->player_down) || \
		!(vars->img->player_left) || !(vars->img->player_right) || \
		!(vars->img->bg) || !(vars->img->token) || !(vars->img->wall) || \
		!(vars->img->exit_c) || !(vars->img->exit_o))
			ft_exit(vars);*/
}

void win_ini (t_vars *vars, char *path)
{
	counter dimensions;

	vars->matrix = create_matrix(path);
	if (!(vars->matrix))
		ft_exit(vars);
	dimensions = map_dim(vars->matrix);
	vars->dim.y = dimensions.y * 32;
	vars->dim.x = dimensions.x * 32;
	vars->win = mlx_new_window(vars->mlx, vars->dim.y, vars->dim.x, "so_long");
		if (!(vars->win))
			ft_exit(vars);
}

void  game_init(t_vars *vars, char *path)
{
	vars->mlx = mlx_init();
	if (!(vars->mlx))
		ft_exit(vars);
	win_ini(vars, path);
	vars->moves = 0;
	img_ini(vars);
	draw_map(vars);
}
