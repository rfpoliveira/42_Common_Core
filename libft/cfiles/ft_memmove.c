/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:16:15 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/22 13:03:17 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)

{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	unsigned int	i;

	temp_dst = dst;
	temp_src = (unsigned char *)src;
	if (temp_dst == 0 && temp_src == 0)
		return (dst);
	while (len > 0)
	{
		temp_dst[len - 1] = temp_src[len - 1];
		len --;
	}
	return (dst);
}
/*
#include <string.h>

int     main()
{
        char buff[6] = "Hello7";
        char copia[6] = "copia.";
	printf("%s \n", buff);

        ft_memmove(buff, copia, 4);
        printf("%s \n", buff);

	 char buff2[6] = "Hello7";
        char copia2[6] = "copia.";

        memmove(buff2, copia2, 4);
        printf("%s\n", buff2);

}*/
