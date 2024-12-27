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
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	argv = parsing(argc, argv);
	if (!argv)
		return (ft_printf("Error\n"));
	stack_a = ft_list_ini(argv);
	if (argc == 2)	
		matrix_free(argv);
	stack_b = ft_list_ini(NULL);
	algoritm(&stack_a, &stack_b);
	//print list:
	stack_a = go_first_node(stack_a);
	while(1)
	{
		ft_printf("%i\n", stack_a->numb);
		stack_a = stack_a->next;
		if (stack_a->first == 1)
			break;
	}
	ft_printf("prev:\n");
	
	stack_a = stack_a->prev;
	while(1)
	{
		ft_printf("%i\n", stack_a->numb);
		stack_a = stack_a->prev;
		if (stack_a->first == 1)
			break ;
	}
	ft_printf("%i\nb:\n", stack_a->numb);

	while(1)
	{
		ft_printf("%p\n", *stack_b);
		stack_b = stack_b->next;
		ft_printf("%p\n", *stack_b);
		if (stack_b->first == 1)
			break ;
	}

	free_lst(&stack_a);
	free_lst(&stack_b);
}
