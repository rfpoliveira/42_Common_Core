/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:34:10 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/31 17:38:24 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);

	if (dstsize < len_dst)
		return (len_src + dstsize);
	i = 0;
	while (src[i] && len_dst < dstsize)
	{
		dst[++len_dst] = src[i++];
	}
	dst[len_dst] = '\0';
	return (len_src + len_dst - i);
}

int main ()
{
	char buff[10] = "0000000000";
	char buff2[9] = "AAAAAAAAA";
	int i = ft_strlcat(buff, buff2, 2);

	printf("%s %i\n", buff, i);

	char buff3[10] = "0000000000";
        char buff4[9] = "AAAAAAAAA";
        int y = strlcat(buff3, buff4, 2);

	printf("%s %i\n", buff3, y); 
}

