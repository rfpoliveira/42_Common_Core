/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:44:41 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/19 12:01:45 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_is_sort(t_node *a)
{
	if (!(a->next))
		return (0);
	a = a->next;
	while(a->next)
	{
		if (a->prev->numb > a->numb)
			return (1);
		a = a->next;
	}
	if (a->prev->numb > a->numb)
		return (1);
	return (0);
}

void atribute_index(t_node **a, t_node **b)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while(*a->next)
	{
		count = 0;
		count += i;
		if (*a->numb > )
	}
}

void  turk(t_node **a, t_node **b)
{
	if (!(ft_is_sort(*a)))
		return ;
	mov_push(*a, *b, "pa");
	mov_push(*a, *b, "pa");
	atribute_index(*a, *b);
		
}


