/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:48:33 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/22 18:12:59 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s++))
		i++;
	while (i >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
		i--;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}
/*
#include "cfiles/libft.h"

int main ()
{
       char *buff = ft_strrchr("hello", 0);
        printf("ft: %s", buff);

        char *buff2 = strrchr("helllo", 0);
        printf("og: %s", buff2);
}*/
