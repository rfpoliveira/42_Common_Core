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

void  sort3(t_node **a, t_node **b)
{
	t_node *max;

	max = get_max(*a);
	if (max == *a)
		mov_rot(a , b, "ra");
	else if ((*a)->next == max)
		mov_rev_rot(a, b, "rra");
	if ((*a)->numb > (*a)->next->numb)
		mov_swap(a, b, "sa");
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
	int	tmp;

	tmp = (*a)->cost;
	*a = (*a)->next;
	while((*a)->first != 1)
	{
		if ((*a)->cost < tmp)
			tmp = (*a)->index;
		*a = (*a)->next;
	}
	while((*a)->cost != tmp)
		*a = (*a)->next;
	(*a)->cheap = 1;
	*a = go_first_node(*a);
}

t_node	*get_max(t_node *b)
{
	int tmp;

	tmp = b->numb;
	while (1)
	{
		b = b->next;
		if (b->first == 1)
			break;
		if (b->numb > tmp)
			tmp = b->numb;
	}
	while(b->numb != tmp)
		b = b->next;
	return (b);
}

t_node *get_min(t_node *b)
{
	int tmp;

	tmp = b->numb;
	while (1)
	{
		b = b->next;
		if (b->first == 1)
			break;
		if (b->numb < tmp)
			tmp = b->numb;
	}
	while(b->numb != tmp)
		b = b->next;
	return (b);
}
