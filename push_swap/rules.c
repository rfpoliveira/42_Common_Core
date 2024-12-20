/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:02:44 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/18 12:17:49 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void  rotate(t_node **lst)
{
	if (!*lst || !lst)
		return ;
	(*lst)->first = 0;
	(*lst)->next->first = 1;
	(*lst) = go_first_node(*lst);
}

void push(t_node **a, t_node **b)
{
	t_node  *tmp;
	void *tmp2;

	if (!*b)
		return ;
	tmp = new_node((*b)->numb);
	tmp2 = (*b)->next;
	free(*b);
	(*b)->next->prev = (*b)->prev;
	(*b)->prev->next = (*b)->next;
	*b = tmp2;
	(*b)->first = 1;
	node_add_back(a, &tmp);
	(*a)->first = 0;
	*a = (*a)->prev;
	(*a)->first = 1;
}

void  swap(t_node **a)
{
	int	tmp;

	tmp = (*a)->numb;
	(*a)->numb = (*a)->next->numb;
	(*a)->next->numb = tmp;
}

void rev_rotate(t_node **a)
{
	if (!*a)
		return ;
	(*a)->first = 0;
	(*a)->prev->first = 1;
	(*a) = (*a)->prev;
}
