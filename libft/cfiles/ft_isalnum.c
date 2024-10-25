/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:27:46 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/10/22 09:25:46 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int     ft_isalpha(int c)
{
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
                return (1);
        return (0);
}

int     ft_isdigit(int c)
{
        if (c >= 48 && c <= 57)
                return (1);
        return (0);
}*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*int main ()
{
	printf("%i", ft_isalnum('6'));
}*/
