/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:02:29 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/22 15:17:55 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	len_src;

	len_src = ft_strlen(src);
	if (src[0] == '\0')
	{
		dst[0] = '\0';
		return (len_src);
	}
	if (dstsize >= len_src + 1)
	{
		ft_memmove(dst, src, len_src);
		dst[len_src + 1] = '\0';
		return (len_src);
	}
	ft_memmove(dst, src, dstsize - 1);
	dst[dstsize - 1] = '\0';
	return (len_src);
}
/*
int	main()
{
	char buff[30];
	char *source = "copyeverythingplease";

	int i = ft_strlcpy (buff, source, 21);

	printf("%s %i\n", buff, i);

	char buff2[30];
        char *source2 = "copyeverythingplease";

        int y = strlcpy(buff2, source2, 21);
	printf("%s %i\n", buff2, y);
}*/
