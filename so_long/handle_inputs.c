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

static void movement (int keycode, t_vars *vars)
{
	if(keycode == XK_w || keycode == XK_Up)
	{
		vars->player.y--;
		hit_W(vars);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		vars->player.y++;
		hit_S(vars);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		vars->player.x++;
		hit_D(vars);
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		vars->player.x--;
		hit_A(vars);
	}
}

static int keystroke (int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		ft_exit(vars);
	else
	{
		movement(keycode, vars);
		ft_printf("Moves: %i\n", vars->moves);
	}
		
	return (0);
}

void handle_input(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, keystroke, vars);
	mlx_hook(vars->win, 9, 1L << 21, draw_map, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_exit, vars);
}

