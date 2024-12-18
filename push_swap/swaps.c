/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:30:47 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/18 17:32:23 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void  mov_swap(t_node **a, t_node **b, char *c)
{
	if (c[1] == 'a' || c[1] == 's')
		swap(a);
	if (c[1] == 'b' || c[1] == 's')
		swap(b);
	ft_printf("%s\n", c);
}

void  mov_push(t_node **a, t_node **b, char *c)
{
	if (c[1] == 'a')
		push(a, b);
	else if (c[1] == 'b')
		push(b, a);
	ft_printf("%s\n", c);
}

void  mov_rot(t_node **a, t_node **b, char *c)
{
	if (c[1] == 'a' || c[1] == 'r')
		rotate(a);
	else if (c[1] == 'b' || c[1] == 'r')
		rotate(b);
	ft_printf("%s\n", c);
}

void  mov_rev_rot(t_node **a, t_node **b, char *c)
{
	if (c[2] == 'a' || c[2] == 'r')
		rev_rotate(a);
	else if (c[2] == 'b' || c[2] == 'r')
		rev_rotate(b);
	ft_printf("%s\n", c);
}
