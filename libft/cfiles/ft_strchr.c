/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:30:43 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/22 17:45:12 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0')
		return ((char *)s);
	return (0);
}

/*#include "cfiles/libft.h"

int main ()
{
	char *buff = ft_strchr("hello", '\0');
	printf("ft: %s", buff);

	char *buff2 = strchr("hello", '\0');
	printf("og: %s", buff2);
}*/
