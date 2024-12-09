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

static int keystroke (int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		ft_exit(vars);
	return (0);
}

void handle_input(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, keystroke, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_exit, vars);
}

