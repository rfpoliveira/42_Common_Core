/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:46:16 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/17 15:13:29 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void  init_nodes_a(t_node **a, t_node **b)
{
	atribute_index(a);
	atribute_index(b);
	set_target_a(a, b);
	get_cost(a, b);
	is_cheap(a);
}

void init_nodes_b(t_node **a, t_node **b)
{
	atribute_index(a);
	atribute_index(b);
	set_target_b(a, b);
}


t_node *ft_list_ini (char **argv)
{
	int		i;
	t_node *stack;
	t_node *curr;

	i = 0;
	if (!argv)
		stack = new_node(0);
	else
		stack = new_node(ft_atoi(argv[i++]));
	if (argv)
	{
		while (argv[i])
		{
			curr = new_node(ft_atoi(argv[i]));
			node_add_back(&stack, &curr);
			i++;
		}
	}
	return (stack);
}
