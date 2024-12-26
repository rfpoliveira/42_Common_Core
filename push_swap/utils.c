/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:12:51 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/20 12:16:49 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int node_count(t_node *a)
{
	int	i;
	
	i = 1;
	if (a == a->next)
		return (1);
	a = a->next;
	while(a->first != 1)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void  sort3(t_node **a, t_node *b)
{
	*a = go_first_node(*a);
	while((*a)->next->first != 1)
	{
		if ((*a)->numb > (*a)->next->numb)
			mov_swap(a, &b, "sa");
		*a = (*a)->next;
	}
	*a = go_first_node(*a);
	if (ft_is_sort(*a))
		sort3(a, b);
}

int	ft_is_sort(t_node *a)
{
	if (!(a->next))
		return (0);
	a = go_first_node(a);
	a = a->next;
	while(1)
	{
		if (a->prev->numb > a->numb)
			return (1);
		a = a->next;
		if (a->first == 1)
			break;
	}
	return (0);
}

void  is_cheap(t_node **a)
{
	(*a)->cheap = 1;
	*a = (*a)->next;
	while((*a)->first != 1)
	{
		if ((*a)->index < (*a)->prev->index)
		{
			(*a)->prev->cheap = 0;
			(*a)->cheap = 1;
		}
		*a = (*a)->next;
	}
}
