/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:53:20 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/23 10:06:32 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfiles/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temps;
	unsigned char	tempc;
	unsigned int	i;

	temps = (unsigned char *)s;
	tempc = (unsigned char)c;
	i = 0;
	if (tempc == '\0')
		return (0);
	if (*temps == tempc)
		return (temps);
	while (i < n && *temps++ != tempc)
		i++;
	if (*temps == tempc)
		return (temps);
	return (0);
}
/*
int	main ()
{
	char *buff = ft_memchr("hello", '0', 10);
	char *buff2 = memchr("hello", '0', 10);
	printf("mine: %s, og: %s.", buff, buff2);
}*/
