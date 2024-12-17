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

t_list *ft_list_ini (char **argv, int n)
{
	int	i;
	t_list *stack;
	t_list *curr;

	i = 1;
	if (n == 2)
		i = 0;
	stack = ft_lstnew(argv[i++]);
	while (argv[i])
	{
		curr = ft_lstnew((argv[i]));
		ft_lstadd_back(&stack, curr);
		i++;
	}
	return (stack);
}
