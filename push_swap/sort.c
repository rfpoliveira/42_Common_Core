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

static int	  check_high_low(int i, t_node *b)
{
	int	res;
	int	horl;

	horl = 0;
	res = 1;
	if (i > b->numb)
		horl = 1;
	b = b->next;
	if (horl == 0)
		while (b->first != 1)
		{
			if (i > b->numb)
				return (0);
			b = b->next;
		}
	else
		while (b->first != 1)
		{
			if (i < b->numb)
				return (0);
			b = b->next;
		}
	return (1);
}

static void atribute_index(t_node **mod, t_node *a, t_node *b)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	a = a->next;
	while(a->first != 1)
	{
		count = 0;
		count += i;
		if (check_high_low((a->numb), b))
			count++;
		else if (!(check_high_low(a->numb, b)))
			while(a->numb > b->numb)
			{
				count++;
				b = b->next;
			}
		(*mod)->index = count;
		i++;
		a = a->next;
	}
}

static void  sort(t_node **a, t_node **b)
{
	int	i;
	int count;

	i = 0;
	count = node_count(*a);
	while ((*a)->cheap != 1)
	{
		(*a) = (*a)->next;
		i++;
	}
	*a = go_first_node(*a);
	if (i < count / 2)
	{
		while(i > 1)
		{
			mov_rot(a, b, "ra");
			i--;
		}
	}
	else 
	{
		while (i < count)
		{
			mov_rev_rot(a, b, "rra");
			i++;
		}
	}
	if (!(check_high_low((*a)->numb, *b)))
	{
		while ((*a)->numb > (*b)->numb)
			mov_rot(b, a, "rb");
	}
	mov_push(b, a, "pb");
}

static void push_back(t_node **a, t_node **b)
{
	while ((*b)->next != (*b))
		mov_push(a, b, "pa");
	mov_push(a, b, "pa");
}

void  algoritm(t_node **a, t_node **b)
{
	int	count;

	if (!(ft_is_sort(*a)))
		return ;
	count = node_count(*a);
	if (count < 3)
		sort3(a, *b);
	mov_push(b, a, "pb");
	mov_push(b, a, "pb");
	while (1)
	{
		(*a) = go_first_node(*a);
		atribute_index(a, *a, *b);
		count = node_count(*a);
		if (count == 3)
			break ;
		sort(a, b);
	}
	sort3(a, *b);
	push_back(a, b);
}
