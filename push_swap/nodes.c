/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:23:44 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/18 11:41:32 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node *go_first_node(t_node *lst)
{
	t_node *tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while(tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

t_node	*go_last_node(t_node *lst)
{
	t_node *tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);	
}

void	node_add_back(t_node **lst, t_node *new)
{
	t_node *tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = go_last_node(*lst);
	tmp->next = new;
	new->prev = tmp;
}

t_node	*new_node(int content, int index)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->numb = content;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
