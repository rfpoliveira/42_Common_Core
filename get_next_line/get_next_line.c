/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:45 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/12 11:02:14 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	r_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*fill_buff(int fd, char *buff, char *rest)
{
	char	*tmp;
	ssize_t	i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		else if (i == 0)
			break ;
		if (!rest)
			rest = r_strdup("");
		tmp = rest;
		rest = r_strjoin(tmp, buff);
		r_free(&tmp);
		if (r_strchr(buff, '\n'))
			break ;
	}
	return (rest);
}

static char	*true_line(char	*line)
{
	static char		*rest;
	size_t			i;

	i = 1;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	rest = r_substr(&line[i + 1], 0, r_strlen(line) - i);
	if (!rest)
		return (NULL);
	line[i + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*buff;
	char			*line;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		r_free(&buff);
		r_free(&rest);
		return (NULL);
	}
	line = fill_buff(fd, buff, rest);
	r_free(&buff);
	if (!line)
		return (NULL);
	rest = true_line(line);
	if (!*line)
	{
		free(line);
		r_free(&rest);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int i = 0;
	char *s = "h";
	int fd = open ("bee.txt", O_RDONLY);
	while (s)
	{
		s = get_next_line(fd);
		printf("%s", s);
		i++;
		free(s);
	}
	close(fd);
}
