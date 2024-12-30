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

void set_target_a(t_node *a, t_node *b)
{
	t_node *target;
	long best;

	while(1)
	{
		best = LONG_MIN;
		while(1)
		{
			if(b->numb < a->numb && b->numb > best)
			{
				best = b->numb;
				target = b;
			}
			b = b->next;
			if(b->first == 1)
				break;
		}
		if (best == LONG_MIN)
			a->target = get_max(b);
		else
			a->target = target;
		a = a->next;
		if (a->first == 1)
		break;
	}
}

void  get_cost(t_node *a, t_node *b)
{
	int len_a;
	int	len_b;

	calc_med(a, b);
	len_a = a->med;
	len_b = b->med;
	while(1)
	{
		a->cost = a->index;
		if (a->index < a->med)
			a->cost = len_a - (a->index);
		if (a->target->index > b->med)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
		if (a->first == 1)
			break;
	}
}

static void  endgame(t_node **a, t_node **b)
{
	int	tmp;

	tmp = get_min(*a)->numb;
	while((*a)->numb != tmp)
	{
		tmp = get_min(*a)->numb;
		(*a)->med = node_count(*a) / 2;
		if (tmp > (*a)->med)
			mov_rot(a, b, "ra");
		else
			mov_rev_rot(a, b, "rra");
	}
}

void  algoritm(t_node **a, t_node **b)
{
	int	count;

	if (!(ft_is_sort(*a)))
		return ;
	count = node_count(*a);
	if (count <= 3)
	{
		sort3(a, b);
		return ;
	}
	mov_push(a, b, "pb");
	if(node_count(*a) > 3 && ft_is_sort(*a))
		mov_push(a, b, "pb");
	while (node_count(*a) > 3 && ft_is_sort(*a))
	{
		init_nodes_a(*a, *b);
		move_to_b(a, b);
	}
	sort3(a, b);
	while((*b)->next != *b)
	{
		init_nodes_b(*a, *b);
		move_to_a(a, b);
	}
	atribute_index(*a);
	endgame(a, b);
}
