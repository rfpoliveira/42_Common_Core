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
#include "so_long.h"

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "Hello world!");
	if (!vars.win)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}
	mlx_hook(vars.win, 2, 1L<<0, handle_input, &vars);
	//mlx_hook(vars.win , 6, 1L<<4, printfhello, &vars);
	mlx_loop(vars.mlx);
}