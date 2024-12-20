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
	if (!lst)
		return (NULL);
	while((lst->first) == 0)
		lst = lst->prev;
	return (lst);
}

void	node_add_back(t_node **lst, t_node **new)
{
	if (!*lst)
	{
		*lst = *new;
		return ;
	}
	(*new)->first = 0;
	*lst = (*lst)->prev;
	(*new)->prev = *lst;
	(*new)->next = (*lst)->next;
	(*lst)->next = *new;
	*lst = go_first_node(*lst);
	(*lst)->prev = *new;
}

t_node	*new_node(int content)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->first = 1;
	new->index = 0;
	new->cheap = 0;
	new->numb = content;
	new->next = new;
	new->prev = new;
	return (new);
}
