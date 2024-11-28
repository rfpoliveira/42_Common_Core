/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:46:40 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/28 11:52:33 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_height(char *map)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(map, O_RDONLY);
	tmp = get_next_line(fd);
	i = 1;
	while(tmp)
	{
		tmp = get_next_line(fd);
		i++;
	}
	r_free(&tmp);
	close(fd);
	return (i);
}

char	**save_map(char *map)
{
	char	**save;
	int		fd;
	int		i;

	map = ft_strjoin("maps/", map);
	i = get_height(map);
	save = malloc(i + 1);
	i = 1;
	fd = open(map, O_RDONLY);
	save[0] = get_next_line(fd);
	while (save[i - 1])
		save[i++] = get_next_line(fd);
	close(fd);
	return (save);
}

int main (int argc, char **argv)
{
	argc = 0;
	char	**save = save_map(argv[1]);
	int i = 0;
	while (save[i])
	{
		ft_printf("%s", save[i]);
		i++;
	}
}
