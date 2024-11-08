/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_putnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:33:10 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/07 16:42:14 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	r_putnbr(int n)
{
	char	*s;
	int		r;

	s = ft_itoa(n);
	r = r_putstr(s);
	free(s);
	return (r);
}
