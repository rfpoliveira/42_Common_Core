/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:05:11 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/17 10:13:39 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main (int argc, char **argv)
{
	int par;
	int n;
	t_list *stack_a;

	par = 0;
	n = 0;
	stack_a = NULL;
	if (argc < 2)
		par = -1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (argv[n])
			n++;
	}	
	par = parsing(argv, argc);
	if (par == -1)
		return (ft_printf("Error\n"));
	stack_a = ft_list_ini(argv, n);
	if (argc == 2)	
		matrix_free(argv);
	

	while(stack_a->next != NULL)
	{
		ft_printf("%s\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("%s\n", stack_a->content);
	
}
