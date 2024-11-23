/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:52:48 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/20 11:55:14 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minilibx-linux/mlx.h"
#include "/usr/include/X11/keysymdef.h"
#include <unistd.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	r_close(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

/*int print(int keycode)*/
/*{*/
/*	if (keycode == )*/
/*		write(1, "hello", 6);*/
/*	return (0);*/
/*}*/

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 320, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, r_close, &vars);
	mlx_loop(vars.mlx);
}
