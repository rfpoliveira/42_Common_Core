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
	mlx_destroy_image(vars->mlx, vars->img.player);
	if (key == 'w')
		vars->img.player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pb.xpm", &vars->img_w, &vars->img_h);
	if (key == 'd')
		vars->img.player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pr.xpm", &vars->img_w, &vars->img_h);
	if (key == 'a' || key == 's')
		vars->img.player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pl.xpm", &vars->img_w, &vars->img_h);
}

static void update_exit(char key, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.pne);
	if (key == 'w')
		vars->img.pne = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pneb.xpm", &vars->img_w, &vars->img_h);
	if (key == 'd')
		vars->img.pne = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pner.xpm", &vars->img_w, &vars->img_h);
	if (key == 'a' || key == 's')
		vars->img.pne = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pnel.xpm", &vars->img_w, &vars->img_h);
}

void hit_W(t_vars *vars)
{
	update_exit('w', vars);
	update_player('w', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.y++;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		if (vars->matrix[vars->player.y][vars->player.x] == 'E')
			vars->matrix[vars->player.y][vars->player.x] = 'F';
		else
			vars->matrix[vars->player.y][vars->player.x] = 'P';
		if (vars->matrix[vars->player.y + 1][vars->player.x] == 'F')
			vars->matrix[vars->player.y + 1][vars->player.x] = 'E';
		else if	(vars->matrix[vars->player.y + 1][vars->player.x] != '1' || \
			vars->matrix[vars->player.y + 1][vars->player.x] != 'E')
			vars->matrix[vars->player.y + 1][vars->player.x] = '0';
		ft_printf("Moves: %i\n", vars->moves);
		vars->moves++;
		draw_map(vars);
	}
}

void hit_S(t_vars *vars)
{
	update_exit('s', vars);
	update_player('s', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.y--;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		if (vars->matrix[vars->player.y][vars->player.x] == 'E')
			vars->matrix[vars->player.y][vars->player.x] = 'F';
		else
			vars->matrix[vars->player.y][vars->player.x] = 'P';
		if (vars->matrix[vars->player.y - 1][vars->player.x] == 'F')
			vars->matrix[vars->player.y - 1][vars->player.x] = 'E';
		else if	(vars->matrix[vars->player.y - 1][vars->player.x] != '1' || \
			vars->matrix[vars->player.y - 1][vars->player.x] != 'E')
			vars->matrix[vars->player.y - 1][vars->player.x] = '0';
		ft_printf("Moves: %i\n", vars->moves);
		vars->moves++;
		draw_map(vars);
	}
}

void hit_D(t_vars *vars)
{
	update_exit('d', vars);
	update_player('d', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.x--;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		if (vars->matrix[vars->player.y][vars->player.x] == 'E')
			vars->matrix[vars->player.y][vars->player.x] = 'F';
		else
			vars->matrix[vars->player.y][vars->player.x] = 'P';
		if (vars->matrix[vars->player.y][vars->player.x - 1] == 'F')
			vars->matrix[vars->player.y][vars->player.x - 1] = 'E';
		else if	(vars->matrix[vars->player.y][vars->player.x - 1] != '1' || \
			vars->matrix[vars->player.y][vars->player.x - 1] != 'E')
			vars->matrix[vars->player.y][vars->player.x - 1] = '0';
		ft_printf("Moves: %i\n", vars->moves);
		vars->moves++;
		draw_map(vars);
	}
}

void hit_A(t_vars *vars)
{
	update_exit('a', vars);
	update_player('a', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.x++;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		if (vars->matrix[vars->player.y][vars->player.x] == 'E')
			vars->matrix[vars->player.y][vars->player.x] = 'F';
		else
			vars->matrix[vars->player.y][vars->player.x] = 'P';
		if (vars->matrix[vars->player.y][vars->player.x + 1] == 'F')
			vars->matrix[vars->player.y][vars->player.x + 1] = 'E';
		else if	(vars->matrix[vars->player.y][vars->player.x + 1] != '1' || \
			vars->matrix[vars->player.y][vars->player.x + 1] != 'E')
			vars->matrix[vars->player.y][vars->player.x + 1] = '0';
		ft_printf("Moves: %i\n", vars->moves);
		vars->moves++;
		draw_map(vars);
	}
}
