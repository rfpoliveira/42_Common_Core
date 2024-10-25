/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:39:55 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/24 12:15:51 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "cfiles/libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*sub;
	unsigned int	stringlen;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	stringlen = ft_strlen(s);
	if (start > stringlen)
		return (malloc(0));
	sub = malloc (stringlen + 1);
	while (s[start] && (i < len))
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return ((char *)sub);
}
/*
int	main()
{
	char *buff = "";
	int i = 5;
	int y = 5;
	char	*dup = ft_substr(buff, i , y);
	printf("%s", dup);
}*/
