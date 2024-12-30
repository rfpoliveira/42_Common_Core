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

void  rotate(t_node *a)
{
	t_node *tmp;

	if (!a)
		return ;
	tmp = a;
	a = a->next;
	a->prev = NULL;
	while(a)
		a = a->next;
	a->next = tmp;
	a->next->prev = a;
	a = go_first_node(a);
}

void push(t_node *a, t_node *b)
{
	t_node *tmp;

	if (!b)
		return ;
	tmp = b;
	b = b->next;
	b->prev = NULL;
	tmp->next = a;
	a->prev = tmp;
	a = a->prev;
}

void  swap(t_node *a)
{
	t_node *tmp;

	if (!a)
		return ;
	tmp = a;
	a = a->next;
	tmp->next = a->next;
	tmp->prev = a;
	a->prev = NULL;
	a->next->prev = tmp;
	a->next = tmp;
}

void rev_rotate(t_node *a)
{
	t_node *tmp;

	if (!a)
		return ;
	while(a)
		a = a->next;
	tmp = a;
	a = a->prev;
	a->next = NULL;
	a = go_first_node(a);
	a->prev = tmp;
	tmp->next = a;
	a = a->prev;
	a->prev = NULL;
}
