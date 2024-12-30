/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:56:00 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/27 15:27:07 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_node *get_cheapest(t_node *a)
{
	while (a->cheap != 1)
		a = a->next;
	return (a);
}

void  get_on_top(t_node **a, t_node **b, int cheap, int index, char name)
{
	if (name == 'a')
	{
		while((*a)->numb != cheap)
		{
			if (index > (*a)->med)
				mov_rot(a, b, "ra");
			else
				mov_rev_rot(a, b, "rra");
		}
	}
	else if (name == 'b')
	{
		while((*b)->numb != cheap)
		{
			if (index > (*b)->med)
				mov_rot(a, b, "rb");
			else
				mov_rev_rot(a, b, "rrb");
		}
	}
}

void move_to_b(t_node **a, t_node **b)
{
	t_node	*cheap;

	cheap = get_cheapest(*a);
	if (cheap->index > (*a)->med && cheap->target->index > (*b)->med && \
	 cheap != *a && cheap->target != *b)
		mov_rot(a, b, "rr");
	else if (cheap != *a && cheap->target != *b)
		mov_rev_rot(a, b, "rrr");
	get_on_top(a, b, cheap->numb, cheap->index, 'a');
	get_on_top(a, b, cheap->target->numb, cheap->target->index, 'b');
	mov_push(a, b, "pb");
}

void  move_to_a(t_node **a, t_node **b)
{
	get_on_top(a, b, (*b)->target->numb, (*b)->target->index, 'a');
	mov_push(a, b, "pa");
}

void set_target_b(t_node *a, t_node *b)
{
	t_node *target;
	long best;

	while(1)
	{
		best = LONG_MAX;
		while(1)
		{
			if(a->numb > b->numb && a->numb < best)
			{
				best = a->numb;
				target = a;
			}
			a = a->next;
			if(a->first == 1)
				break;
		}
		if (best == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
		if (b->first == 1)
			break;
	}
}
