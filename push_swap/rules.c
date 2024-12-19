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
	if (!*b)
		return ;
	(*b) = (*b)->next;
	(*b)->first = 1;
	(*b)->prev->next = *a;
	(*a)->prev = (*b)->prev;
	(*a)->first = 0; 
	*a = (*a)->prev;
	(*a)->first = 1;
	//(*b)->prev = go_last_node(*b);
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
	//(*a)->prev = go_last_node(*a);
	(*a)->prev->next = *a;
	(*a)->first = 0;
	*a = (*a)->prev;
	(*a)->first = 1;
}
