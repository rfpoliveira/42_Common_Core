/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:46:27 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/22 09:46:30 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif 

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd);
char	*r_strdup(char *s1);
char	*r_strchr(char *s, int c);
char	*r_substr(char *s, unsigned int start, size_t len);
char	*r_strjoin(char *s1, char *s2);
int		r_strlen(char *str);

#endif
