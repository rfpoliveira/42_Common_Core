/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:02:11 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/25 15:03:39 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfiles/libft.h"

/*int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dup = malloc (len + 1);
	if (dup == NULL)
		return (dup);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*result;

	result = ft_strdup(s);
	i = 0;
	while (result[i])
	{
		result[i] = (*f)(i, result[i]);
		i++;
	}
	return (result);
}
/*
char	r_tolower(unsigned int i, char c)
{
	i = 0;
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	main (void)
{
	int i = 0;
	char *buff = "HELLO";
	char *buff2 = ft_strmapi(buff,r_tolower);
	printf("%s", buff2);
}*/
