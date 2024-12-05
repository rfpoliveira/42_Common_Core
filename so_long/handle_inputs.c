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

int handle_input(int keycode, t_vars *vars)
{
	int	img_width;
	int	img_height;

	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx); 
		free(vars->mlx);
		exit(0);
	}
	if (keycode == XK_space)
		ft_printf("hello");
	if (keycode == XK_d)
	{
	//vars->local.x += 32;
	vars->img->player_up = mlx_xpm_file_to_image(vars->mlx, "./assets/1.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->player_up, vars->local.y, vars->local.x);
	}
	return (0);
}

