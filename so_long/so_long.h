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
#include "libft/libft.h"

// macros

// custom structs

typedef struct s_img {
	void  *player;
	void  *token;
	void  *bg;
	void  *wall;
	void  *exit_c;
	void  *exit_o;
	int	  img_h;
	int	  img_w;
}			   t_img;

typedef struct v_counter {
	int	x;
	int	y;
}			   counter;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_img	*img;
	char	**matrix;
	counter	dim;
	counter	player;
	int		coins;
	int		moves;
}			   t_vars;

// functions

void	  handle_input(t_vars *vars);
int		check_map(char *map_matrix, t_vars *vars);
char	**create_matrix(char *map);
counter	map_dim(char **map);
int		check_path(char **map, int coins);
int		draw_map(t_vars *vars);
void	game_init(t_vars *vars, char *path);
int		ft_exit(t_vars *vars);
void	hit_W(t_vars *vars);
void	hit_S(t_vars *vars);
void	hit_A(t_vars *vars);
void	hit_D(t_vars *vars);
void	handle_input(t_vars *vars);

#endif
