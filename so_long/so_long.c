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

/*static int	render(t_vars vars, int *local)
{
	int img_width;
	int	img_height;

	img_width = 1;
	img_height = 1;
	vars.img = mlx_xpm_file_to_image(vars.mlx, "./assets/1.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, local.y, local.x);
	return (0);
}
*/
static int  create_window()
{
	t_vars	vars;

	vars.local.y = 100;
	vars.local.x = 100;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "so_long");
	if (!vars.win)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}
//	mlx_loop_hook(vars.mlx, render, &vars);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.player_up, local.y, local.x);
	mlx_hook(vars.win, 2, 1L<<0, handle_input, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int check_file(char *map)
{
	int	fd;
	int	i;
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] != 'r' || map[len - 2] != 'e' || map[len - 3] != 'b' \
		|| map[len - 4] != '.')
		return (-1);
	fd = open(map, O_RDONLY);
	i = read(fd, 0, 0);
	if (fd != -1)
		close(fd);
	return (i);	
}

int	main(int argc, char **argv)
{
	if (argc != 2 || check_file(argv[1]) == -1)
	{
		ft_printf("Error\nInvalid arguments or file\n");
		return (0);
	}
	if (check_map(argv[1]) != -1)
		create_window();
	else
		ft_printf("Error\nInvalid Map\n");
	return (0);	
}
