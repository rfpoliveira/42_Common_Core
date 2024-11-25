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

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

// functions

int	handle_input(int keycode, t_vars *vars);

#endif
