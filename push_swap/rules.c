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

void  swap(t_node **lst)
{
	if (!*lst || !lst)
		return ;
	*lst = (*lst)->next;
	(*lst)->prev->prev = *lst;
	(*lst)->prev->next = (*lst)->next;
	(*lst)->next->prev = (*lst)->prev;
	(*lst)->next = (*lst)->prev;
	(*lst)->prev = NULL;
}

void push(t_node **a, t_node **b)
{
	if (!*b)
		return ;
	(*b) = (*b)->next;
	(*b)->prev->next = *a;
	(*a)->prev = (*b)->prev;
	*a = (*a)->prev;
	(*b)->prev = NULL;
}

void  rotate(t_node **a)
{
	if (!*a)
		return ;
	(*a) = go_last_node(*a);
	(*a)->next = go_first_node(*a);
	(*a)->next->prev = *a;
	(*a)->prev->next = NULL;
	(*a)->prev = NULL;
}

void rev_rotate(t_node **a)
{
	if (!*a)
		return ;
	(*a)->prev = go_last_node(*a);
	(*a)->prev->next = *a;
	*a = (*a)->next;
	(*a)->prev->next = NULL;
	(*a)->prev = NULL;
}
