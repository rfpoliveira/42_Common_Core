/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:15:37 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/23 16:44:54 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfiles/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i + 1 < n)
		i++;
	return (s1[i] - s2[i]);
}

/*int     main()
{
        char *buff = "hello";
        char *buff2 = "hellz";
        int n = 5;

        int i = ft_strncmp(buff, buff2, n);
        int y = strncmp(buff, buff2, n);
	printf("mine: %i, og: %i", i , y);
}*/
