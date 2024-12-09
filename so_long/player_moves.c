/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:41:19 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/09 15:48:16 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void update_player(char key, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->player);
	if (key == 'w')
		vars->img->player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pu.xmp", &vars->img->img_w, &vars->img->img_h);
	if (key == 's')
		vars->img->player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pd.xmp", &vars->img->img_w, &vars->img->img_h);
	if (key == 'd')
		vars->img->player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pr.xmp", &vars->img->img_w, &vars->img->img_h);
	if (key == 'a')
		vars->img->player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pl.xmp", &vars->img->img_w, &vars->img->img_h);
}

void hit_W(t_vars *vars)
{
	update_player('w', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.y++;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		vars->matrix[vars->player.y][vars->player.x] = 'P';
		vars->matrix[vars->player.y + 1][vars->player.x] = '0';
		vars->moves++;
		draw_map(vars);
	}
}

void hit_S(t_vars *vars)
{
	update_player('s', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.y--;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		vars->matrix[vars->player.y][vars->player.x] = 'P';
		vars->matrix[vars->player.y - 1][vars->player.x] = '0';
		vars->moves++;
		draw_map(vars);
	}
}

void hit_D(t_vars *vars)
{
	update_player('d', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.x--;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		vars->matrix[vars->player.y][vars->player.x] = 'P';
		vars->matrix[vars->player.y][vars->player.x - 1] = '0';
		vars->moves++;
		draw_map(vars);
	}
}

void hit_A(t_vars *vars)
{
	update_player('a', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.x++;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		vars->matrix[vars->player.y][vars->player.x] = 'P';
		vars->matrix[vars->player.y][vars->player.x - 1] = '0';
		vars->moves++;
		draw_map(vars);
	}
}
