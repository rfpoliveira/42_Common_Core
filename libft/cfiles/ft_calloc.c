/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:46:44 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/24 11:59:48 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfiles/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(count * size);
	if (temp == NULL)
		return (temp);
	while (count-- > 0)
		temp[i++] = 0;
	return (temp);
}
/*
int	main ()
{
	char *temp = ft_calloc(5, 1);
	printf("%s", temp);
}*/
