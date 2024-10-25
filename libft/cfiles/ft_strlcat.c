/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:34:10 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/22 16:24:48 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "cfiles/libft.h"

int     ft_strlen(const char *str)
{
        int     i;

        i = 0;
	while (str[i])
                i++;
        return (i);
}
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	len_dst;
	int	len_src;
	int	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_src)
		return (len_src + dstsize);
	i = 0;
	while (src[i] && len_dst + 1 < dstsize)
		dst[len_dst++] = src[i++];
	dst[i + len_dst] = '\0';
	return (len_src + len_dst - i);
}
/*
int main ()
{
	char buff[20] = "Hello, ";
	char buff2[7] = "World!";
	int i = ft_strlcat(buff, buff2, 5);

	printf("%s %i ", buff, i);

	char buff3[20] = "Hello, ";
        char buff4[7] = "World!";
        int y = strlcat(buff3, buff4, 5);

	printf("%s %i", buff3, y); 
}*/
