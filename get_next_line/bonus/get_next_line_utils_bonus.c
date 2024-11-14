/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:02:27 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/12 11:02:29 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	r_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*r_strdup(char *s1)
{
	unsigned int	len;
	char			*dup;
	unsigned int	i;

	i = 0;
	len = r_strlen(s1);
	dup = malloc (len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*r_strchr(char *s, int c)
{
	int		i;
	char	tempc;

	tempc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == tempc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == tempc)
		return ((char *)&s[i]);
	return (0);
}

char	*r_substr(char *s, unsigned int start, size_t len)
{
	unsigned char	*sub;
	unsigned int	stringlen;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	stringlen = r_strlen(s);
	if (start > stringlen)
		return (NULL);
	if (stringlen - start < len)
		sub = malloc (stringlen - start + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start] && (i < len))
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return ((char *)sub);
}

char	*r_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	y;
	unsigned char	*joint;

	i = 0;
	y = 0;
	joint = malloc(r_strlen(s1) + r_strlen(s2) + 1);
	if (joint == NULL)
		return ((char *)joint);
	while (s1[i])
	{
		joint[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		joint[i++] = s2[y];
		y++;
	}
	joint[i] = '\0';
	return ((char *)joint);
}
