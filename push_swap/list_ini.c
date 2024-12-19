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

t_node *ft_list_ini (char **argv)
{
	int		i;
	t_node *stack;
	t_node *curr;

	i = 0;
	stack = new_node(ft_atoi(argv[i++]));
	while (argv[i])
	{
		curr = new_node(ft_atoi(argv[i]));
		node_add_back(&stack, &curr);
		i++;
	}
	return (stack);
}
