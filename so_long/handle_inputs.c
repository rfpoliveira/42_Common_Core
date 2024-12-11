/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:32:40 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/25 14:33:48 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void check_win(t_vars *vars, char key)
{
	if (key == 'w')
		if (vars->endgame == 1 && vars->matrix[vars->player.y - 1][vars->player.x] == 'E')
		{
			ft_printf("YOU WIN! Total moves: %i\nThanks for playing!\n", vars->moves);
			ft_exit(vars);
		}
	if (key == 'a')
		if (vars->endgame == 1 && vars->matrix[vars->player.y][vars->player.x - 1] == 'E')
		{
			ft_printf("YOU WIN! Total moves: %i\nThanks for playing!\n", vars->moves);
			ft_exit(vars);
		}
	if (key == 'd')
		if (vars->endgame == 1 && vars->matrix[vars->player.y][vars->player.x + 1] == 'E')
		{
			ft_printf("YOU WIN! Total moves: %i\nThanks for playing!\n", vars->moves);
			ft_exit(vars);
		}
	if (key == 's')
		if (vars->endgame == 1 && vars->matrix[vars->player.y + 1][vars->player.x] == 'E')
		{
			ft_printf("YOU WIN! Total moves: %i\nThanks for playing!\n", vars->moves);
			ft_exit(vars);
		}
}

static void movement (int keycode, t_vars *vars)
{
	if(keycode == XK_w || keycode == XK_Up)
	{
		check_win(vars, 'w');
		vars->player.y--;
		hit_W(vars);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		check_win(vars, 's');
		vars->player.y++;
		hit_S(vars);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		check_win(vars, 'd');
		vars->player.x++;
		hit_D(vars);
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		check_win(vars, 'a');
		vars->player.x--;
		hit_A(vars);
	}
}

static int keystroke (int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		ft_exit(vars);
	else
		movement(keycode, vars);
	return (0);
}

void handle_input(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, keystroke, vars);
  //mlx_hook(vars->win, 9, 1L << 21, draw_map, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_exit, vars);
}

