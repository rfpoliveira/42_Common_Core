/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:24:17 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/25 14:27:38 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libraries

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

// macros

#define HEIGHT 640
#define WIDTH 320

// custom structs

typedef struct s_img {
	void  *player_up;
	void  *player_down;
	void  *player_right;
	void  *player_left;

}			   t_img;

typedef struct v_counter {
	int	x;
	int	y;
}			   counter;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_img	*img;
	counter	local;
}			   t_vars;

// functions

int		handle_input(int keycode, t_vars *vars);
int		check_map(char *map_matrix);
char	**create_matrix(char *map);
counter	map_dim(char **map);
int		check_path(char **map, int coins);

#endif
